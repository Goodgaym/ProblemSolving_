#include<cstdio>    // 1085_���簢������Ż�� [����]
int C(int x,int y){
    return x<y?x:y;
}
int x,y,w,h;
int main(){
    scanf("%d%d%d%d",&x,&y,&w,&h);
    printf("%d",C(C(C(w-x,x),y),h-y));
    return 0;
}