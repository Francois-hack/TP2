#include "Graphe.h"
#include <fstream>
#include <queue>

Graphe::Graphe(std::string cheminFichierGraphe) {
    std::ifstream ifs{cheminFichierGraphe};
    if(!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    ifs >> m_estOriente;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'orientation du graphe.");
    }
    int ordre;
    ifs >> ordre;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'ordre du graphe.");
    }
    int taille;
    ifs >> taille;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de la taille du graphe.");
    }
    for(int i=0; i<ordre; ++i) {
        m_sommets.push_back(new Sommet(i));
    }
    int num1, num2;
    for(int i=0; i<taille; ++i) {
        ifs >> num1 >> num2;
        if(ifs.fail()) {
            throw std::runtime_error("Problème de lecture d'un.e arc/arête.");
        }
        m_sommets[num1]->addSuccesseur(m_sommets[num2]);
        if(!m_estOriente && num1 < num2) {
            m_sommets[num2]->addSuccesseur(m_sommets[num1]);
        }
    }
}

Graphe::~Graphe() {
    for(auto addrSommet : m_sommets) {
        delete addrSommet;
    }
}

void Graphe::afficher() const {
    std::cout << std::endl << "Graphe ";
    std::cout << (m_estOriente ? "orienté" : "non orienté") << std::endl;
    std::cout << "Ordre : " << m_sommets.size() << std::endl;
    std::cout << "Liste d'adjacences : " << std::endl;
    for(auto addrSommet : m_sommets) {
        addrSommet->afficher();
        std::cout << std::endl;
    }

}


std::vector<int> Graphe::BFS(int numero_s0) const {

    std::vector<int> couleurs((int) m_sommets.size(), 0);
    std::queue<const Sommet*> file;
    std::vector<int> predecesseurs((int) m_sommets.size(), -1);
    file.push(m_sommets[numero_s0]);
    couleurs[numero_s0] = 1;
    const Sommet* s;

    while(!file.empty()) {
        s = file.front();
        file.pop();
        for(auto succ : s->getSuccesseurs()) {
            if(couleurs[succ->getNumero()] == 0) {
                file.push(succ);
                couleurs[succ->getNumero()] = 1;
                predecesseurs[succ->getNumero()] = s->getNumero();
            }
        }
        couleurs[s->getNumero()] = 2;
    }
    return predecesseurs;
}


std::vector<int> Graphe::DFS(int numero_s0) const {

    std::vector<int> couleurs((int) m_sommets.size(), 0);

    std::stack<const Sommet*> file;
    std::vector<int> predecesseurs((int) m_sommets.size(), -1);
    file.push(m_sommets[numero_s0]);
    couleurs[numero_s0] = 1;
    const Sommet* s;
    while(!file.empty()) {
        s = file.top();
        file.pop();
        for(auto succ : s->getSuccesseurs()) {
            if(couleurs[succ->getNumero()] == 0) {
                file.push(succ);
                couleurs[succ->getNumero()] = 1;
                predecesseurs[succ->getNumero()] = s->getNumero();
            }
        }
        couleurs[s->getNumero()] = 2;
    }
    return predecesseurs;
}


void Graphe::ComposantConnexe() {

    std::vector<int> couleurs((int) m_sommets.size(), 0);
    std::cout << "les composants connexes sont :" << std::endl;
    for (auto s : m_sommets)
        if (couleurs[s->getNumero()] != 1) {

            std::cout<<" {";
            std::vector<int> arborescence = BFS(s->getNumero());
            for (size_t i = 0; i < arborescence.size(); i++) {
                if (i != s->getNumero()) {

                    if (arborescence[i] != -1) {

                        std::cout << i << " ";
                        couleurs[i] = 1;
                    }
                }
            }

            couleurs[s->getNumero()] = 1;
            std::cout << s->getNumero();
            std::cout<< "}"<< std::endl;

        }
}