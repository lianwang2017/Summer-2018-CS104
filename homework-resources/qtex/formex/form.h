#ifndef MYFORM_H
#define MYFORM_H
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>


class MyForm : public QWidget
{
  Q_OBJECT

 public:
  MyForm(QWidget* parent = NULL);

  // Help define initial size
  QSize sizeHint() const { return QSize( 300, 100 ); }
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 200, 150 ); }

 private slots:
  void saveClicked();
  void quitClicked();
 protected:
  void mousePressEvent(QMouseEvent* ev);
 private:

  QLineEdit* nameText;
  QLineEdit* ageText;
  QPushButton* saveButton;
  QPushButton* quitButton;
  

};

#endif
