#include<cstdio>	// 15651_N��M(3) [��Ʈ��ŷ]
int n,m;
char a[16]="1 1 1 1 1 1 1 1";
void f(int x){
	if(x==m)puts(a);
	else for(int i=0;i<n;i++){
		a[x*2]=49+i;
		f(x+1);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	a[m*2]=0;
	f(0);
	return 0;
}