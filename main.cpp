/**
  * Implémentation de la fonction main qui permet soit de lancer l'interface générale, soit de lancer un exercice donné, avec éventuellement un niveau donné
  *
  * @warning nécessité de respecter la syntaxe
  * @see https://redmine.ryxeo.com/projects/leterrier-calculment/
  * @author 2009-2010 Philippe Cadaugade <philippe.cadaugade@ryxeo.com>
  * @see The GNU Public License (GPL)
  */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <QtGui/QApplication>
#include "interface.h"
#include "exercice.h"
#include "editeur.h"
#include <stdio.h>

extern const QString abeApplicationLongName=QObject::trUtf8("AbulÉdu LeTerrier -- Calcul-Mental");

void debugOutput(QtMsgType type, const char *msg)
 {
     switch (type) {
     case QtDebugMsg:
#ifdef QT_NO_DEBUG_OUTPUT
         fprintf(stderr, "Debug: %s\n", msg);
#endif
         break;
     case QtWarningMsg:
#ifdef QT_NO_WARNING_OUTPUT
         fprintf(stderr, "Warning: %s\n", msg);
#endif
         break;
     case QtCriticalMsg:
         fprintf(stderr, "Critical: %s\n", msg);
         break;
     case QtFatalMsg:
         fprintf(stderr, "Fatal: %s\n", msg);
         abort();
     }
 }


int main(int argc, char *argv[])
{
//    MonApplication appli(argc,argv);
//    QObject* appliCastee = qobject_cast<QApplication*>(&appli);
//    appli.QObject::installEventFilter(appliCastee);
    QApplication appli(argc, argv);
    //qInstallMsgHandler(debugOutput);
    qDebug()<<"Nom de mon appli : "<<appli.objectName();
    qApp->setApplicationName("leterrier-calculment");
    qApp->setApplicationVersion("1.0.6");
    QString exo;
    QString nivo="";
    int nombre=0;
    //Je teste si l'appel a des arguments, le premier étant forcément le nom de l'exercice
    if (argc>1) {
        exo= argv[1];
        exo.remove("--exercice=", Qt::CaseInsensitive);
        exo.toLower();}
    qDebug()<<"exo : "<<exo;

    //Je teste si l'appel a d'autres arguments je récupère leur valeur, sachant qu'ici je me suis embêté à tester l'ordre des paramètres ce qui est inutile depuis la "normalisation"
    QString deuze;
    QString troize;
    if (argc>2){
        deuze= argv[2];
        troize=argv[3];
        qDebug()<<"deuze : "<<deuze<<"4ème lettre : "<<deuze[3];
        if (deuze[3]=='n') {
            deuze.remove("--niveau=", Qt::CaseInsensitive);
            deuze.prepend("Niveau");
            nivo=deuze;
            qDebug()<<"nivo : "<<nivo;
            }
        else if (deuze[3]=='o') {
            deuze.remove("--nombre=", Qt::CaseInsensitive);
            nombre=deuze.toInt();
            qDebug()<<"nombre : "<<nombre;
            }
        if (troize[3]=='i') {
            troize.remove("--niveau=", Qt::CaseInsensitive);
            troize.prepend("Niveau");
            nivo=troize;
            qDebug()<<"nivo : "<<nivo;
            }
        else if (troize[3]=='o') {
            troize.remove("--nombre=", Qt::CaseInsensitive);
            nombre=troize.toInt();
            qDebug()<<"nombre : "<<nombre;
            }
        }
    //à améliorer : dans un cas l'interface est créée pour rien, dans l'autre c'est l'exercice... de toute façon c'est de la mémoire utilisée pour rien !!
    interface w;
    w.setWindowTitle("Calcul Mental");
    if (nombre!=0) exo.append(QString::number(nombre));
    qDebug()<<"exo : "<<exo;
    //exercice e(exo,&a,nombre,nivo);
    exercice e(exo,0,nombre,nivo);
        QPixmap* imageFond = new QPixmap("./data/images/"+exo+".jpg");
        e.adapte(*imageFond);
//        e.setImgFond(imageFond);
//        e.setFixedSize(imageFond->width()+150,imageFond->height()+20);
        //QObject* appliCastee = qobject_cast<QApplication*>(&appli);
        e.setObjectName("exercoce");
        //e.setParent(&w);//c'est ça qui mettait le bazar et créait la fenêtre blanche... je le commente, j'espère que ce n'était indispensable pour autre chose...
        e.setWindowTitle("exercice");
    if (argc==1) w.show();
    else e.show();
    return appli.exec();
}
