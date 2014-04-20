#include<iostream>

using namespace std;

void read(int[],int&);
void display(int[],int);       
void insertionSort(int[],int);
void swap(int&,int&);

int main()                      
{
  int a[10],b=0;
  read(a,b);
  cout<<endl<<"Unsorted array:";
  display(a,b);
  insertionSort(a,b);
  cout<<endl<<endl<<"Sorted array: ";
  display(a,b);
  return 0;
}                       

void read(int a[],int &b)           
{
  cout<<"NO OF ARRAY ELEMENTS:\n";
  cin>>b;
  cout<<"ENTER ARRAY:\n"<<endl;
  for(int i=0;i<b;i++)
    cin>>a[i];
}

void display(int a[],int b)          
{
  for(int i=0;i<b;i++)
  {
    cout<<"\t"<<a[i];
  }
  cout<<"\n";
}


void swap(int &x,int &y)            
{
  int temp=x;
  x=y;
  y=temp;
}


void insertionSort(int a[],int b)        
{
  for(int i=1;i<b;i++)
  {
    for(int j=i;j>0;j--)
    {
      if(a[j]<a[j-1])
      {
        swap(a[j],a[j-1]);
      }
    }
    //cout<<"\nPass "<<i<<":";
    display(a,b);
  }
}
