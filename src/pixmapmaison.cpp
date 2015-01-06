/** Objet cible des exercices du type Maison des nombres
  *
  * @see https://redmine.ryxeo.com/projects/ryxeo/wiki/LeTerrierExercice
  * @author 2011-2012 Philippe Cadaugade <philippe.cadaugade@ryxeo.com>
  * @author 2012 Eric Seigne <eric.seigne@ryxeo.com>
  * @author 2013 Icham Sirat <icham.sirat@ryxeo.com>
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

#include "pixmapmaison.h"
#include <QGraphicsSceneHoverEvent>
#include <QDebug>

/* Il est possible qu'AUCUNE des fonctions ci-dessous ne servent, à présent !! */

PixmapMaison::PixmapMaison(QPixmap image)
    :QGraphicsPixmapItem(image)
{
    m_pixmapInitial = image;
//    setAcceptHoverEvents(true);
//    m_isChangeableAuSurvol = false;
}

//void PixmapMaison::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
//{
//    qDebug()<<"PixmapMaison::hoverEnterEvent "<<m_isChangeableAuSurvol;
//    if (m_isChangeableAuSurvol)
//    {
//    event->accept();
//    qDebug()<<"Survol de "<<toolTip();
//    if (toolTip().right(1) == "0")
//        setPixmap(QPixmap("./data/images/maison"+toolTip().right(2)+"b.png"));
//    else
//        setPixmap(QPixmap("./data/images/maison"+toolTip().right(1)+"b.png"));
//    this->setSelected(true);
//    }
//}

//void PixmapMaison::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
//{
//    qDebug()<<"PixmapMaison::hoverLeaveEvent "<<m_isChangeableAuSurvol;
//    if (m_isChangeableAuSurvol)
//    {
//    event->accept();
//    if (toolTip().right(1) == "0")
//        setPixmap(QPixmap("./data/images/maison"+toolTip().right(2)+".png"));
//    else
//        setPixmap(QPixmap("./data/images/maison"+toolTip().right(1)+".png"));
//    this->setSelected(false);
//    }
//}

//void PixmapMaison::rendSelectionnable()
//{
//    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
//    this->setAcceptHoverEvents(true);
//}

//void PixmapMaison::rendNonSelectionnable()
//{
//    this->setFlag(QGraphicsItem::ItemIsSelectable, false);
//    this->setAcceptHoverEvents(false);
//}

//void PixmapMaison::peutChangerImage()
//{
//    m_isChangeableAuSurvol = true;
//}

//void PixmapMaison::nePeutPasChangerImage()
//{
//    m_isChangeableAuSurvol = false;
//}

QPixmap PixmapMaison::getMPixmapInitial()
{
    return m_pixmapInitial;
}

void PixmapMaison::setMPixmapInitial()
{
    setPixmap(m_pixmapInitial);
}
