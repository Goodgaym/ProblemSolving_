#include<cstdio>   // 10162_���ڷ����� [����]

int main() {
	int T;

	scanf("%d", &T);
	if (T % 10 != 0)
		printf("%d",-1);
	else
		printf("%d %d %d", T / 300, (T % 300) / 60, (T/10)% 6);

	return 0;
}