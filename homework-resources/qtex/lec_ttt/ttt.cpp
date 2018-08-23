/****************************************************************************
** $Id:  qt/ttt.cpp   3.0.5   edited Nov 14 2001 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include <qpainter.h>
#include <qdrawutil.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <stdlib.h>                             // rand() function
#include <qdatetime.h>                          // seed for rand()
#include "ttt.h"

#include <iostream>
using namespace std;
//***************************************************************************
//* TTT member functions
//***************************************************************************

// --------------------------------------------------------------------------
// Creates a game widget with a game board and two push buttons, and connects
// signals of child widgets to slots.
//

TTT::TTT( int boardSize, QWidget *parent, const char *name )
    : QWidget( parent )
{
    l = new QVBoxLayout( this );

    // Create a message label

    message = new QLabel( this );
    message->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
    message->setAlignment( Qt::AlignCenter );
    l->addWidget( message );

    // Create the game board and connect the signal finished() to this

    board = new TTTBoard( boardSize, this );
    connect( board, SIGNAL(finished()), SLOT(gameOver()) );
    l->addWidget( board );

    // Create a horizontal frame line

    QFrame *line = new QFrame( this );
    line->setFrameStyle( QFrame::HLine | QFrame::Sunken );
    l->addWidget( line );

    // Create the combo box for deciding who should start, and
    // connect its clicked() signals to the buttonClicked() slot

    whoStarts = new QComboBox( this );
    whoStarts->insertItem(0, "Human starts" );
    whoStarts->insertItem(1, "Computer starts" );
    l->addWidget( whoStarts );

    // Create the push buttons and connect their clicked() signals
    // to this right slots.

    newGame = new QPushButton( "Play!", this );
    connect( newGame, SIGNAL(clicked()), SLOT(newGameClicked()) );

    quit = new QPushButton( "Quit", this );
    // qApp is a global pointer to the application
    connect( quit, SIGNAL(clicked()), qApp, SLOT(quit()) );

    QHBoxLayout * b = new QHBoxLayout;
    b->addWidget( newGame );
    b->addWidget( quit );

    l->addLayout( b );

    newState();
}

TTT::~TTT()
{
    delete board;
    delete whoStarts;
    delete newGame;
    delete quit;
    delete message;
    delete l;
}

// --------------------------------------------------------------------------
// TTT::newGameClicked()                  - SLOT
//
// This slot is activated when the new game button is clicked.
//

void TTT::newGameClicked()
{
  // most of the internal data/state is kept in the board object
  // so we reset it via it's newGame() method
  board->newGame(whoStarts->currentIndex(), true);

  // then we update our widgets
  newState();
}


// --------------------------------------------------------------------------
// TTT::gameOver()                        - SLOT
//
// This slot is activated when the TicTacGameBoard emits the signal
// "finished()", i.e. when a player has won or when it is a draw.
//

void TTT::gameOver()
{
    newState();                                 // update text box
}


// --------------------------------------------------------------------------
// Updates the message to reflect a new state.
//

void TTT::newState()
{
    static const char *msg[] = {                // TicTacGameBoard::State texts
        "Click Play to start", "Make your move",
        "You won!", "Computer's move", "Computer won!", "It's a draw" };

    // get the state from the board and use that to decide
    // which message gets printed
    message->setText( msg[board->state()] );
}

