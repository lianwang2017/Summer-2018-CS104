/****************************************************************************
** $Id:  qt/tictac.cpp   3.0.5   edited Nov 14 2001 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "ttt_button.h"
#include <qapplication.h>
#include <qpainter.h>
#include <qdrawutil.h>

//***************************************************************************
//* TTTButton member functions
//***************************************************************************

// --------------------------------------------------------------------------
// Creates a TicTacToe Button
//

TTTButton::TTTButton( QWidget *parent ) : QPushButton( parent )
{
    t = Blank;      // initial type
}

// --------------------------------------------------------------------------
// Paints TTTButton
//

void TTTButton::paintEvent(QPaintEvent *event)
{

  QPushButton::paintEvent(event);

    QPainter p(this);
    // Every button can get it's enclosing rectangle from rect()
    QRect r = rect();

    p.setPen( Qt::SolidLine );
    //p.setBrush(Qt::blue);

    if ( t == Circle ) {
      // Provide an enclosing rectangle for ellipse to be drawn
      p.drawEllipse( r.left()+4, r.top()+4, r.width()-8, r.height()-8 );
    } else if ( t == Cross ) {                  // draw cross
      // drawLine wants to two points...topLect(), etc. returns QPoint's
      p.drawLine( r.topLeft()   +QPoint(4,4), r.bottomRight()-QPoint(4,4));
      p.drawLine( r.bottomLeft()+QPoint(4,-4),r.topRight()   -QPoint(4,-4));
    }


}


