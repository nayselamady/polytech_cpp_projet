#include "../lib/Jeu.h"
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include <QImage>
#include <QDebug>
#include <QTimer>
#include "../lib/EnergiePolluante.h"
#include "../lib/EnergieRenouvelable.h"
#include "../lib/Eolienne.h"
#include "../lib/Affichage.h"
#include "../lib/Bouton.h"
#include "../lib/Joueur.h"


/* Classe Jeu permettant de configurer l'affichage de la fenêtre graphique*/
Jeu::Jeu(){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(LENGHT_SCREEN,WIDTH_SCREEN);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,LENGHT_SCREEN,WIDTH_SCREEN);
    setBackgroundBrush(QBrush(QImage(":/images/bg_redim.png")));
    setScene(scene);

}

void Jeu::play(){

    //réinitialisation de la fenêtre d'affichage
    scene->clear();

    // on cree un item a placer dans la fenêtre
    player = new Joueur(0,25,VIE_JOUEUR,0);
    player->setPos(400,500);
    //rendre l'élément focalisable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // on ajoute l'item a la scene
    scene->addItem(player);
    QObject::connect(player,SIGNAL(win()),this, SLOT(gagner())); // si le signal win est émis alors on fait appel à la méthode public slots gagner()

    affichage = new Affichage();
    scene->addItem(affichage);
    QObject::connect(affichage,SIGNAL(dead()),this, SLOT(gameOver()) );

    QTimer * creation_mechant = new QTimer();
    QObject::connect(creation_mechant ,SIGNAL(timeout()),this,SLOT(creer_mechant()));// création des vagues de méchants
    QObject::connect(creation_mechant,SIGNAL(timeout()),this,SLOT(maj_Map())); // mis à jour de la map de méchants
    creation_mechant ->start(10000);

    QTimer * creation_gentil = new QTimer();
     QObject::connect(creation_gentil,SIGNAL(timeout()),this,SLOT(creer_gentil())); // création vague de gentil
    creation_gentil->start(30000);

    //music background
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sons/combat.mp3"));
    music->play();

    show();
}

/* Méthode permettant d'afficher la fenêtre d'instructions */
void Jeu::afficherInfo()
{
    QWidget* instruction_window = new QWidget;
    QLabel* instructions1 = new QLabel("<h3>EXTERMINEZ LES ENERGIES POLLUANTES AVANT QU'ELLES NE DÉTRUISENT LA TERRE</h3>");
    QLabel* instructions2 = new QLabel("*** Utilisez les flèches droite et gauche pour vous déplacer. *** "
                                       "\n *** Utilisez la barre d'espace pour tirer sur les énergies polluantes. *** "
                                       "\n *** Mais attention à ne pas tirer sur les energies renouvelables. Vous perdriez des points ! ***"
                                       "\n *** Atteignez un score de 80 points et la victoire sera à vous ! ***"
                                       "\n *** A vous maintenant de sauver la planète ! Car il n'y en a qu'une !***");
    instructions2->setAlignment(Qt::AlignCenter);
    QPushButton* close = new QPushButton("Retour");
    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addWidget(instructions1);
    vlayout->addWidget(instructions2);
    vlayout->addWidget(close);
    instruction_window->setLayout(vlayout);
    instruction_window->show();
    QApplication::connect(close, SIGNAL(clicked()), instruction_window, SLOT(close()));
}

/* Méthode permettant de rejouer */
void Jeu::rejouer()
{
    // réinitialisation des différents STL et de la scène
    _tabPollu.clear();
    _tabRenouv.clear();
    _mapPollu.clear();
    scene->clear();
    play();// appel à la fonction play

}

/*méthodes permettant d'afficher le message pour le cas où le joueur perds*/
void Jeu::gameOver()
{
    QString message = "    Vous avez perdu bouuuh ! Les énergies polluantes ont pris le dessus. ";
    AffichageGameOver(message);
}

/*méthodes permettant d'afficher le message pour le cas où le joueur gagne*/
void Jeu::gagner()
{
    QString message2 = "    Vous avez gagné wouuuhouu !! La planète est sauvée !";
    AffichageGameOver(message2);

}

