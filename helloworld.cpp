#include <QApplication>
#include "window.h"
#include <QLabel>
#include <QPixmap>
#include <QlineEdit>
#include <Qtextedit>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);
  Window window;


 QPixmap bikini;
 bikini.load("C:\\Users\\affen\\Pictures\\bikini.jpg");
 QLabel label(&window);
 label.setPixmap(bikini);




 window.show();

 return app.exec();
}
