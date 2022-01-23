#ifndef ENERGIERENOUVELABLE_H
#define ENERGIERENOUVELABLE_H

#include "Personnage.h"
#include <QDebug>

/* Classe mère EnergiePolluante dérivant de la classe Personnage */
class EnergieRenouvelable: public Personnage{

public:
    EnergieRenouvelable(int pS,std::string nom);
    virtual int soins(){return 0;}
    int getpS() const{return _pS;}
    void afficher(std::ostream &info) const;

private:
    int _pS;
};
std::ostream &operator << (std::ostream &info,EnergieRenouvelable const& v);
#endif
