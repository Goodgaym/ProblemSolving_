#include <cstdio>   // 1546_��� [��Ģ]
#define max(x, y) x>y?x:y
int n, a[1000], m;
float z;
int main() {
    scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d",&a[i]);
		m = max(m, a[i]);
	}
	for(int i=0; i<n; ++i)
		z += (float)a[i] / (float)m * 100.0;

	printf("%f ", z/n);
    return 0;
}