#include<iostream>	// 5. ����Ʈ ������
#include<cstdio>
#include<vector>
#include<memory>
using namespace std;

// delete Ű���带 �̿��� �޸� ������ ���� �ʰ� ����ϴ� ������
// �Ҹ��ڰ� �ڵ����� ����� ���� �޸𸮸� delete ���ش�.
// ���� ���� �������� �ʴ� ��� ����Ʈ �����ڰ� �ڵ����� NULL�� �ʱ�ȭ�Ѵ�.
// �޸� ��, ��۸� ������ ����
// * �޸� �� : �����Ҵ� ��, �޸𸮸� �������� �ʾ� �޸𸮰� �����Ǵ� ����
// * ��۸� ������ : ������ �޸𸮸� �����ϰų� ���ÿ��� ����� �޸𸮸� �����ϴ� ������

// unique_ptr/shared_ptr/weak_ptr�� �����Ѵ�.
/* unique_ptr :
	- �ϳ��� ����Ʈ �����͸� Ư�� ��ü�� �����ϵ��� �������� ����
	- �ش� ��ü�� �������� ������ ���� �� �Ҹ��ڰ� �ش� ��ü�� ����
	- ���� �����ڿ� ���� ���� �����ڰ� �ʿ���� ������ ��� �Ұ�.
	- ���簡 �Ұ����ϰ� ������ ������ ����
	- ������ ������ ���� unique_ptr�� null_ptr�� �ȴ�.
	- ������ ������ move �Լ� ���.
	- �����ʹ� get ����Լ��� ���, �޸� ������ reset��� �Լ��� ���
*/
/* shared_ptr :
	- ���� Ƚ���� ���� �����ϴ� ����Ʈ �����Ͱ� ����� Ȯ���Ѵ�.
	- ���� Ƚ���� Ư�� ��ü�� ���� shared_ptr�� �߰��� ������ 1�� ����, ���� �Ҷ����� 1�� ����
	- ���� Ƚ���� 0�� �Ǹ� �ڵ� ����
	- unique_ptr�� ���� make_shared �Լ��� ���� �����ϰ� ���� ����
	- ���翡 ������ ����.
	- use_count �Լ��� ���� ���� Ƚ���� �� �� �ִ�.
	- ���� Ƚ���� �ǵ帮�� ������ shared_ptr ��ü�� ���簡 �Ǿ �޸� ������ �ȴþ.
	- move �Լ��� ����ϸ� ������ �����͸� �����ϰ� �״�� �����ϱ� ������ ���� Ƚ���� �� ����
*/
/* weak_ptr :
	- ���� ������ ����Ű�� ����Ʈ �����ʹ� ����Ƚ���� 0�� ���� �����Ƿ� �޸𸮰� �������� �ʴ´�.
	- weak_ptr�� �� ��ȯ������ �����ϱ� ���� ���ȴ�.
	- weak_ptr�� �ϳ� �̻��� shared_ptr �ν��Ͻ��� �����ϴ� ��ü�� ���� ������ ���������� ������ ������ ���Ծȵ�.
	- weak_ptr�� ����Ű�� �޸� ������ shared_ptr�� ����Ƚ���� ���Ե��� ����.
*/	
int main(){
	// Modern Cpp ���� auto_ptr�� ���
	//auto_ptr<int> aptr1(new int(1));
	//auto_ptr<int> aptr2 = aptr1; // �̶� aptr1�� null_ptr�� �ȴ�.

	// unique_ptr
	unique_ptr<int> uptr(new int(1));
	cout << *uptr << endl; // output 1
	
	auto uptr2 = uptr.get(); // ������ ������ �ƴ� ���� ������ ���
	*uptr2 = 2;
	cout << *uptr2 <<" "<< *uptr << endl; // output 2 2

	auto uptr3 = move(uptr); // ������ ����
	uptr.reset();	// �̹� ������ ������ �Ǿ� �ƹ��ϵ� ���Ͼ.
	cout << *uptr3 <<" "; // output 2
	*uptr3 = 3;
	cout << *uptr3 << " " << *uptr2 << endl; // output 3 3

	// make_unique : ������ Ÿ���� ��ü�� �����ϰ� ������ ��ü�� ����Ű�� unique_ptr ��ȯ
	// ���� �߻��� �����ϰ� ��ó
	unique_ptr<int[]> uptr4(new int[3]{1,2,3});
	for(int i=0; i<3; i++)
		cout << uptr4[i] << endl;

	unique_ptr<int[]> uptr5 = make_unique<int[]>(3);
	for(int i=0; i<3;) 
		uptr5[i] = ++i;
	for(int i=0; i<3; i++)
		cout << uptr5[i] << endl;

	// shared_ptr
	shared_ptr<int> sptr = make_shared<int>(1);
	cout << sptr.use_count()<<endl;	// 1

	auto sptr2 = sptr;	// ����
	cout << sptr.use_count()<<endl;	// 2

	auto sptr3(sptr); 	// �����ڷ� ����
	cout << sptr.use_count()<<endl;	// 3
	
	auto sptr4 = move(sptr2);	// ������ ����
	cout << sptr.use_count()<<endl;	// 3
	
	sptr4.reset();	// ������ ����
	sptr3.reset();
	sptr.reset();

	cout << sptr.use_count()<<endl;	// 0
	
	return 0;
}