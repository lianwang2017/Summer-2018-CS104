#ifndef HAMMER_H
#define HAMMER_H
#include <QObject>

class Hammer : public QObject
{
  Q_OBJECT
public:
  Hammer() : hardHit(false) { }
  ~Hammer() {}
  void setHardHit(bool val) { hardHit = val; emit hit(val); }
signals:
  void hit(bool howHard);
private:
  bool hardHit;
};

#endif
