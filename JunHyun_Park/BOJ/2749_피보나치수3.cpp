#include<cstdio>    // 2749_�Ǻ���ġ��3 [�ǻ���ֱ�]
const int R = 1000000;
const int P = 15*100000;
int A[P] = {0,1};
int main(){
    long long int n;
    scanf("%lld", &n);
    
    for(int i=2;i<P; i++){
        A[i] = (A[i-2] + A[i-1])%R;
    }
    
    printf("%d", A[n%P]);
    return 0;
}