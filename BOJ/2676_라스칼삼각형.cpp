#include<cstdio>	// 2676 ��Į�ﰢ�� [����]
int T;
int main(){
	for(scanf("%d", &T); T--;){
		int n,m;
		scanf("%d %d", &n, &m);

		printf("%llu\n", (n-m)*m+1);	
	}
	return 0;
}