//
// Created by Francois Chevalier on 01/05/2020.
//

#ifndef TP2_GRAPHE_H
#define TP2_GRAPHE_H
#include <iostream>
#include <vector>
#include <string>
#include "Sommet.h"

class Graphe {
private:
    bool m_estOriente;
    std::vector<Sommet*> m_sommets;
public:
    Graphe(std::string cheminFichierGraphe);
    ~Graphe();
    void afficher() const;
    std::vector<int> BFS(int numero_s0) const;
    std::vector<int> DFS(int numero_s0) const;
    void ComposantConnexe();

};

#endif //TP2_GRAPHE_H
