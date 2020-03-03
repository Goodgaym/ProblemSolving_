#include<iostream>  // 8. �̵� �ø�ƽ 
#include<cstring>
using namespace std;

/* Move Sematics
    C++11 ���� �߰��� ����. ��ü�� �޸� �������� �����ϴ� ����� ���� 
    ������ C++���� ���� Copy semantics (���� �ø�ƽ)�� ������ ���ʿ��� ���綧���� ������ �ʴ� ���� ������ ������ �Ǿ���.
    ������ ���� �Ǵ� ������ ���� �� ������ �Ҹ�� Move Semantics�� ����Ѵٸ� ���� ���縦 �ص� �޸��� ������ �����̱� ������ ����� �߻����� ����

    Class A = B;
    ��ó�� ���� ����Ʈ ��������ڸ� �����Ϸ��� ��������
    ����Ʈ ����������� ���� -> ���� ����

    swapping�� �ϰԵǸ� ���ʿ��� ���翬���� �ſ� ���� �߻�

    Move semantics �� �̶� ����ϸ� R-Value(�ӽð�ü)�� �̵��� �̿�

    �̵� ������ �� ��ü�� �� �����̹Ƿ� �����ؼ��� ���� �ȵȴ�.

    Copy Semantics �� Move Semantics�� ���� ū ��������
    Copy Semantics�� ���� ���縦 ���� ������ �Ȱ��� ��ü�� ������ �����ϹǷ� �޸� ���� ���ϰ�
    Move Semantics�� �޸� ������ ������ ���� ���� ���縦 �ϰ� ������ NULL�� �ʱ�ȭ �ϴ� ��.
*/

class atring{
public:
    char *str;
    int len;
    int capacity;
    atring(){
        cout << "[+] call constructor ! " <<endl;
        len = 0;
        capacity = 0;
        str = NULL;
    }
    atring(char *s){
        cout << "[+] call constructor ! " << endl;
        len = strlen(s);
        capacity = len;
        str = new char[len];
        for(int i= 0; i!=len; i++)
            str[i] = s[i];
    }
    // ���� ������
    atring& operator=(atring &s){
        cout << "[+] copy ! " << endl;
        if(s.len > capacity){
            delete[] str;
            str = new char[s.len];
            capacity = s.len;
        }
        len = s.len;
        for(int i=0; i!=len; i++)
            str[i]= s.str[i];
        return *this;
    }
    // �̵� ������
    atring& operator=(atring &&s){
        cout<<"[+] move ! "<<endl;
        str = s.str;
        capacity = s.capacity;
        len = s.len;

        s.str = nullptr;
        s.capacity = 0;
        s.len = 0;

        return *this;
    }
    atring(atring &s){
        cout <<"[+] call copy constructor ! " <<endl;
        len = s.len;
        str = new char[len];
        for(int i=0; i!=len; i++)
            str[i] = s.str[i];
    }
    atring(atring &&s){
        cout <<"[+] call move constructor ! " <<endl;
        len = s.len;
        str = s.str;
        capacity = s.capacity;

        s.str = nullptr;
        s.len = 0;
        s.capacity = 0;
    }
    ~atring(){
        if (str) delete[] str;
    }
    int length(){
        return len;
    }
    void print(){
        for(int i =0; i!=len; i++)
            cout<<str[i];
        cout <<endl;
    }
};
template<typename T>
void awap(T &a, T &b){
    T tmp(move(a));
    a = move(b);
    b = move(tmp);

    // �Ʒ��� ���� swap ������ �ǽ� �Ѵٸ� Copy Semantics�� ���� ���ʿ��� ���簡 �߻��Ѵ�.
    /* T tmp(a);
    a = b;
    b = tmp;*/
}
int main(){
    atring str1("CAT");
    atring str2("DOG");
    cout << "===== before Swap =====" <<endl;
    cout << "[=] str1 : ";str1.print();
    cout << "[=] str2 : ";str2.print();
    cout << "===== after Swap =====" <<endl;
    awap(str1, str2);
    cout << "[=] str1 : ";str1.print();
    cout << "[=] str2 : ";str2.print();
    cout << str1.str<<endl;
    return 0;
}