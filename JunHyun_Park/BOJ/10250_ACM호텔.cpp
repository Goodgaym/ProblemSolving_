#include<cstdio>    // 10250_ACMȣ�� [��Ģ]
int N, w, h, c;
int main(){
    scanf("%d ", &N);
    while(N--){
        scanf("%d %d %d", &h, &w, &c);
        printf("%d\n", c%h? c %h *100 +c /h +1 : h *100 +c /h);
    }
    return 0;
}