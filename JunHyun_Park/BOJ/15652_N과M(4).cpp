#include<cstdio>	// 15652_N��M(4) [��Ʈ��ŷ]
int n,m;
bool v[9];
char a[16]="0 0 0 0 0 0 0 0";
void f(int x,int y){
	if(x==m)puts(a);
	else for(int i=y;i<n;i++){
		a[x*2]=49+i;
		f(x+1, i);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	a[m*2]=0;
	f(0,0);
	return 0;
}