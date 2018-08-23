#include <QApplication>
#include "multiwin.h"

int main(int argc, char* argv[])
{

  QApplication app(argc, argv);
  Multiwin win;
  win.show();
  return app.exec();
}
