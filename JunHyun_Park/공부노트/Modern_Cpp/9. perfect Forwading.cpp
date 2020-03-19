#include<iostream> // 9. �Ϻ��� ����
#include<vector>
using namespace std;

// L-Value Reference�� ���ڷ� �޴� �Լ��� R-Value�� �Ѱ����� �ذ��ϴ� ���.
// Universal Reference : Ÿ�� �߷��� ���ڷ� ������ ������/������ ������ �� ���� �ִ�.

class Class{};
int b;
// R-Value Reference;
Class&& c = Class();

// Universal Reference
auto&& a = b;

// R-Value Reference;
void func(Class&& c);

// R-Value Reference;
template<typename T>
vector<T> func (vector<T>&& v);

// Universal Reference
template<typename T>
void func(T&& t);

/* C++ ���� ��Ģ
    1. non const lvalue reference�� lvalue�� ���� ����
    2. const lvalue reference�� lvalue / rvalue �� �� ���� ����
    3. rvalue reference�� rvalue�� �������� (C++11���� ��� ����)
*/

// �����ε��� ���� ������������ ���ϴ´�� �������� �ʴ� ��찡 �ִ�.

void func(int& i){
    cout<<"This is L-Value Reference"<<endl;
}

void func(int&& i){
    cout<<"This is R-Value Reference"<<endl;
}

// forward Ű���带 ������� ������ L-Value�� �ν��Ѵ�.
template<typename T>
void proc(T&& t){
    func(forward<T>(t));
}

int main(){
    int a = 1;
    proc(a);
    proc(1);
}
