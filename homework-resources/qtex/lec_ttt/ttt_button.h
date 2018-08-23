/****************************************************************************
** $Id:  qt/tictac.h   3.0.5   edited Oct 12 2001 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

/****************************************************************************
** Edited by Mark Redekopp - 2013-Mar-16
**  Updated for Qt 4.8 (mainly updated to use qvector)
*****************************************************************************/
#ifndef TTT_BUTTON_H
#define TTT_BUTTON_H

#include <qpushbutton.h>

// --------------------------------------------------------------------------
// TTTButton implements a single tic-tac-toe button
//
class TTTButton : public QPushButton
{
    Q_OBJECT
public:
    TTTButton( QWidget *parent );

    // override functions related to the size of the button
    QSizePolicy sizePolicy() const
    { return QSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred ); }

    QSize sizeHint() const { return QSize( 32, 32 ); }
    QSize minimumSizeHint() const { return QSize( 10, 10 ); }

    // Tic-Tac-Toe specific stuff
    enum Type { Blank, Circle, Cross };
    Type        type() const            { return t; }

    // Note: repaint() triggers a paintEvent
    void        setType( Type type )    { t = type; repaint(); }

protected:
    void paintEvent(QPaintEvent *event);
private:
    Type t;
};


#endif // TTT_BUTTON_H



