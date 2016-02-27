#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class QLineEdit;
class QLabel;
class Window : public QWidget


{
 Q_OBJECT
public:
 explicit Window(QWidget *parent = 0);


private slots:
 void slotButtonClicked(bool checked);
 void resetButtonClicked(bool tsekkaus);
private:
 QPushButton *m_button;
 QPushButton *reset;
 QLineEdit *virta;
 QLineEdit *jannite;
 QLineEdit *teho;
 QLineEdit *lteho;
 QLineEdit *pteho;
 QLineEdit *tos;
 QLineEdit *vos;
 QLineEdit *jos;
 QLineEdit *imped;
 QLabel   *label;
 QLabel    *label1;
 QLabel    *label2;
 QPixmap    *bikini;

};

#endif // WINDOW_H
