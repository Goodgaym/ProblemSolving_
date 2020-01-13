// iterator �ݺ���

// ���� ǥ���θ� �������� �ʰ� � ���� ��ü�� ���� ���ҵ��� ���������� ������ �� �ִ� ����� ����
// - ����Ʈ ��ü�� �����ؼ� ���ο� ������ ���� ���� �ϰų� ��ȸ�ϴ� ������ �ݺ��� ��ü�� ����
// List -> Iterator �������� ���� �ݺ��� �����ϵ��� �Ͽ�����


#include<iostream>
using namespace std;
#define DEFAULT_LIST_CAPACITY 10000000;

template<class Item>
class List {
    public:
    
    // ����, �Ҹ�, �ʱ�ȭ, ����
    List(long size = DEFAULT_LIST_CAPACITY) : _size(size);
    List(List&);
    ~List(){

    }
    List& operator=(const List&){
        return *this;
    }
    
    // ���ٿ� �Լ�
    long Count() const{
        return _size;
    }
    Item& Get(long index) const{
        return _item;
    }
    Item& First() const;
    Item& Last() _const;
    bool Includes(const Item&) const{

    };

    void Append(const Item&){

    };

    void Prepend(const Item&){

    };

    // 
    void Remove(const Item&);
    void RemoveLast();
    void RemoveFirst();
    void RemoveAll();

    Item& Top() const;
    void Push(const Item&);
    Item& pop();

private:
    long _size;
    Item* _head, _tail;
};

template<class Item>
void List<Item>::Append(const Item& item){

}