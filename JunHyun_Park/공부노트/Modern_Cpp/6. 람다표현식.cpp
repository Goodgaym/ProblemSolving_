#include<iostream> // 6. ����ǥ����
#include<functional>
using namespace std;

// �̸����� �Լ��� �Ҹ�.
// �ڵ��� ���������� �ڵ��� ������ ���
// �� �� ����ϰ� ������� �ʴ� �Լ��� �ڵ� ��ü�� ���� �������� ������
// �̶� �ش� ������ ������ ���� �Լ��� ����ϸ� ���ϰ� ������ ���
// ���� STL�� �˰����� �� �����ϰ� ����ϰ� ����.
// �������� �������� �ڵ带 �� �� �ٷ� �ٿ��ִ� ȿ���� �ش�.

/* �⺻����
[captures](parameters)mutable -> return type { body } (execute);

captures{
    ���ٽ��� ������ �ٱ��� ������ ������ �׼����� �������� ĸó�Ѵ�.
    ������, =(call by value), &(call by reference) �� ����.
    ����θ� �ƹ��͵� ������� �ʴ´ٴ� ���̴�.
    ex) [=], [&], [a,&b], [this] 
    
    call by value �� ĸ�ĵ� �������� lambda body ���� ������ ���� ��������� const Ű���尡 �ٴ´�.
    �׷��Ƿ� lambda body���� ������ ������ �Ұ���������. (mutable Ű���� ����ϸ� ����)
    
    �������� ĸó �Ұ�
    ���������� ĸ���Ϸ��� [&] or [=]�� �̿��ؾ� �Ѵ�.

    C++14 ���� [a=1+2] �� ���� �ʱ�ȭ ĸ�� ���� ����
}
parameters{
    ���ڰ�.
    C++14 ���� auto Ű���� ���� ���� ����
    ���� ����
}
mutable{
    mutable Ű���带 ���� call by value�� ĸ�ĵ� �������� constŰ���尡 ��������
    �׷��� [=]�� call by value �̱� ������ lambda body ���ο����� �Ͻ������� ���� ���� 
}
return type{
    �������� ������ٶ��� ���� ��ȯ ���� ���
    ����, �߷� ����
    C++11 �� ������ �ѹ��� ��Ÿ���ų� ���� ��� �ڵ�Ÿ�� �߷�
    lambda body ���� ��� ��ȯ���� ������ ��� �ڵ�Ÿ�� �߷�
}
body{
    �Լ� ����
}
excute{
    lambda�� ���� ��� �Լ� ������ ��� () ������ ���� �Լ� ����
}
*/
auto k= 5;
auto getLambda() {
    return [&]() {k=4; cout<<k<<endl;};
}

class Person {
private:
    string name;
public:
    Person(string _name) : name(_name){}
    void show(){
        [this]() {cout << name << endl;}();
    }
};
int main(){
    auto a = 5;

    // �⺻ ����
    [&](){a = 1; cout << a << endl;}();

    // �Լ� ������ ��� (auto �̿�)
    auto func1 = [&](){a = 2; cout<<a<<endl;};
    func1();

    // �Լ� ������ ��� (std::function �̿�)
    std::function<void()> func2 = [&](){a = 3; cout<<a<<endl;};
    func2();

    // ���� ��ȯ �Լ�
    auto func3 = getLambda();
    func3();

    // ���ټ� ����
    auto func4 = [&](){return [&](){a=5; return a;}();};
    cout<<func4()<<endl;

    // ��� ����
    // �Լ� ������ �ÿ� auto�� ���� ���������, ��ͷ� �Ҷ��� std::function ���
    std::function<int(int)> func5 = [&func5](int num) -> int{
        if(num <= 1) return 1;
        else return num* func5(num-1);
    };
    auto fact = func5(5);
    cout<<fact<<endl;

    return 0;
}