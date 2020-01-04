#include<iostream>	// 4. decltype Ű����
#include<cstdio>
#include<vector>
#include<typeinfo>
using namespace std;

// decleared type(����� ����)�� ���Ӹ� 
// �־��� ǥ������ Ÿ���� �˷��ش�.
// auto : ���� �����ϴ� Ÿ���� �߷�
// decltype : �����κ��� Ÿ���� �߷�

// �������� auto�� �� �� ���ϰ� �߷�(Cpp11)
auto func1(int x, int y) -> decltype(x+y){
	return x+y;
}

template<typename A, typename B>
auto func2(A a, B b) -> decltype(a+b){
	return a+b;
}

template<typename A, typename B>
auto func3(A a, B b){	// Cpp14 ���ʹ� ��������
	return a+b;
}

int main(){
	auto a = 1;
	auto b = 2.5;
	decltype(a+b) c = 3; // a+b�� Ÿ������ ����. double��

	// c ������ Ÿ�� ���
	cout<<"c : "<< c <<" and type is " << typeid(c).name()<<endl;
	
	// �Լ� ȣ�� �� ������ Ÿ�� ���
	cout<<"a+b : "<< a+b <<" and type is " << typeid(func3(a,b)).name()<<endl;
	return 0;
}