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
#ifndef TTT_BOARD_H
#define TTT_BOARD_H

#include <qwidget.h>
#include <qlayout.h>
#include "ttt_button.h"

// Using template vector to make vector-class of TicTacButton.
// This vector is used by the TTTBoard class defined below.
typedef QVector<TTTButton*>        TTTButtonVec;
typedef QVector<int>          	   TTTArray;


// --------------------------------------------------------------------------
// TTTBoard implements the tic-tac-toe game board.
// TTTBoard is a composite widget that contains N x N TTTButtons.
// N is specified in the constructor.
//

class TTTBoard : public QWidget
{
  Q_OBJECT
public:
  TTTBoard( int n, QWidget *parent=0, const char *name=0 );
  ~TTTBoard();

  // Changed by MWR
  //  Defines the possible state that game can be in
  enum        State { Init, P1Turn, P1Won, P2Turn, P2Won, NobodyWon };

  State       state() const           { return st; }
  bool        computerPlaying()       { return compPlaying; }
  //void        p2Starts( bool v );
  void        newGame(int whoStarts, bool computerPlays);
 
signals:
  void        finished();                     // game finished
  
private slots:
  void        buttonClicked();


private:
  void        setState( State state ) { st = state; }
  void        updateButtons();           //
  int         checkBoard( TTTArray * );  // Check if Game over
  void        computerMove();            // Do computer move

private:
  bool        compPlaying; // Used when we support human-human games
  State       st;          // state of the game
  int         nBoard;      // size of the board
  bool        comp_starts; // does computer start
  TTTArray     *btArray;   // Array of values of the squares
  TTTButtonVec *buttons;   // Array of actual buttons
  QGridLayout  *grid;
};



#endif // TTT_BOARD_H



