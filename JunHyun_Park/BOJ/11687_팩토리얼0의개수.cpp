#include<cstdio>    // 11687_���丮��0�ǰ��� [����], [����]

long long int N;
long long int f(long long int n){
    long long int R=0;
    for(long long int i=5; i<=n; i*=5){
        R += n/i;
    }
    return R;
}
int main(){
    bool er = false;
    long long int S;
    scanf("%lld", &N);
    long long int l=0, r=250000000000, m;
    while(l+1 < r){
        m = (l+r) /2;
        if(f(m) >= N) r = m;
        else l = m;
    }

    if(f(r) == N)
        printf("%lld",r);
    else
        printf("-1");

	return 0;
}