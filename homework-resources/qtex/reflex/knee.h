#ifndef KNEE_H
#define KNEE_H

#include <QObject>
#include <iostream>

class Knee : public QObject
{
  Q_OBJECT

private:
  int _which;
public:
  Knee(int which) : _which(which) { }
  ~Knee() {}

public slots:
  void reflex(bool howHard)
  {
    if(howHard){
      std::cout << "Knee " << _which << ": Big Kick" << std::endl;
    }
    else {
      std::cout << "Knee " << _which << ": Small Kick" << std::endl;
    }
  }
};
#endif
