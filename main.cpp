#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
string mystr;
int myint;
int expo;
int input();

int main()
{
    cout << "Anna numero: ";
    input();
    for(int count=0;count<=5;count++){
    cout <<endl<<myint<<"^"<<expo<<"="<<pow(myint,expo)<<endl;

    expo++;}
    cout<<myint<<endl;
    return 0;
}


int input(){
    getline (cin,mystr);
    stringstream (mystr)>>myint;
    return 0;}
