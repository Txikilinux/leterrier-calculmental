#include "interface.h"
#include "ui_interface.h"
#include "exercice.h"
#include "ui_exercice.h"
#include "editeur.h"
#include "boutonspolygone.h"

#include <QApplication>
 #include <QDesktopWidget>


interface::interface(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::interfaceClass)
{
    ui->setupUi(this);
    QRect ecran;
    ecran=QApplication::desktop()->screenGeometry();

    QFile* fichierConf = new QFile("./maConfig.ini");
    if (!fichierConf->exists()) qDebug()<<QString::fromUtf8("Fichier config NON trouvé");
    else qDebug() << QString::fromUtf8("Fichier config trouvé");
    qDebug() << "Taille ecran : " << ecran.width()<< " X "<<ecran.height();
    this->resize(ecran.width(),ecran.height());
    ui->fete->resize(ecran.width()*0.85,ecran.height()*0.85);

    QPixmap imgFond("./images/fondecran.png");
    QPixmap imgFond2=imgFond.scaled(ecran.width()*0.85,ecran.height()*0.85);
    qDebug() << "Taille imageFond : " << imgFond.width()<< " X "<<imgFond.height();
    qDebug() << "Taille imageFond2 : " << imgFond2.width()<< " X "<<imgFond2.height();
    QBrush* fond = new QBrush(imgFond2);
    ui->fete->setBackgroundBrush(*fond);

    double kw=ecran.width()*0.85/1024;
    double kh=ecran.height()*0.85/768;

    QGraphicsScene* dessin = new QGraphicsScene(this);
        ui->fete->setScene(dessin);
        dessin->setSceneRect(0, 0, ecran.width()*0.85,ecran.height()*0.85);

    m_editeur = new Editeur();

    boutonsPolygone* btnPoly1 = new boutonsPolygone("addition");
        btnPoly1->deplace(0*kw,350*kh);
        btnPoly1->retaille(380*kw,170*kh);
        //btnPoly1->tourne(-20);
        btnPoly1->QGraphicsItem::setToolTip("Faire des additions");
        btnPoly1->setTexte("Additions");
        dessin->addItem(btnPoly1);

    boutonsPolygone* btnPoly2 = new boutonsPolygone("multiplication");
        btnPoly2->deplace(400*kw,450*kh);
        btnPoly2->retaille(270*kw,270*kh);
        btnPoly2->QGraphicsItem::setToolTip("Faire des multiplications");
        btnPoly2->setTexte("Multiplications");
        dessin->addItem(btnPoly2);

    boutonsPolygone* btnPoly3 = new boutonsPolygone("editeur");
        btnPoly3->deplace(60*kw,520*kh);
        btnPoly3->retaille(100*kw,200*kh);
        btnPoly3->QGraphicsItem::setToolTip(QString::fromUtf8("Lancer l'éditeur"));
        dessin->addItem(btnPoly3);

    boutonsPolygone* btnPoly4 = new boutonsPolygone("sortie");
        btnPoly4->deplace(840*kw,610*kh);
        btnPoly4->retaille(120*kw,40*kh);
        btnPoly4->QGraphicsItem::setToolTip("Quitter");
        connect(btnPoly4, SIGNAL(sortie()), this, SLOT(close()));
        dessin->addItem(btnPoly4);
        
    boutonsPolygone* btnPoly5 = new boutonsPolygone("1tableM");
        btnPoly5->deplace(20*kw,15*kh);
        btnPoly5->retaille(230*kw,250*kh);
        btnPoly5->QGraphicsItem::setToolTip("Tables de multiplication");
        btnPoly5->setTexte("Tables de multiplication");
        dessin->addItem(btnPoly5);

     boutonsPolygone* btnPoly6 = new boutonsPolygone("2complementA");
        btnPoly6->deplace(530*kw,60*kh);
        btnPoly6->retaille(250*kw,180*kh);
        btnPoly6->tourne(12);
        btnPoly6->QGraphicsItem::setToolTip(QString::fromUtf8("Compléments additifs"));
        btnPoly6->setTexte("Complements additifs");
        dessin->addItem(btnPoly6);

