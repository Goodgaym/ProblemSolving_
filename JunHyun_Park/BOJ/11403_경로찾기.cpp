#include<cstdio>    // 11403_���ã�� [BFS], [DFS], [�÷��̵���Ⱦ˰���]
//�÷��̵� ���� �˰����� ����Ͽ� ���� ����

int main(){
    int N;
    bool A[101][101];
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &A[i][j]);

    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0;j<N; j++)
                if(A[i][k] && A[k][j])
                    A[i][j] = 1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}