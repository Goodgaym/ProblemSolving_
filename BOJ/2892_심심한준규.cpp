#include <cstdio>   // 2892_�ɽ����ر� [���ڿ�ó��]

int main(){
	int n, T;
	for(scanf("%d", &n); n--;){
		scanf("%x", &T);
		if(T<38) printf(".");
		else printf("-");
	}
	return 0;
}