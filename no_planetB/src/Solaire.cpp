#include "../lib/Solaire.h"
#include "../lib/Jeu.h"
#include <QTimer>
extern Jeu* grille;

Solaire::Solaire(QGraphicsItem * parent,int pS) : QObject(),QGraphicsPixmapItem(parent),EnergieRenouvelable(pS,"Solaire"){
    int random_number = rand() % 700;
    setPos(random_number,0);
    // drew the Jontil
    setPixmap(QPixmap(":/images/solar_redim.png"));

    //connexion des différents slots à un timer
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(soigner()));
    timer->start(50); // timer time to 50 ms
}

/*Méthodes calculant les soins effectué par un Solaire */
int Solaire::soins(Joueur *j, Solaire *sj)
{
    int s = j->getpV()+ sj->getpS();

    if(s>VIE_JOUEUR){
        j->setPv(VIE_JOUEUR);
        return 1;
    }
    else{
        j->setPv(s);
        return 0;
    }


}

/* Méthode contrôlant le déplacement des Solaires*/
void Solaire::move()
{
    //move Solaire
     setPos(x(), y()+5);
     if(pos().y() > 600){ // s'il quitte la fenêtre graphique alors on le supprime et on l'enlève de la scène
         scene()->removeItem(this);
         delete this;
         //qDebug() << "mechant supprime";
     }
}

void Solaire::soigner()
{
    // si collision avec Joueur on le soigne
     QList<QGraphicsItem*> list2 = collidingItems();
     int n = list2.size();
     for (int i = 0; i< n; i++){
         if(typeid(*(list2[i])) == typeid(Joueur)){
             soins(grille->player,this);
             qDebug() << "le joueur s'est fait soigner par SJ";
             qDebug()<< "pS Soin" << this->getpS();
             scene()->removeItem(this);
             delete this;

            }
         else if(typeid(*(list2[i])) == typeid(Solaire)){
             setPos(rand()%700,0);
             qDebug()<<"perso change de place";
         }
      }
 }




