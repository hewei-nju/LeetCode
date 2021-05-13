#include <iostream>
#include <string>

class Father {
protected:
    int a;
private:
    char b;
public:
    std::string c;
    Father(int a, char b, const std::string &c): a(a), b(b), c(c) { }
    virtual void print() { std::cout << a << " " << b << " " << c << std::endl; }
    Father copyFromSon(const Son &son) { return Father(son.a, son.b, son.c); }
    Father copyFromFather(const Father &father) { return Father(father.a, father.b, father.c); }
};

class Son : public Father {
public:
    Son(int a, char b, const std::string &c): Father(a, b, c) { }
    void print() override{ std::cout << a << " " << c << std::endl; } // 不能访问b
    void print(const Son &son) { std::cout << son.a << " " << son.c << std::endl; }  // 访问不到b
    // void print(const Father &father) { std::cout << father.a << " " << father.c << std::endl; } // 访问不到a, b
};




int main()
{
    Father father(1, 'b', "what");
    Son son(2, 's', "what");
    // son.print(father);
    std::cout << sizeof(father) << std::endl;
    std::cout << sizeof(son) << std::endl;
}


// class A {
// private:
//     std::string nickName;

// protected:
//     int id;
    
// public:
//     A(int id, const std::string &nickName): id(id) nickName(nickName) { }
//     void setID(int id) { this->id = id; }
//     virtual void printID() { std::cout << "ID: " << id << std::endl; }
// };

// class B : public A {

// private:
//     std::string name;
// public:
//     B(int id, const std::string &nickName, const std::string &name): A(id, nickName), name(name) { }
//     void printID() { std::cout << name << ": " << id << std::endl; }
// };

// class C;

// class D : public C{

// };

// int main(
//     int argc,
//     char *argv[]
// )
// {
//     B b(23, "ming", "xiaoming");
//     b.printID();

//     return 0;
// }