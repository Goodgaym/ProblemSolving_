#include<iostream>
using namespace std;

// R-value Reference(������ ����)
/* 
        ������(L-Value) ������(R-Value)
    int a              =3
    
    �������� ǥ������ ����Ǹ� ���̻� �������� �ʰԵ�. (�ӽð�ü)
    ũ�Ⱑ ū �ڷ����� ��쿡 ���縦 �ݺ������� �Ұ�� ������尡 �߻��� �� �ִ�.
    ������ ������ �������� �ı����� �ʰ� �������� �״�� ������ �� �ְ� �Ѵ�.
    �׷��Ƿ� ũ�Ⱑ ū �ڷ����� �����Ҷ� ������ ������ ����ϸ� ������带 ���� �� �ִ�.
    
*/
template<typename T>
class X{
    public:
    X& operator=(T&& rhs){   // �������� ������
        this->value = rhs;
        return *this;
    }
    
    T getValue(){return this->value;};
    private:
    T value;
};

int main(){
    int a = 5;      // L = R
    int b = a;      // L = L
    int c = a++;    // L = R
    int d = ++a;    // L = L
    int& e = b;     // L = L
    int f = b + c;  // L = R
    int* g = &a;    // L = R

    X<int> x;
    x = 5;  // ������ ������ ���� 5�� �����ǰ� �� ���� ����
    
    cout<< x.getValue() <<endl; 
    return 0;
}