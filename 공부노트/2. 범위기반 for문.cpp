#include<iostream>	// 2. ������� for��
#include<cstdio>
#include<vector>
using namespace std;

// ������� for���� foreach ���� ����ϴ�.
// Ŭ������ ������� for ������ ����ϱ� ���ؼ��� begin, end �Լ��� �����ؾ��Ѵ�.
int main(){
	vector<int> v{1,2,3}; 

	// ���� ���
	for(vector<int>::iterator i=v.begin(); i != v.end; i++)
		printf("%d ", i);
	cout<<endl;

	// ������� for��
	for(auto i : v)
		printf("%d", i);
	cout<<endl;

	return 0;
}