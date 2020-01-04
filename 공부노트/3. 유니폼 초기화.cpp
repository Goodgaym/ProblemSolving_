#include<iostream>	// ��� C++ 3.������ �ʱ�ȭ
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

typedef struct Car {
	int cost;
	int oil;
}Car;

class Book{
public:
	string name;
	int cost;

	Book(const string& name, int cost) : name(name), cost(cost){}
};

// �Լ� ���ϰ����� ���
vector<int> return_func(){
	return {1,2,3};
}

// �Լ� ���ڷ� ���
void parameter_func(vector<int> v){
	for(auto i : v) cout<<i<<" ";
	cout<<endl;
}

int main(){
	// 5�� �ʱ�ȭ
	int v1{5};
	printf("v1: %d \n",v1);

	// �迭 1,2,3 ���� �ʱ�ȭ
	int v2[]{1,2,3};
	printf("v2 [0]:%d [1]:%d [2]:%d\n",v2[0], v2[1], v2[2]);

	// vector Ŭ���� 1,2,3 ���� �ʱ�ȭ
	vector<int> v3{1,2,3};
	printf("v3 [0]:%d [1]:%d [2]:%d\n", v3[0], v3[1], v3[2]);

	// vector Ŭ���� pair�ʱ�ȭ {1, '1'}, {2, 'b'}
	vector<pair<int, string>> v4{{1, "1"}, {2,"b"}};
	printf("v4 [0]%d %s [1]%d %s \n", v4[0].first, v4[0].second.c_str(), v4[1].first, v4[1].second.c_str());

	// Ŭ���� �ʱ�ȭ
	Car car{50, 20};
	printf("Car cost[%d] oil[%d]\n", car.cost, car.oil);

	// vector Ŭ���� ���ø� Ŭ������ �ʱ�ȭ
	vector<Book> book{{"a", 100}, {"b", 200}};
	printf("Book [0](%s,%d) [1](%s,%d)\n", book[0].name.c_str(), book[0].cost, book[1].name.c_str(), book[1].cost);

	// �̸����� �ӽú��� �ʱ�ȭ
	vector<int> {1,2,3};

	// �����Ҵ�
	int * v = new int[3]{1,2,3};

	// �Լ� ���ϰ� �ʱ�ȭ�� ����
	vector<int> v = return_func();

	// �Լ� ���ڷ� ���
	parameter_func({1,2,3});

	return 0;
}