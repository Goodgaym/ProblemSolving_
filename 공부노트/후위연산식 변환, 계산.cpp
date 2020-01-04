#include<cstdio>	// ��ȣ���� ����� ����. [��������� ��ȯ], [��������� ���]
template <typename T>
class stack{
public:
	void push(T n){
		this->_n[++_top] = n;
	}
	int pop(){
		return this->_n[_top--];
	}
	int top(){
		if(this->isEmpty()) return -1;
		else return this->_n[_top];
	}
	bool isEmpty(){
		if(_top == -1)	return true;
		else	return false;
	}
	int isTop(){
		return _top;
	}	
private:
	T _n[20];
	int _top = -1;
};

int main(){
	short N, top = -1;	// ���� ����, ���� ��ȯ ���ڿ��� ����
	char c, s[20];	// �Է� ���� , ���� ��ȯ ���ڿ�
	stack<int> n_s;	// �ǿ����� ���� 
	stack<char> oper;	// ������ ����

	scanf("%d ", &N);
	
	for(int i=0; i<N; i++){
		scanf("%c", &c);
		
		if(c >= '0' && c <= '9') s[++top] = c;	// �ǿ�����
		else if(c == '(') 	// ���� ��ȣ
			oper.push(c);

		else if(c == '*' || c == '+' || c == '-') {	// ������
			if(!oper.isEmpty() && oper.top() != '(') // ������� �ʰ� ���ÿ� �ִ°��� ��ȣ�� �ƴϸ�
				s[++top] = oper.pop();	// ��ȣ������ ������ �켱������ ���߾� �ٸ� ������ �����ϸ� �켱���� ���� ����
			oper.push(c);
		}
		else if(c == ')'){
			while(oper.top() != '(')	// ��ȣ�� ���ö� ���� �����ڸ� pop (�ٸ� ���� ����� ������ �켱����)
				s[++top] = oper.pop();
			oper.pop();
		}
	}

	// ���� ����
	while(!oper.isEmpty()) s[++top] = oper.pop();
	s[++top] = '\0';
	
	// ���� ����� ���
	printf("%s\n", s);
	
	// ���� ����� ���
	for(int i=0; s[i] != '\0'; i++){
		int a, b;
		if(s[i] == '+') n_s.push(n_s.pop() + n_s.pop());
		else if(s[i] == '-') {
			b = n_s.pop();
			a = n_s.pop();
			n_s.push(a - b);
		}
		else if(s[i] == '*') n_s.push(n_s.pop() * n_s.pop());
		else n_s.push(s[i] - '0');
	}
	printf("%d", n_s.top());
	return 0;
}