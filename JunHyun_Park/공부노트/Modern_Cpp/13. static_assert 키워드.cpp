#include<iostream> // 13. static_assert Ű����

// C��� ���ǽ� assert(���ǽ�);
// assert �Լ��� ���ǽ� -> �� : �н� / ���� : �����޼���
// ��Ÿ�ӽ� �����Ǿ� ������ �ÿ��� ������ �ȵȴ�.
// �����Ͻ� �����ϴ°��� static_assert Ű����
// ���ǽ��� ������ �� ������ ������ ���.

int main(){

    // ����� �� �� �ִ�. ������ �� �� ����.
    static int n = 3;
    static_assert(1, "error");

    return 0;
}