#include <iostream>

class A;
class B {
private:
    int b;
    friend void A::displayB(B&);
public:
    B() : b(0) {}

    void setB(int value) {
        b = value;
    }

    int getB() {
        return b;
    }
};
// 类 A
class A {
public:
    void displayB(B&);  // 声明 B 类的成员函数为友元
};
void A::displayB(B& objB) {
    std::cout << "B's private member b: " << objB.b << std::endl;
}

int main() {
    A objA;
    B objB;

    objB.setB(10);  // 设置 B 类的私有成员 b 为 10
    objA.displayB(objB);  // 调用 A 类的友元函数来访问 B 类的私有成员 b

    return 0;
}