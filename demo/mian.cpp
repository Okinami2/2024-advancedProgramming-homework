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
// �� A
class A {
public:
    void displayB(B&);  // ���� B ��ĳ�Ա����Ϊ��Ԫ
};
void A::displayB(B& objB) {
    std::cout << "B's private member b: " << objB.b << std::endl;
}

int main() {
    A objA;
    B objB;

    objB.setB(10);  // ���� B ���˽�г�Ա b Ϊ 10
    objA.displayB(objB);  // ���� A �����Ԫ���������� B ���˽�г�Ա b

    return 0;
}