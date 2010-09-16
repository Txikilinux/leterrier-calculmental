#ifndef EDITEUR_H
#define EDITEUR_H

#include <QtGui/QWidget>

namespace Ui {
    class Editeur;
}

class Editeur : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(Editeur)
public:
    explicit Editeur(QWidget *parent = 0);
    virtual ~Editeur();
    QString getNiveauEnCours();
    void initialiser();

protected:
    virtual void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);


private:
    Ui::Editeur *m_ui;
    QString *m_niveauEnCours;
   // bool nouvelUtilisateur;
    void initialiserOperation(QString);
    void initialiserApproche(QString operation);
    void initialiserComplement(QString operation);

private slots:
    void on_btnQuitter_clicked();
    void sauverNiveau(QString);
    void chargerNiveau(QString);
    void changerNiveau(QString);
};

#endif // EDITEUR_H
