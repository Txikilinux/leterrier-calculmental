/** Classe de base pour les exercices du logiciel Calcul mental
  * Modification importante par rapport à la première implémentation pour hériter d'AbulEduStateMachineV1
  *
  * @see https://redmine.ryxeo.com/projects/ryxeo/wiki/LeTerrierExercice
  * @author 2014 Philippe Cadaugade <philippe.cadaugade@ryxeo.com>
  *
  * @see The GNU Public License (GPL)
  *
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

#ifndef EXERCICEOPERATION_H
#define EXERCICEOPERATION_H

#include "abstractexercise.h"
#include <QGraphicsItemAnimation>


class ExerciceOperation : public AbstractExercise
{

Q_OBJECT
public:
    ExerciceOperation(QString exerciseName, QWidget *parent, int val = 0, QString niveau = QString());
    ~ExerciceOperation();

protected:
    QWidget* m_parent;

    int verifieReponse();
    int donneReponse();

    /** Dimensionne et place les widgets
      * @param ratio le ratio est par défaut celui calculé dans l'AbulEduApplicationV1 */
    void setDimensionsWidgets(float ratio = abeApp->getAbeApplicationDecorRatio());

    int m_minG;
    int m_maxG;
    int m_minD;
    int m_maxD;
    int m_temps;

    void chargerParametres();

    void animeBaudruche();

protected slots:
    /** Entrée dans l'état "sequence" de l'AbulEduStateMachineV1
      * Passage unique au lancement de la machine à états */
    virtual void slotSequenceEntered();

    /** Entrée dans l'état "PresentationSequence" de l'AbulEduStateMachineV1
      * Passage unique au lancement de la machine à états */
    virtual void slotPresenteSequenceEntered();

    /** Entrée dans l'état "realisationExercice" de l'AbulEduStateMachineV1
      * Passage une seule fois au début de chaque exercice */
    virtual void slotRealisationExerciceEntered();

    /** Entrée dans l'état "initQuestion" de l'AbulEduStateMachineV1
      * Passage en boucle à chaque nouvelle question
      * Par contre, on n'y repasse pas si on refait la même question */
    virtual void slotInitQuestionEntered();

    /** Entrée dans l'état "question" de l'AbulEduStateMachineV1
      * Passage une fois au début de chaque question, puis en cas de réponse incorrecte ou clic sur btnRefaire */
    virtual void slotQuestionEntered();

    /** Entrée dans l'état "afficheVerificationQuestion" de l'AbulEduStateMachineV1
      * Passage à chaque clic sur btnVerifier */
    virtual void slotAfficheVerificationQuestionEntered();

    /** Entrée dans l'état "finVerificationQuestion" de l'AbulEduStateMachineV1
      * Passage en sortie de l'état "afficheVerificationQuestion" */
    virtual void slotFinVerificationQuestionEntered();

    /** Entrée dans l'état "afficheCorrectionQuestion" de l'AbulEduStateMachineV1
      * Passage à chaque clic sur btnCorriger */
    virtual void slotAfficheCorrectionQuestionEntered();

    /** Entrée dans l'état "finCorrectionQuestion" de l'AbulEduStateMachineV1
      * Passage en sortie de l'état "afficheCorrectionQuestion" */
    virtual void slotFinCorrectionQuestionEntered();

    //    /** Entrée dans l'état "bilanExercice" de l'AbulEduStateMachineV1
    //      * Passage pour chaque exercice si la variable onPeutPresenterBilanExercice vaut true */
    //    void slotBilanExerciceEntered();

    /** Entrée dans l'état "bilanSequence" de l'AbulEduStateMachineV1
      * @warning Passage unique en fin de séquence */
    virtual void slotBilanSequenceEntered();

    //    /** Connecté au clic sur btnQuitter */
    //    void slotQuitter();

    /** Intercepte les evénénements issus de abeApp
     * Utilisé pour filtrer les appuis sur le clavier (pour l'instant)
     */
    bool eventFilter(QObject *obj, QEvent *event);

    void ajouteErreur(QString msg);
};

#endif // EXERCICEOPERATION_H
