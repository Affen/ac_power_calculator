#include "window.h"
#include <QPushButton>
#include <QLabel>
#include <math.h>
#include <QLineEdit>

double PI = 3.14159265;

QString valcur="0";
QString  valvol="0";
QString valimp="0";
QString valpow="0";
QString valpowl="0";
QString valpowp="0";
QString valvos="0";
QString valjos="0";
QString valtos="0";
QString valios="0";
QString ind="ind";
QString kap="kap";
QString teksti="nolla";
Window::Window(QWidget *parent) :
 QWidget(parent){


    setWindowTitle("Teholaskuri");


 // Set size of the window
    setFixedSize(850, 275);


    teho = new QLineEdit (this);
     teho->setGeometry(650,50,50,25);
     teho->setText(valpow);

     label=new QLabel("Näennäisteho (S)",this);
     label->setGeometry(560,50,100,25);

     label =new QLabel("VA",this);
     label->setGeometry(705,50,20,25);

     tos = new QLineEdit (this);
      tos->setGeometry(750,50,50,25);
     tos->setText(valtos);

     label = new QLabel("∠",this);
            label->setGeometry(730,50,20,25);

            label=new QLabel("°",this);
            label->setGeometry(805,50,10,25);


     lteho = new QLineEdit (this);
      lteho->setGeometry(650,100,50,25);
      lteho->setText(valpowl);

      label =new QLabel("Loisteho (Q)",this);
      label->setGeometry(580,100,100,25);

      label =new QLabel("VAR",this);
      label->setGeometry(705,100,50,25);


      pteho = new QLineEdit (this);
       pteho->setGeometry(650,150,50,25);
       pteho->setText(valpowp);

       label =new QLabel("Pätöteho (P)",this);
       label->setGeometry(580,150,100,25);

       label =new QLabel("W",this);
       label->setGeometry(705,150,50,25);


     jannite = new QLineEdit (this);
      jannite->setGeometry(265,50,50,25);
      jannite->setText (valvol);



      label=new QLabel("Jännite (U)",this);
         label->setGeometry(205,50,60,25);

         label =new QLabel("V",this);
         label->setGeometry(320,50,20,25);

         jos = new QLineEdit (this);
          jos->setGeometry(360,50,50,25);
         jos->setText(valjos);

         label = new QLabel("∠",this);
                label->setGeometry(340,50,20,25);

                label=new QLabel("°",this);
                label->setGeometry(415,50,50,25);


      virta = new QLineEdit (this);
       virta->setGeometry(265,100,50,25);
        virta->setText(valcur);


        label=new QLabel("Virta (I)",this);
        label->setGeometry(215,100,50,25);

        label =new QLabel("A",this);
        label->setGeometry(320,100,50,25);


        vos = new QLineEdit (this);
         vos->setGeometry(360,100,50,25);
        vos->setText(valvos);

        label = new QLabel("∠",this);
               label->setGeometry(340,100,20,25);

               label=new QLabel("°",this);
               label->setGeometry(415,100,50,25);

               imped = new QLineEdit (this);
                imped->setGeometry(265,150,50,25);
                 imped->setText(valcur);


                 label=new QLabel("Impedanssi (Z)",this);
                 label->setGeometry(190,150,80,25);

                 label =new QLabel("Ω",this);
                 label->setGeometry(320,150,50,25);

                 ios = new QLineEdit (this);
                  ios->setGeometry(360,150,50,25);
                 ios->setText(valios);

                 label = new QLabel("∠",this);
                        label->setGeometry(340,150,20,25);

                        label=new QLabel("°",this);
                        label->setGeometry(415,150,50,25);

               label1 = new QLabel(this); // kapasitiivista vai induktiivistä
                label1->setGeometry(730,100,20,25);




 QFont font("Courier",10);
 // Create and position the button
 m_button = new QPushButton("Laske!", this);
 m_button->setGeometry(230, 225, 120, 30);
 m_button->setCheckable(true);
 m_button->setFont(font);

 reset= new QPushButton ("Nollaa",this);
        reset->setGeometry(370, 225, 120, 30);
         reset->setCheckable(true);
         reset->setFont(font);
connect(reset,SIGNAL(clicked(bool)),this,SLOT(resetButtonClicked(bool)));

connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));


}

void Window::resetButtonClicked(bool tsekkaus){
    if(tsekkaus){
        tsekkaus=0;
        emit reset->click();
        valpow="0";
        valcur="0";
        valimp="0";
        valvol="0";
        valtos="0";
        valvos="0";
        valjos="0";
        valios="0";
        valpowp="0";
        valpowl="0";

        teho->setText(valpow);
        pteho->setText(valpowp);
        lteho->setText(valpowl);
        jannite->setText(valvol);
        virta->setText(valcur);
        imped->setText(valimp);
        tos->setText(valtos);
        vos->setText(valvos);
        jos->setText(valjos);
        label1->clear();
    }
}

void Window::slotButtonClicked(bool checked)
{
 if (checked) {


     emit m_button->click();
     checked=0;





    valcur= virta-> text();
    valvol= jannite->text();
    valimp= imped->text();
    valpow=teho->text();
    valvos=vos->text();
    valtos=tos->text();
    valjos=jos->text();
    valios=ios->text();
    valpowl=lteho->text();
    valpowp=pteho->text();

    double viros=valvos.toDouble();
    double janos=valjos.toDouble();
    double tehos=valtos.toDouble();
    double impos=valios.toDouble();
     double cur = valcur.toDouble();
    double vol=valvol.toDouble();
    double imp=valimp.toDouble();
    double pow=valpow.toDouble();
    double powl=valpowl.toDouble();
    double powp=valpowp.toDouble();



    if(pow==0 ){
      label1->clear();
    pow=0.5*cur*vol;
    valpow=pow;
    teho->setText(QString::number(pow));
    viros=viros*-1;
    tehos=janos+viros;
    tos->setText(QString::number(tehos));}

    else if (cur==0){
        viros=tehos-janos;
        viros=viros*-1;
        cur=pow/(0.5*vol);
       valcur=cur;

        virta->setText(QString::number(cur));
        vos->setText(QString::number(viros));
    }

    else if (vol==0){
            viros=viros*-1;
            janos=tehos-viros;
           vol=pow/(0.5*cur);
           valvol=vol;
           jos->setText(QString::number(janos));
          jannite->setText(QString::number(vol));
       }
    else if (imp==0){
        if (tehos!=0){
            impos=tehos;}
        else {viros=impos;}}
    powp=pow*(cos(tehos* PI / 180.0));
    pteho->setText(QString::number(fabsf(powp)));
    powl=pow*(sin(tehos*PI/180.0));
     lteho->setText(QString::number(fabsf(powl)));
    if(powl<0 && pow!=0){

    label1->setText("kap");
}




               if(powl>0 && pow!=0){

                   label1->setText("ind");}}
label1->show();




   // else if (vol==0){
   //     vol=pow/cur;
      //  valvol=vol;
      //  jannite->setText(QString::number(vol));
   // }
 }


