/****************************************************************************
 ** $Id:  qt/tictac.cpp   3.0.5   edited Nov 14 2001 $
 **
 ** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
 **
 ** This file is part of an example program for Qt.  This example
 ** program may be used, distributed and modified without limitation.
 **
 *****************************************************************************/

#include "ttt_board.h"
#include <qapplication.h>
#include <qpainter.h>
#include <qdrawutil.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <stdlib.h>                             // rand() function
#include <qdatetime.h>                          // seed for rand()
#include <iostream>
using namespace std;

//***************************************************************************
//* TTTBoard member functions
//***************************************************************************

// --------------------------------------------------------------------------
// Creates a game board with N x N buttons and connects the "clicked()"
// signal of all buttons to the "buttonClicked()" slot.
//

TTTBoard::TTTBoard( int n, QWidget *parent, const char *name )
  : QWidget( parent )
{
  st = Init;                                  // initial state
  nBoard = n;
  n *= n;                                     // make square
  comp_starts = FALSE;                        // human starts
  buttons = new TTTButtonVec();             // create real buttons
  btArray = new TTTArray(n);               // create button model
  QGridLayout * grid = new QGridLayout( this );//, nBoard, nBoard, 4 );
  for ( int i=0; i<n; i++ ) {                 // create and connect buttons
    TTTButton *ttb = new TTTButton( this );

    connect( ttb, SIGNAL(clicked()), SLOT(buttonClicked()) );
    grid->addWidget( ttb, i%nBoard, i/nBoard );
    buttons->insert( i, ttb) ;
    (*btArray)[i] = TTTButton::Blank;   // initial button type
  }
  QTime t = QTime::currentTime();             // set random seed
  srand( t.hour()*12+t.minute()*60+t.second()*60 );
}

TTTBoard::~TTTBoard()
{
  delete buttons;
  delete btArray;
  delete grid;
}


// TTTBoard::newGame()
//
// Clears the game board and prepares for a new game
//
void TTTBoard::newGame(int whoStarts, bool computerPlays)
{
  st = P1Turn;
  compPlaying = computerPlays;
  for ( int i=0; i<nBoard*nBoard; i++ )
    (*btArray)[i] = TTTButton::Blank;
  if ( whoStarts == 1){
    st = P2Turn;
    if(compPlaying ){
      computerMove();
      st = P1Turn;
    }
  }
  updateButtons();
}


// --------------------------------------------------------------------------
// TTTBoard::buttonClicked()             - SLOT
//
// This slot is activated when a TTTButton emits the signal "clicked()",
// i.e. the user has clicked on a TTTButton.
//

void TTTBoard::buttonClicked()
{
  if ( st != P1Turn && st != P2Turn )    // not ready
    return;
  // find which button generated the event
  int i;
  for(i=0; i < buttons->size(); i++){
    if(buttons->at(i) == (TTTButton*)sender())
      break;
  }
  TTTButton *b = buttons->at(i);           // get piece that was pressed

  if ( b->type() == TTTButton::Blank ) {   // empty piece?
    int s;
    if(st == P1Turn){
      (*btArray)[i] = TTTButton::Circle;
      updateButtons();
      s = checkBoard( btArray );
      if ( s == 0 && compPlaying ){			
	computerMove();
	updateButtons();
	s = checkBoard( btArray );
      }
      // only used when we supported human-human games
      else { 
	st = P2Turn;
      }
    }
    // Only used when we supported human-human games
    else {
      (*btArray)[i] = TTTButton::Cross;
      updateButtons();
      s = checkBoard( btArray );
      st = P1Turn;
    }
    if ( s > 0 ) {                              // any winners yet?
      st = s == TTTButton::Circle ? P1Won : P2Won;
      emit finished();
    }                                           // draw ?
    else if ( s == -1){
      st = NobodyWon;
      emit finished();
    }
  }
}


// --------------------------------------------------------------------------
// TTTBoard::updateButtons()
//
// Updates all buttons that have changed state
//

