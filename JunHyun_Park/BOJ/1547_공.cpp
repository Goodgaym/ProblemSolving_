#include<cstdio>    // 1547_�� [��Ģ], [�ùķ��̼�]
int main(){
	int n, a1, a2, z=1;
	scanf("%d", &n);

	for(int i=0; i<n; ++i){
		scanf("%d %d",&a1, &a2);
		if(a1 == z)
			z = a2;
		else if(a2 == z)
			z = a1;
	}
	
	printf("%d", z);
	return 0;
}