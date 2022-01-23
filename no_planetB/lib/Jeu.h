#ifndef JEU_H
#define JEU_H

#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include "Joueur.h"
#include "EnergiePolluante.h"
#include <vector>
#include "EnergieRenouvelable.h"
#include "Petrole.h"
#include "Nucleaire.h"
#include "Eolienne.h"
#include "Solaire.h"
#include "Affichage.h"
#include <string>

// valeurs globale du jeu
#define VIE_JOUEUR 100
#define LENGHT_SCREEN 800
#define WIDTH_SCREEN 600

class Jeu: public QGraphicsView{
    Q_OBJECT
public:
    Jeu();
    QGraphicsScene * scene;
    Joueur * player;
    Affichage* affichage;
    void menu();
    void AffichageGameOver(QString message);

public slots:
    void creer_mechant();
    void creer_gentil();
    void maj_Map();
    void play();
    void afficherInfo();
    void gameOver();
    void gagner();
    void rejouer();


private:
    std::vector<EnergiePolluante>_tabPollu;
    std::vector<EnergieRenouvelable>_tabRenouv;
    std::map<EnergiePolluante,int>_mapPollu;

};
#endif
