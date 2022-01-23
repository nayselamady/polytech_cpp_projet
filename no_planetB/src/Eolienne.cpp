#include "../lib/Eolienne.h"
#include <QTimer>

extern Jeu* grille;

/* Constructeur */
Eolienne :: Eolienne(QGraphicsItem * parent,int pS) :QObject(),QGraphicsPixmapItem(parent), EnergieRenouvelable(pS,"Eolienne"){
    // on fixe une position aléatoire
    int random_number = rand() % 700;
    setPos(random_number,0);
    // affichage de l'image
    setPixmap(QPixmap(":/images/eolienne_redim.png"));// changer l'image
    // si image a l'envers et que l'on souhaite la faire tourner
     setRotation(180);

    //connexion des différents slots à un timer
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(soigner()));

    timer->start(50); // on règle le timer pour qu'il commence dans 50 ms
}

/*Méthodes calculant les soins effectué par une Eolienne */
int Eolienne::soins(Joueur *j, Eolienne *jo)
{
    int s = j->getpV()+ jo->getpS(); // calcul des nouveaux points de vie du joueur 

    if(s>VIE_JOUEUR){
        j->setPv(VIE_JOUEUR);
        return 1;
    }
    else{
        j->setPv(s);
        return 0;
    }

}

/* Méthode contrôlant le déplacement des Eoliennes*/
void Eolienne::move()
{
    //move Eolienne
     setPos(x(), y()+5);
     if(pos().y() > 600){ // s'il quitte la fenêtre graphique alors on le supprime et on l'enlève de la scène
         scene()->removeItem(this);
         delete this;
         //qDebug() << "gentil supprimé";
     }

}

/* Méthode permettant à une Eolienne de "soigner" le joueur lorsqu'ils entrent en collision
 Si une Eolienne touche une autre éolienne alors on la change de place */
void Eolienne::soigner()
{

    QList<QGraphicsItem*> list2 = collidingItems();
    int n = list2.size();
    for (int i = 0; i< n; i++){
        if(typeid(*(list2[i])) == typeid(Joueur)){ // si collision avec Joueur on le soigne
            soins(grille->player,this);
            scene()->removeItem(this);
            delete this;
           }
        else if(typeid(*(list2[i])) == typeid(Eolienne)){ // si collision avec Eolienne on change de place
            setPos(rand()%700,0);
        }
     }
}
