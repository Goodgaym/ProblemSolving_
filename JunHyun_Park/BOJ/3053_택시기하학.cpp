#include<cstdio>    // 3053_�ýñ����� [����], [���� �˰���], [����]
#include<math.h>
#define PI 3.141592653589793

double R;
int main(){
    scanf("%lf",&R);

    printf("%lf\n%lf", PI*pow(R,2),2*abs(R)*abs(R));
	return 0;
}