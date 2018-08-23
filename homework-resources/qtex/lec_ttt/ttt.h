/****************************************************************************
** $Id:  qt/ttt.h   3.0.5   edited Oct 12 2001 $
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
#ifndef TTT_H
#define TTT_H

// --------------------------------------------------------------------------
// TTT implements the complete game.
// TTT is a composite widget that contains a TTTBoard and
// two push buttons for starting the game and quitting.
//
#include <qapplication.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include "ttt_board.h"

class TTT : public QWidget
{
    Q_OBJECT
public:
    TTT( int boardSize=3, QWidget *parent=0, const char *name=0 );
    ~TTT();
private slots:
    void        newGameClicked();
    void        gameOver();
private:
    void        newState();
    QComboBox   *whoStarts;
    QPushButton *newGame;
    QPushButton *quit;
    QLabel      *message;
    QVBoxLayout * l;
    TTTBoard    *board;
};


#endif // TTT_H



