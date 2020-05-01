#include <iostream>
#include "Graphe.h"

void afficherParcours(size_t s0, const std::vector<int>& precesseur) {
    for(size_t i = 0; i < precesseur.size(); ++i) {
        if (i != s0) {
            if(precesseur[i] != -1) {
                std::cout << i << " <--- ";
                size_t j = precesseur[i];
                while(j != s0) {
                    std::cout << j << " <--- ";
                    j = precesseur[j];
                }
                std::cout << j << std::endl;
            }
        }
    }
}

int main() {

    size_t s0 = 0;
    Graphe g("../Graphe.txt");
    std::vector<int> arborescence;
    int choix;

    do {
        std::cout << "1 : Afficher la liste d'adjacence des sommets"<< std::endl;
        std::cout << "2 : Afficher le plus courts chemins BFS"<< std::endl;
        std::cout << "3 : Afficher le plus courts chemins DFS"<< std::endl;
        std::cout << "4 : Afficher les composantes connexes"<< std::endl;
        std::cout << "5 : Quitter" << std::endl;
        std::cin >> choix;

        switch (choix)
        {
            case 1 :
                g.afficher();
                break;

            case 2 :

                std::cout << std::endl << "BFS : Veuillez saisir le numéro du sommet initial pour la recherche du plus court chemin : ";
                std::cin >> s0;
                arborescence = g.BFS(s0);
                std::cout << "Plus courts chemins depuis le sommet " << s0 << " (BFS) : " << std::endl;
                afficherParcours(s0, arborescence);
                break;

            case 3 :

                std::cout << std::endl << "DFS : Veuillez saisir le numéro du sommet initial pour la recherche du plus court chemin : ";
                std::cin >> s0;
                arborescence = g.DFS(s0);
                std::cout << "Plus courts chemins depuis le sommet " << s0 << " (BFS) : " << std::endl;
                afficherParcours(s0, arborescence);
                break;

            case 4 :
                g.ComposantConnexe();
                break;
        }
    }while(choix != 5 );
    return 0;
}

