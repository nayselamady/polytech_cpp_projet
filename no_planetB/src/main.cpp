#include <QApplication>
#include "../lib/Jeu.h"
#include <QDebug>
#include <iostream>

Jeu* grille;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    grille = new Jeu();
    grille->show();
    grille->menu();
    return a.exec();


}
