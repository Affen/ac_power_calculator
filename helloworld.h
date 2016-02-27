#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QMainWindow>

namespace Ui {
class Helloworld;
}

class Helloworld : public QMainWindow
{
    Q_OBJECT

public:
    explicit Helloworld(QWidget *parent = 0);
    ~Helloworld();

private:
    Ui::Helloworld *ui;
};

#endif // HELLOWORLD_H
