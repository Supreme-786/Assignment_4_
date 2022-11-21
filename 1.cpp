#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>


using namespace std;

/*

Topics Covered - 
    1. Function
        a) Inline function
    2. Class and object
        a) Static functions
        b) access Specifier
        c) Friend Function
        d) Friend Class
        e) Function Overloading
    3. Constructors and destructors
        a) Default Costructor
        b) Parameterized constructor
        c) Copy constructor
        d) Dynamic Constructors
    4. Inheritance
        a) Virtual Function
        b) Function Overriding
    5. Polymorphism
        a) Operator Overloading
        b) virtual function
    6. Operator overloadings
    7. File Handling
    8. Exception Handling
    9. Template Classes
   10. Abstraction
   11. Encapsulation
   12. Binding

*/


class clsobj {
   private:
   int pvt = 25;
   public:
   int pub = 15;
   static int stc;
   clsobj() {
        stc++;
   }
   void dis(){
    cout << "Privte member - " << pvt <<endl;
   }
   friend void fnddis(clsobj);
    friend class fndcls;
};

class fndcls{
    public:
    int x = 1;
    int y = 2;
        void calc(){
            cout<<"calculation Without Argument "<<x+y<<endl;
        }
        void calc(int a){
            cout<<"calculation With 1 Argument "<<a+y<<endl;
        }
        void calc(int a,int b){
            cout<<"calculation With 2 Argument "<<a+b<<endl;
        }
        void dis(clsobj a){
            a.dis();
        }

};


class base{
    public :
        int a = 10;
};

class inht: public base{
    public :
    int b = 15;
    void dis(){
            cout<<"Variable from Base class is "<<a<<endl;
            cout<<"Variable from inherited class is "<<b<<endl;
        }
};


class cnsdes{
    public:
    int *num;
    cnsdes(void){
        cout<<"1) Default Costructor"<<endl;
        cout <<"Constructor called"<<endl;
    }
    cnsdes(int z,int v){
        cout<<"2) Parameterized constructor"<<endl;
        cout <<"Constructor called with parameter "<<z<<"  "<<v<<endl;
    }
	cnsdes(cnsdes&obj){
        cout<<"3) Copy Constructors"<<endl;
	}
	cnsdes(int x){
        cout<<"4) Dynamic Constructor"<<endl;
		num= new int;
		*num=x;
	}    
};


class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0)
     {real = r;
    imag = i;
    }
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() 
    { 
        cout<<"      1) Operator Overloading"<<endl;
        cout<<"The Sum is -  ";
        cout << real << " + i" << imag << '\n'; 
    }
};


class bas {
public:
    virtual void print()
    {
        cout << "This is from Base Class\n";
    }
};
  
class derived : public bas {
public:
    void print()
    {
        cout << "This is from Virtual Class\n";
    }
};


int clsobj::stc = 0;
void fnddis(clsobj a){
    a.pvt = 20;
    a.dis();
}



inline void infnc(){
    cout<<"This is an inline function"<<endl;
}

template <typename T> T Max(T x, T y)
{
    return (x > y) ? x : y;
}





int main(void){
    clsobj a;
    clsobj a1;
    clsobj a2;
    fndcls f;
    inht i;
    Complex c1(10, 5), c2(2, 4),c3;
    bas *bptr;
    derived d;
    string s;
    ofstream f1("1199.txt");
    ifstream f2("1199.txt");
    int x = -1,c,ch;









menu:
    cout<<"  1. Function"<<endl;
    cout<<"      1) Inline function"<<endl;
    cout<<"  2. Class and object"<<endl;
    cout<<"      1) Static functions"<<endl;
    cout<<"      2) access Specifier"<<endl;
    cout<<"      3) Friend Function"<<endl;
    cout<<"      4) Friend Class"<<endl;
    cout<<"      5) Function Overloading"<<endl;
    cout<<"  3. Constructors and destructors"<<endl;
    cout<<"  4. Inheritance"<<endl;
    cout<<"  5. Polymorphism"<<endl;
    cout<<"  6. File Handling"<<endl;
    cout<<"  7. Exception Handling"<<endl;
    cout<<"  8. Template Classes"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter your Choice";
    cin>>c;


switch (c)
{
case 1:
    cout<<" 1. Function (inline)"<<endl;
    infnc();
    goto menu;
    break;
case 2:
    menu2:
        cout<<" 2. Class and Object"<<endl;
        cout<<"      1) Static functions"<<endl;
        cout<<"      2) access Specifier"<<endl;
        cout<<"      3) Friend Function"<<endl;
        cout<<"      4) Friend Class"<<endl;
        cout<<"      5) Function Overloading"<<endl;
        cout<<"      6) Main Menu"<<endl;
        cout<<"Enter your Choice";
        cin>>ch;
    switch(ch){
        case 1:
            cout<<"1) Static functions"<<endl;
            cout << "Total objects created = " << clsobj::stc << endl;
            goto menu2;
            break;
          case 2:
            cout<<"2) access Specifier"<<endl;
            cout<<"public member - "<<a.pub<<endl;
            a.dis();
            goto menu2;
            break;
        case 3:
            cout<<"3) Friend Function"<<endl;
            fnddis(a);
            goto menu2;
            break;
        case 4:
            cout<<"4) Friend Class"<<endl;
            f.dis(a);
            goto menu2;
            break;
        case 5:
            f.calc();
            f.calc(5);
            f.calc(5,9);
            goto menu2;
            break;
        case 6:
            goto menu;            
    }

case 4:
    cout<<"  4. Inheritance"<<endl;
    i.dis();
    goto menu;
    break;
    


case 5:
    cout<<"  5. Polymorphism"<<endl;
    c3 = c1 + c2;
    c3.print();
    cout<<" Virtual Function"<<endl;
    bptr = &d;
    bptr->print();
    goto menu;
    break;

case 6:
    cout<<"  6. File Handling"<<endl;
    f1 << "Thank you for your patience";
    f1.close();
    while (getline (f2, s)) {
        cout << s;
    }
    f2.close();
    goto menu;
    break;


case 7:
    cout<<"  7. Exception Handling"<<endl;
    cout << "Before try \n";
   try {
      cout << "Inside try x is "<<x<<endl;
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught  x is "<<x<<endl;
   }
   goto menu;
    break;

case 8:
    cout<<"  8. Template class"<<endl;
    cout << Max<int>(3, 7) << endl; 
    cout << Max<double>(3.0, 7.0)<< endl;
    cout << Max<char>('g', 'e')<< endl;
    goto menu;
    break;


case 3:
    cout<<"  3. Constructors"<<endl;
		 cnsdes cons;	
		 cnsdes consd(1199,995);
		 cnsdes con(cons);
		 cnsdes cn(254);
         goto menu;
    break;



}







    return 0;
}