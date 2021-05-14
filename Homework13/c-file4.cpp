#include<iostream>
using namespace std;

class complex{
  public:
    complex(){
      Re=0;
      Im=0;
      cout<<"无参构造函数被执行"<<endl;
    }
    complex(double a, double b){
      Re=a;
      Im=b;
      cout<<"有参构造函数被执行"<<endl;
    }
    double Re, Im;
    friend void Add(complex&, complex&, complex&);
    void Disp(){
      cout<<Re<<"+"<<Im<<"i"<<endl;
    }
};

void Add(complex& a, complex& b, complex& c){
  c.Re=a.Re+b.Re;
  c.Im=a.Im+b.Im;
}

int main(){
  complex a(1,2);
  complex b;
  b.Re=3.1;
  b.Im=2.5;
  complex c;
  Add(a,b,c);
  c.Disp();
  return 0;
}
