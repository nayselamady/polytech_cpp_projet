#include "../lib/EnergieRenouvelable.h"

/* constructeur de la classe mère EnergieRenouvelable*/
EnergieRenouvelable::EnergieRenouvelable(int pS,std::string nom): Personnage(nom,1),_pS(pS){}

/* Surcharge de l'opérateur "<<" pour l'affichage des informations des personnages dans les TestCase*/
std::ostream &operator << (std::ostream &info,const EnergieRenouvelable& v)
{
    v.afficher(info);
    return info;
}

/*Fonction utilisée dans la surcharge, pour afficher les informations des Energies */
void EnergieRenouvelable::afficher(std::ostream &info)const
{
     info<<"EnergieRenouvelable: Nom  "<< this->getNom()<<"\nPoints de soin: "<<this->_pS<<"\n";
}
