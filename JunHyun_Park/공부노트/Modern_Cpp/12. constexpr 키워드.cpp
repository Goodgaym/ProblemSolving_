#include<iostream> // 12. constexpr Ű����
using namespace std;
// const Ű����� constexpr Ű������ ���� : ���� �߻� �ñ�
// const : ���� �ʱ�ȭ�� ��Ÿ�ӱ��� ������ �ʱ�ȭ ���� ����
// constexpr : ������ Ÿ�ӿ� ������ �ʱ�ȭ�� �̷������ ��

// constexpr ������ �ݵ�� ��������� �ʱ�ȭ �Ǿ�� ��

// constexpr �Լ��� ������ Ÿ�ӿ� ���� ���� ����� �� �ִٸ� ����
// �׷��� �ʴٸ� �Ϲ����� �Լ�ó�� ��Ÿ�ӽ� ���ϰ� ����

constexpr int func(int n){
    return n*n;
}

// constexpr �Լ��� �������
// 1. �����Ŀ� ��� ����
// 2. ���ڿ� constexpr�� ����� �� ����
// 3. �����Լ��� ����� �� ����
// (C++14���� ������ �͵�)
// 4. ���������� ����� �� ���� 
// 5. ���������� ����� �� ����
// 6. return ������ single state ���߸� ��(���׿����� ��밡��)

int main(){
    constexpr int a = 1;
    constexpr int b = {1}; 
    //constexpr int c; error
    int d = 1;
    //constexpr int e = d + 2; error
    //constexpr int f = time(NULL); error

    int n;
    cin >> n;
    cout << func(n) <<endl; // ��Ÿ��
    cout << func(1) <<endl; // ������
    return 0;
}