#include <iostream>
#include <QObject>
#include "hammer.h"
#include "knee.h"

int main(int argc, char* argv[])
{
  Hammer h;
  Knee k1(1);

  QObject::connect(&h, SIGNAL(hit(bool)), &k1, SLOT(reflex(bool)));
  h.setHardHit(true);
  h.setHardHit(false);
  return 0;
}