void TTTBoard::updateButtons()
{
  for ( int i=0; i<nBoard*nBoard; i++ ) {
    if ( buttons->at(i)->type() != btArray->at(i) ){
      buttons->at(i)->setType( (TTTButton::Type)btArray->at(i) );
    }
    buttons->at(i)->setEnabled( (TTTButton::Type)btArray->at(i) == TTTButton::Blank );
  }
}


// --------------------------------------------------------------------------
// TTTBoard::checkBoard()
//
// Checks if one of the players won the game, works for any board size.
//
// Returns:
//  - TTTButton::Cross  if the player with X buttons won
//  - TTTButton::Circle if the player with O buttons won
//  - Zero (0) if there is no winner yet
//

int TTTBoard::checkBoard( TTTArray *a )
{
  int  t = 0;
  int  row, col;
  bool won = FALSE;
  for ( row=0; row<nBoard && !won; row++ ) {  // check horizontal
    t = a->at(row*nBoard);
    if ( t == TTTButton::Blank )
      continue;
    col = 1;
    while ( col<nBoard && a->at(row*nBoard+col) == t )
      col++;
    if ( col == nBoard )
      won = TRUE;
  }
  for ( col=0; col<nBoard && !won; col++ ) {  // check vertical
    t = a->at(col);
    if ( t == TTTButton::Blank )
      continue;
    row = 1;
    while ( row<nBoard && a->at(row*nBoard+col) == t )
      row++;
    if ( row == nBoard )
      won = TRUE;
  }
  if ( !won ) {                               // check diagonal top left
    t = a->at(0);                           //   to bottom right
    if ( t != TTTButton::Blank ) {
      int i = 1;
      while ( i<nBoard && a->at(i*nBoard+i) == t )
	i++;
      if ( i == nBoard )
	won = TRUE;
    }
  }
  if ( !won ) {                               // check diagonal bottom left
    int j = nBoard-1;                       //   to top right
    int i = 0;
    t = a->at(i+j*nBoard);
    if ( t != TTTButton::Blank ) {
      i++; j--;
      while ( i<nBoard && a->at(i+j*nBoard) == t ) {
	i++; j--;
      }
      if ( i == nBoard )
	won = TRUE;
    }
  }
  if ( !won )  {                               // no winner
    t = 0;
    bool draw = true;
    for (int i=0; i < a->size(); ++i){
      if(a->at(i) == TTTButton::Blank){
	draw = false;
	break;
      }
    }
    if(draw) t = -1;
  }
  return t;
}


// --------------------------------------------------------------------------
// TTTBoard::computerMove()
//
// Puts a piece on the game board. Very, very simple.
//

void TTTBoard::computerMove()
{
  int numButtons = nBoard*nBoard;
  int *altv = new int[numButtons];            // buttons alternatives
  int altc = 0;
  int stopHuman = -1;
  TTTArray a(*btArray); // make a temp copy so we can explore our options
  int i;
  for ( i=0; i<numButtons; i++ ) {            // try all positions
    if ( a[i] != TTTButton::Blank )      // already a piece there
      continue;
    a[i] = TTTButton::Cross;             // test if computer wins
    if ( checkBoard(&a) == a[i]  ) {         // computer will win
      st = P2Won;
      stopHuman = -1;
      break;
    }
    a[i] = TTTButton::Circle;            // test if human wins
    if ( checkBoard(&a) == a[i]  ) {         // oops...
      stopHuman = i;                      // remember position
      a[i] = TTTButton::Blank;         // restore button
      continue;                           // computer still might win
    }
    a[i] = TTTButton::Blank;             // restore button
    altv[altc++] = i;                       // remember alternative
  }
  if ( stopHuman >= 0 )                       // must stop human from winning
    a[stopHuman] = TTTButton::Cross;
  else if ( i == numButtons ) {               // tried all alternatives
    if ( altc > 0 )                         // set random piece
      a[altv[rand()%(altc--)]] = TTTButton::Cross;
    if ( altc == 0 ) {                      // no more blanks
      st = NobodyWon;
      emit finished();
    }
  }
  *btArray = a;                               // update model
  delete[] altv;
}



