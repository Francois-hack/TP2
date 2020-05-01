//
// Created by Francois Chevalier on 01/05/2020.
//

#ifndef TP2_SOMMET_H
#define TP2_SOMMET_H
#include <iostream>
#include <vector>

class Sommet {
private:
    int m_numero;
    std::vector<const Sommet*> m_successeurs;
public:
    Sommet(int num);
    int getNumero() const;
    void addSuccesseur(const Sommet* succ);
    const std::vector<const Sommet*>& getSuccesseurs() const;
    void afficher() const;
};


#endif //TP2_SOMMET_H
