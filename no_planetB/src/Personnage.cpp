#include "../lib/Personnage.h"

Personnage::Personnage(std::string nom,int type){
    this->_nom = nom;
    _type = type;
}

Personnage::Personnage(const Personnage &p){
    this->_nom = p._nom;
    _type = p._type;
}

