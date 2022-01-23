#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <string>
#include <vector>

/*Personnage est la classe mère de tout les types de personnages
Personnage est une classe abstraite*/

class Personnage
{
public:
    Personnage(std::string nom,int type);
    Personnage (const Personnage &p);
    int getType() const{return _type;}
    void setType(int t){ _type = t;}
    void setNom(std::string n){ _nom = n;}
    std::string getNom() const{return _nom;}
    std::vector<Personnage> tabPerso();
    virtual void afficher() const{;}

protected:
    int _type; // 0: joueur, 1: victime, 2: Miam miam
    std::string _nom;

};
#endif
