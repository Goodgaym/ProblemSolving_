#include<cstdio>    // 2775_�γ�ȸ���̵��׾� [��Ģ]
int N;
int f[15];
int main(){
    scanf("%d", &N);
    while(N--){
        int k, n, t, b;
        scanf("%d %d", &k, &n);

        for(int i=0; i<=k; i++){
            for(int j=1; j<=n; j++){
                if(i==0)
                    f[j] = j;
                else
                    f[j] = f[j-1] + f[j];
            }
        }
        printf("%d\n", f[n]);
    }
}