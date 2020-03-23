#include<iostream>  // 14. ������ ���̺귯�� 2
#include<fstream>
#include<thread>
#include<mutex>

using namespace std;

mutex file_mutex;

// ���� �ڿ� ����
void func(string str){
    ofstream file("test.txt", ios::app);
    
    //file_mutex.lock();

    //lock ȣ�� �� unlock ��ȣ�� �� deadlock�� ������.
    //lock_guard�� ��� �� �ڵ����� unlock ����
    { 
        lock_guard<mutex> guard(file_mutex);
        for(auto i : str)
            file << i;
        file << endl;
    }
    //file_mutex.unlock();
}

int main(){
    thread t1(func, "thread 1");
    thread t2(func, "thread 2");

    t1.join();
    t2.join();

    return 0;

}