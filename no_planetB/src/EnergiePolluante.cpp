#include "../lib/EnergiePolluante.h"

/* constructeur de la classe mère EnergiePolluante */
EnergiePolluante::EnergiePolluante(int pA, std::string nom):Personnage(nom,2),_pA(pA){}

/* Surcharge de l'opérateur "<" pour les énergies polluantes ; cette fonction sert au remplissage de la map*/
bool EnergiePolluante::operator <(const EnergiePolluante &p) const
{
    if( this->_pA<p._pA){
        return true;
    }
    return false;
}

/*Fonction utilisée dans la surcharge, pour afficher les informations des Energies */
void EnergiePolluante::afficher(std::ostream &info)const
{
    info<< "EnergiePolluante: Nom "<< this->getNom()<<"\n Points d'attaque: "<<this->_pA<<"\n";
}

/* Surcharge de l'opérateur "<<" pour l'affichage des informations des personnages dans les TestCase*/
std::ostream&operator <<(std::ostream &info,EnergiePolluante const& s)
{
        s.afficher(info);
        return info;
}
