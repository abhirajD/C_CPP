/*OPERATOR OVERLODING*/

#include<iostream>
#include<math.h>

using namespace std;

class complx
{
	float real,img;
public:
	void disp();
	void read();
	void operator +(complx);
	void operator -(complx);
	complx operator *(complx);
	complx conj();
	void operator /(complx);
};

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


void complx::operator +(complx b)
{   complx c;
	c.real=real+b.real;
	c.img=img+b.img;
	c.disp();
}

void complx:: operator -(complx b)
{ complx c;
	c.real=real-b.real;
	c.img=img-b.img;
	c.disp();
}

complx  complx:: operator *(complx b)
{complx c;
	c.real=real*b.real-img*b.img;
	c.img=img*b.real+real*b.img;
	return(c);
}

complx complx:: conj()
{ complx b;
	b.real=real;
	b.img=-img;
	return(b);
}

void complx:: operator /(complx b)
{
	complx c;
	c=*this*(b.conj());
	float x=pow(b.real,2)+pow(b.img,2);
	c.real=c.real/x;
	c.img=c.img/x;
	c.disp();
}

int main()
{ 
	complx a,b;
	a.read();
	b.read();
	cout<<endl<<"entered numbers: "<<endl;
	a.disp();
	b.disp();
	cout<<endl<<"addition is"<<endl;
	a+b;
	cout<<endl<<"subtraction is"<<endl;
	a-b;
	cout<<endl<<"conjugate of ";
	a.disp();
	cout<<" is ";
	a.conj().disp();
	cout<<endl<<"multiplication is"<<endl;
	(a*b).disp();
	cout<<endl<<"division is"<<endl;
	a/b;
	return 0;
}

