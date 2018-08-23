#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include "form.h"

using namespace std;

MyForm::MyForm(QWidget* parent) : QWidget(parent)
{
  /* Allocate widgets */
  saveButton = new QPushButton("&Save");
  quitButton = new QPushButton("&Quit");

  nameText = new QLineEdit;
  ageText = new QLineEdit;
  
  /* Setup layout */
  QFormLayout* fLayout = new QFormLayout;
  fLayout->addRow("&Name:", nameText);
  fLayout->addRow("&Age:", ageText);

  
  QHBoxLayout* botRow = new QHBoxLayout;
  botRow->addWidget(saveButton);
  botRow->addWidget(quitButton);

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(fLayout);
  mainLayout->addLayout(botRow);

  setLayout(mainLayout);

  /* Connect signals/slots */
  connect(saveButton, SIGNAL(clicked()),
	  this,       SLOT(saveClicked()));
  connect(quitButton, SIGNAL(clicked()),
	  this,       SLOT(quitClicked()));

}

void MyForm::saveClicked()
{
  string name = nameText->text().toStdString();
  if(name != ""){
    ofstream ofile("data.txt");
    ofile << name  << " is "
	  << ageText->text().toStdString()
	  << " years old." << endl;
    ofile.close();
    
  }
  else {
    nameText->setText(QString("Please enter your name"));
  }
}

void MyForm::quitClicked()
{
  cout << "Bye Bye!" << endl;
  close();
}

void MyForm::mousePressEvent(QMouseEvent* ev)
{
  cout << "Press" << endl;
}
