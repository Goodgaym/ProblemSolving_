#include<cstdio>    //  [����]

int N,K;
int gcd(int m, int n){
    int r;
    while(1){
        r = m%n;
        if(r == 0 ) return n;
        else {
            m = n;
            n = r;
        }
    } 
}    
int main(){
    scanf("%d %d",&N, &K);
    int i, j;
    if(N<K){
        int t = N;
        N = K;
        K = t;
    }

    for(j=1; (N*j)%K !=0;j++);
    printf("%d\n%d", K/i, N*j);
    return 0;
}