    boutonsPolygone* btnPoly7 = new boutonsPolygone("3complementM");
        btnPoly7->deplace(780*kw,220*kh);
        btnPoly7->retaille(110*kw,90*kh);
        btnPoly7->tourne(10);
        btnPoly7->QGraphicsItem::setToolTip("Multiples");
        btnPoly7->setTexte("Multiples");
        dessin->addItem(btnPoly7);

    boutonsPolygone* btnPoly8 = new boutonsPolygone("soustraction");
        btnPoly8->deplace(330*kw,140*kh);
        btnPoly8->retaille(150*kw,180*kh);
        btnPoly8->QGraphicsItem::setToolTip(QString::fromUtf8("Soustractions"));
        btnPoly8->setTexte("Soustractions");
        dessin->addItem(btnPoly8);

    boutonsPolygone* btnPoly9 = new boutonsPolygone("4tableA");
        btnPoly9->deplace(170*kw,255*kh);
        btnPoly9->retaille(190*kw,30*kh);
        btnPoly9->tourne(-27);
        btnPoly9->QGraphicsItem::setToolTip("Tables d'addition");
        btnPoly9->setTexte("Tables d'addition");
        dessin->addItem(btnPoly9);
    }

interface::~interface()
{
    delete ui;
}

void interface::paintEvent(QPaintEvent* e )
{
    QMainWindow::paintEvent(e);
}
void interface::on_actionQuitter_triggered()
{
    this->close();
}

void interface::on_actionAdditions_triggered()
{
    m_exercice = new exercice("addition",0,"",this);
    m_exercice->show();
}

void interface::on_actionMultiplications_triggered()
{
    m_exercice = new exercice("multiplication",0,"",this);
    m_exercice->show();
}

void interface::on_actionp2_triggered()
{
    m_exercice = new exercice("tableA",2,"",this);
    m_exercice->show();
}

void interface::on_actionp3_triggered()
{
    m_exercice = new exercice("tableA",3,"",this);
    m_exercice->show();
}

void interface::on_actionp4_triggered()
{
    m_exercice = new exercice("tableA",4,"",this);
    m_exercice->show();
}

void interface::on_actionp5_triggered()
{
    m_exercice = new exercice("tableA",5,"",this);
    m_exercice->show();
}

void interface::on_actionp6_triggered()
{
    m_exercice = new exercice("tableA",6,"",this);
    m_exercice->show();
}

void interface::on_actionp7_triggered()
{
    m_exercice = new exercice("tableA",7,"",this);
    m_exercice->show();
}

void interface::on_actionp8_triggered()
{
    m_exercice = new exercice("tableA",8,"",this);
    m_exercice->show();
}

void interface::on_actionp9_triggered()
{
    m_exercice = new exercice("tableA",9,"",this);
    m_exercice->show();
}

void interface::on_actionX_2_triggered()
{
    m_exercice = new exercice("tableM",2,"",this);
    m_exercice->show();
}

void interface::on_actionX_3_triggered()
{
    m_exercice = new exercice("tableM",3,"",this);
    m_exercice->show();
}

void interface::on_actionX_4_triggered()
{
    m_exercice = new exercice("tableM",4,"",this);
    m_exercice->show();
}

void interface::on_actionX_5_triggered()
{
    m_exercice = new exercice("tableM",5,"",this);
    m_exercice->show();
}

void interface::on_actionX_6_triggered()
{
    m_exercice = new exercice("tableM",6,"",this);
    m_exercice->show();
}

void interface::on_actionX_7_triggered()
{
    m_exercice = new exercice("tableM",7,"",this);
    m_exercice->show();
}

void interface::on_actionX_8_triggered()
{
    m_exercice = new exercice("tableM",8,"",this);
    m_exercice->show();
}

void interface::on_actionX_9_triggered()
{
    m_exercice = new exercice("tableM",9,"",this);
    m_exercice->show();
}

void interface::on_actionAfficher_l_diteur_triggered()
{
    m_editeur->show();
}
