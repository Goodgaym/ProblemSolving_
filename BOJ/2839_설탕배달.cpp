#include<cstdio>    // 2839_������� [����], [����]
int N, b;
int main() {
	scanf("%d", &N);

	while (N > 0) {
		if (N < 15 && N%5 != 0)
			N -= 3;
		else 
			N -= 5;
		b++;
	}
	if (N < 0)
		printf("-1");
	else
		printf("%d", b);

	return 0;
}