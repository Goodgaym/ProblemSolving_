#include <cstdio>   // 2751_�������ϱ�2 [����]
int n, max, min = 1000001;
char arr[2000001] = {false,};

int main(){
	scanf("%d",&n);
    
	for(int i=0; i<n; ++i){
        int k;
        scanf("%d", &k);
        if(max < k) max = k;
        if(min > k) min = k;
        arr[k+1000000] = true;
    }
		
	for(int i=min; i<=max; ++i){
        if(arr[i+1000000]){
		    printf("%d\n",i);
        }
    }

	return 0;
}