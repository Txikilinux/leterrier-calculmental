#include "interface.h"
#include "ui_interface.h"
#include "exercice.h"
#include "ui_exercice.h"
#include "editeur.h"
#include "boutonspolygone.h"

interface::interface(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::interfaceClass)
{
    ui->setupUi(this);

    QFile* fichierConf = new QFile("./maConfig.ini");
    if (!fichierConf->exists()) qDebug()<<QString::fromUtf8("Fichier config NON trouvé");
    else qDebug() << QString::fromUtf8("Fichier config trouvé");

    m_editeur = new Editeur();

    QPixmap* imgFond = new QPixmap("./images/fondecran.png");
    QBrush* fond = new QBrush(*imgFond);
    ui->fete->setBackgroundBrush(*fond);

    QGraphicsScene* dessin = new QGraphicsScene(this);
        ui->fete->setScene(dessin);
        dessin->setSceneRect(0, 0, 1024, 768);

    boutonsPolygone* btnPoly1 = new boutonsPolygone("addition");
        btnPoly1->deplace(-75,340);
        btnPoly1->retaille(60,90);
        btnPoly1->tourne(-20);
        btnPoly1->QGraphicsItem::setToolTip("Faire des additions");
        btnPoly1->setTexte("Additions");
        dessin->addItem(btnPoly1);

    boutonsPolygone* btnPoly2 = new boutonsPolygone("multiplication");
        btnPoly2->deplace(250,310);
        btnPoly2->retaille(100,80);
        btnPoly2->QGraphicsItem::setToolTip("Faire des multiplications");
        btnPoly2->setTexte("Multiplications");
        dessin->addItem(btnPoly2);

    boutonsPolygone* btnPoly3 = new boutonsPolygone("editeur");
        btnPoly3->deplace(930,640);
        btnPoly3->retaille(50,100);
        btnPoly3->QGraphicsItem::setToolTip(QString::fromUtf8("Lancer l'éditeur"));
        dessin->addItem(btnPoly3);

    boutonsPolygone* btnPoly4 = new boutonsPolygone("sortie");
        btnPoly4->deplace(160,590);
        btnPoly4->retaille(60,30);
        btnPoly4->QGraphicsItem::setToolTip("Quitter");
        connect(btnPoly4, SIGNAL(sortie()), this, SLOT(close()));
        dessin->addItem(btnPoly4);
        
    boutonsPolygone* btnPoly5 = new boutonsPolygone("1tableM");
        btnPoly5->deplace(830,90);
        btnPoly5->retaille(160,30);
        btnPoly5->QGraphicsItem::setToolTip("Tables de multiplication");
        btnPoly5->setTexte("Tables de multiplication");
        dessin->addItem(btnPoly5);

     boutonsPolygone* btnPoly6 = new boutonsPolygone("2complementA");
        btnPoly6->deplace(400,90);
        btnPoly6->retaille(150,30);
        btnPoly6->QGraphicsItem::setToolTip(QString::fromUtf8("Compléments additifs"));
        btnPoly6->setTexte("Complements additifs");
        dessin->addItem(btnPoly6);

    boutonsPolygone* btnPoly7 = new boutonsPolygone("3complementM");
        btnPoly7->deplace(490,280);
        btnPoly7->retaille(70,30);
        btnPoly7->QGraphicsItem::setToolTip("Multiples");
        btnPoly7->setTexte("Multiples");
        dessin->addItem(btnPoly7);

    boutonsPolygone* btnPoly8 = new boutonsPolygone("soustraction");
        btnPoly8->deplace(125,310);
        btnPoly8->retaille(100,80);
        btnPoly8->QGraphicsItem::setToolTip(QString::fromUtf8("Soustractions"));
        btnPoly8->setTexte("Soustractions");
        dessin->addItem(btnPoly8);

    boutonsPolygone* btnPoly9 = new boutonsPolygone("4tableA");
        btnPoly9->deplace(720,210);
        btnPoly9->retaille(160,30);
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
