#include<cstdio>	// 2675 ���ڿ��ݺ� [���ڿ�]
int main(){
	int T, R;
	char s[21];
	for(scanf("%d", &T); T--;){
		scanf("%d %s", &R, s);
		for(int i =0, j=1; s[i]!='\0'; j++){
			printf("%c", s[i]); 
			if(j%R==0) i++;
		}
		printf("\n");
	}
	return 0;

}