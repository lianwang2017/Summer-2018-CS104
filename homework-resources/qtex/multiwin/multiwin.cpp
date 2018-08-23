#include <QVBoxLayout>
#include "multiwin.h"

Multiwin::Multiwin() : QWidget(NULL)
{
  /* Allocate widgets of main window */
  mainButton = new QPushButton("&Open OtherWin");

  /* Allocate widgets of other window */
  otherWin = new QWidget;
  otherButton = new QPushButton("&Close");

  /* Setup layout of main window */
  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addWidget(mainButton);
  setLayout(mainLayout);

  /* Setup layout of other window */
  QVBoxLayout* otherLayout = new QVBoxLayout;
  otherLayout->addWidget(otherButton);
  otherWin->setLayout(otherLayout);

  /* Connect signals and slots */
  QObject::connect(mainButton, SIGNAL(clicked()), this, SLOT(mainButtonClicked()));
  QObject::connect(otherButton, SIGNAL(clicked()), this, SLOT(otherButtonClicked()));
}

void Multiwin::mainButtonClicked()
{
  otherWin->show();
}
void Multiwin::otherButtonClicked()
{
  otherWin->hide();
}
