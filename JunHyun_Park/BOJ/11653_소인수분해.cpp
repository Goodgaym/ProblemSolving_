#include<cstdio>    // 11653_���μ����� [����]

int N,k;
int main(){
    scanf("%d",&N);
    k = 2;
    while (N>1){
        if(N%k == 0){
            printf("%d\n",k);
            N/=k;
        }
        else k++;
    }
    return 0;
}