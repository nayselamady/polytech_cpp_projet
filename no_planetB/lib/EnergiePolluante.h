#ifndef ENERGIEPOLLUANTE_H
#define ENERGIEPOLLUANTE_H


#include "Personnage.h"
#include <string>
#include <vector>

/* Classe mère EnergiePolluante dérivant de la classe Personnage */

class EnergiePolluante: public Personnage{
public:
    EnergiePolluante(int pA,std::string nom);
    virtual int degats(){return 0;}
    int getpA()const{return _pA;}
    bool operator < (const EnergiePolluante &p) const;
    void afficher(std::ostream &info)const;

private:
    int _pA;
};
std::ostream &operator << (std::ostream &info, const EnergiePolluante& s);

#endif
