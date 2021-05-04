#include <iostream>
#include <string>
using namespace std;

class CString {   
    char *p; 
    int size;
public:
   CString(int x):size(x),p(new char[size]){}    
};



// class A {     
//     int x;
//     const int y;
//     int& z;
// 	public:
//         A(): y(1),z(x), x(0)  {  x = 100; }
//         void print() {
//             cout << x << " " << y << " " << z << endl;
//         }
// };

class A {
    int x;
    public:
        A() { 
            cout << x << endl;
            x = 10;
        }
};

int main()
{
    // CString str= CString(5);
    // int a;
    // cout << a << endl;
    // A a = A();
    // a.print();
    A a = A();
}


// class A{
//     public:
//         A();
//         A(int i);
//         A(char *p);
// };


// int main()
// {
//     A a[4];

//     return 0;
// }



// class Test{
// private:
//     int year;
//     int month;
//     int day;

// public:
//     std::string getDate() { 
//         return to_string(this->year) + "-" + to_string(this->month) + "-" + to_string(this->day);
//     }
// };

// int main()
// {
//     Test t;
//     cout << t.getDate() << flush;

//     // retunr 0;
// }