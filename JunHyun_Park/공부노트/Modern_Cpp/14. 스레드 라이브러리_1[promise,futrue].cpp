#include<iostream>
#include<thread> // ������ ��� ���
#include<future> // promise, future ��ü�� ����ϱ� ���� ���
using namespace std;

chrono::system_clock::time_point start_time;

class Class{
    public:
    static void func(int a, int b){
        for(int i=0; i<b; i++){
            cout << a << endl;
        }
    }
};
void func(int a, int b){
    this_thread::sleep_until(start_time + 3s); // ���α׷� ���� �� 3�ʵ� ����
    for(int i=0; i<b; i++){
        this_thread::sleep_for(1s); // 1�� ���� sleep
        cout << a << endl;
    }
}

void sum(promise<int>& ret, int t){
    this_thread::sleep_for(5s);
    int sum = 0;
    for(int i=1; i<=t; i++) sum += i;
    ret.set_value(sum);
}
int main(){
    start_time = chrono::system_clock::now(); // ���α׷� ���۽ð�

    thread t1(func, 1, 5); // ù��°���ڴ� �Լ�, �ι�° ���ں��� �Ű�����
    thread t2([](int a, int b){ // ���� �Լ��� ����
        for(int i=0; i<b; i++){
            cout << a << endl;
        }
    }, 2, 5);
    thread t3;
    /* join �Լ��� ȣ������ ������ ������ �Լ��� ����Ǳ� ����
    �����Լ��� ����Ǵ� ��찡 �����Ƿ� join() �Լ��� ȣ���Ѵ�.
    �ش� ������ �Լ��� ����� ������ join() �Լ��� ���� �ڵ�� ������� �ʴ´�.
    
    */
    t1.join();
    t2.join();
    
    t3 = thread(Class::func,3,5); // ���� �س��� ���ϴ� Ÿ�ֿ̹� ������ ����
    // static �Լ� / ���� �Լ� �� �����ϴ�.
    /*
    Class c;//�Ϲ� Ŭ���� ����Լ��� ȣ���ϱ� ���ؼ���
    t3 = thread(&Class::func, &c ,3, 5);//������ ���� ȣ���Ѵ�.
    */
    t3.join();

    // ������ �Լ��� ���ϰ� �ޱ�
    promise<int> ret;
    future<int> value = ret.get_future(); // future<int> => auto ����
    thread t4(sum, ref(ret), 10); // �������·� �ѱ�� �ʹٸ� ref() �Լ� ���

    cout << value.get() <<endl;
    // get() �Լ��� set_value()�� ȣ��� ������ ��ٸ���.
    // �׷��Ƿ� join()�Լ��� �� �����ٿ� ȣ���ص� ������ �߻����� �ʴ´�.

    t4.join();
}