void Jeu::AffichageGameOver(QString message)
{
    // désactiver tous les éléments de la scène
        for (size_t i = 0, n = scene->items().size(); i < n; i++){
            scene->items()[i]->setEnabled(false);
        }
        // création du bouton Rejouer
        Bouton* rejouer = new Bouton(QString("Rejouer"));
        int rxPos = this->width()/2 - rejouer->boundingRect().width()/2;
        int ryPos = 150;
        rejouer->setPos(rxPos,ryPos);
        scene->addItem(rejouer);
        connect(rejouer,SIGNAL(clicked()),this,SLOT(rejouer())); // connection du bouton et de la méthode pour rejouer une fois qu'on à cliqué sur le bouton

        // création du bouton Quitter
        Bouton* quit = new Bouton(QString("Quitter"));
        int qxPos = this->width()/2 - quit->boundingRect().width()/2;
        int qyPos = 275;
        quit->setPos(qxPos,qyPos);
        scene->addItem(quit);
        connect(quit,SIGNAL(clicked()),this,SLOT(close()));

        // création du texte pour annoncer le gagnant
        QGraphicsTextItem* overText = new QGraphicsTextItem(message);
        overText->setPos(150,225);
        scene->addItem(overText);

}

void Jeu::menu(){
    // On commence par le titre
        QGraphicsTextItem* titre = new QGraphicsTextItem(QString("No Planet B"));
        QFont titleFont("Fantasy",50);
        titre->setFont(titleFont);
        int txPos = this->width()/2 - titre->boundingRect().width()/2;
        int tyPos = 150;
        titre->setPos(txPos,tyPos);
        scene->addItem(titre);

        // création du bouton Jouer
        Bouton* jouer = new Bouton(QString("Jouer"));
        int bxPos = this->width()/2 - jouer->boundingRect().width()/2;
        int byPos = 275;
        jouer->setPos(bxPos,byPos);
        connect(jouer,SIGNAL(clicked()),this,SLOT(play()));
        scene->addItem(jouer);

        // création du bouton Quitter
        Bouton* quitButton = new Bouton(QString("Quitter"));
        int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos = 350;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);

        // création du bouton Instructions
        Bouton* instructButton = new Bouton(QString("Instructions"));
        int ixPos = this->width()/2 - instructButton->boundingRect().width()/2;
        int iyPos = 425;
        instructButton->setPos(ixPos,iyPos);
        connect(instructButton,SIGNAL(clicked()),this,SLOT(afficherInfo())); // quand on clique dessus on appel la méthode afficherInfo
        scene->addItem(instructButton);
}

/* Méthode pour créer les gentils */
void Jeu::creer_gentil()
{
    // boucle pour créer les gentils Eolienne
    for(int k= 0;k<2;k++){
        Eolienne* eolienne= new Eolienne(0,20);
        _tabRenouv.push_back(*(eolienne));
        scene-> addItem(eolienne);
        std::cout << "nouveau gentil créé: "<<*eolienne<<"\n";
    }
    // boucle pour créer les gentils Solaire
    for(int i= 0;i<1;i++){
        Solaire* solaire = new Solaire(0,35);
        _tabRenouv.push_back(*(solaire));
        scene-> addItem(solaire);
        std::cout << "nouveau gentil créé: "<<*solaire<<"\n";
    }
}

void Jeu::maj_Map()
{
    // on efface le contenu de la map si elle n'est pas vide
    if(!_mapPollu.empty()){
        _mapPollu.clear();
    }
    // Parcours le vecteur pour regarder si l'élément actuel est présent ou pas
    for (auto& i : _tabPollu){
        // si l'élément actuel n'est pas dans la map alors on l'insère avec une fréquence == 1
        if (_mapPollu.find(i) == _mapPollu.end()){
            _mapPollu[i] = 1;
        }

        // Ou sinon on incrémente le nombre d'éléments (la fréquence)
        else {
            _mapPollu[i]++;
        }
    }
/*
    //Parcours la map pour afficher les occurences de chaque méchant; partie servant à débugger le code
    for (auto& it : _mapPollu){
        std::cout<< "nouvel appel";
        std::cout << it.first << " et nb occurences "
             << it.second << '\n';
    }*/
}

/* Méthode pour créer les méchants */
void Jeu::creer_mechant()
{
    // boucle pour créer les méchants Pétroles
    for (int i =0; i<3;i++){
        Petrole* mechant1 = new Petrole(0,10);
        _tabPollu.push_back(*(mechant1));
        scene->addItem(mechant1);
        std::cout << "nouveau méchant créé: "<<*mechant1<<"\n";
    }
    // boucle pour créer les méchants Nucléaires
    for(int j=0;j<2;j++){
        Nucleaire* mechant2= new Nucleaire(0,20);
        _tabPollu.push_back(*(mechant2));
        scene-> addItem(mechant2);
        std::cout << "nouveau méchant créé: "<<*mechant2<<"\n";
    }
}
