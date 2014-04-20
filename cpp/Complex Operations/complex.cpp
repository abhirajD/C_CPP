#include<iostream>
#include<math.h>

using namespace std;

class complx
{
  float real,img;
public:
  void disp();
  void read();
  void add(complx,complx);
  void sub(complx,complx);
  void mul(complx,complx);
  complx conj();
  void div(complx);
};
complx a,b,c;

void complx::disp()
{
  cout<<real<<"+("<<img<<")i"<<endl;
}

void complx::read()
{
 cout<<"complex no: real part=";
 cin>>real;
 cout<<"imaginary part=";
 cin>>img;
}


void complx::add(complx a, complx b)
{
 real=a.real+b.real;
 img=a.img+b.img;
 c.disp();
}

void complx::  sub(complx a, complx b)
{ complx c;
 c.real=a.real-b.real;
 c.img=a.img-b.img;
 c.disp();
}

void  complx::  mul(complx a, complx b)
{
 real=a.real*b.real-a.img*b.img;
 img=a.img*b.real+a.real*b.img;
}

complx complx:: conj()
{ complx b;
  b.real=real;
  b.img=-img;
  return(b);
}

void complx:: div(complx b)
{
 complx c;
 c.mul(a,b.conj());
 float x=pow(b.real,2)+pow(b.img,2);
 c.real=c.real/x;
 c.img=c.img/x;
 c.disp();
}

int main()
{ 
  a.read();
  b.read();
  cout<<endl<<"Entered numbers: "<<endl;
  a.disp();
  b.disp();
  cout<<endl<<"Addition:"<<endl;
  c.add(a,b);
  cout<<endl<<"Subtraction:"<<endl;
  c.sub(a,b);
  cout<<endl<<"Conjugate:";
  a.disp();
  cout<<" is ";
  a.conj().disp();
  cout<<endl<<"Multiplication:"<<endl;
  c.mul(a,b);
  c.disp();
  cout<<endl<<"Division:"<<endl;
  a.div(b);
  return 0;
}
