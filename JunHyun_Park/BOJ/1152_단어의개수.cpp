#include <cstdio>   // 1152_�ܾ��ǰ��� [���ڿ�ó��]
char c;
int n;
bool r = true;
int main() {
	for(int i=0; !(c==10); i++){
		if (!(c == 32) && r && !i==0) { n++; r=false; }
		c = getchar();
		if (c == 32) r = true;
	}
	printf("%d", n);
	return 0;
}