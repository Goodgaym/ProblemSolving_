#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define max(x,y) x>y?x:y
int N;
long long int R;

// ���׸�Ʈ Ʈ�� ���� ���� 
long long init(
	vector<long long> &a, 
	vector<long long> &tree,
	int node, int start, int end 
){	
	// ���� ����� ���
	if(start == end){
		return tree[node] = a[start];
	}
	// ���� ����
	else{
		int mid = (start + end)/2;
		return tree[node] = 
			init(a, tree, node*2, start, mid) +
			init(a, tree, node*2+1, mid + 1, end);
	}
}
long long sum(
	vector<long long> &tree,
	int node, int start, int end, int left, int right
){
	// [left, right] �� [start, end] �� ���� ��ġ�� �ʴ� ���
	if(left > end || right < start)
		return 0;
	// [left, right] �� [start, end] �� ���� ������ ���� ���
	else if (left <= start && end <= right)
		return tree[node];
	// [left, right] �� [start, end] �� �Ϻ� ��ġ�� ���
	else{
		int mid = (start+end)/2;
		return  sum(tree, node*2, start, mid, left, right) + 
				sum(tree, node*2+1, mid+1, end, left, right);
	}
}
int main(){
	vector<long long> A, T;
    for(;;){
        scanf("%d", &N);
        int i;
        for(i=1; i<=N; i++){
			long long input;
			scanf("%lld", &input);
			A.push_back(input);
		}
            
        if(i==1) break;

        R = 0;
		int h = (int)ceil(log2(N));
		int treesize = (1 << (h+1));
		T.assign(treesize,0);

        init(A, T, 1, 1, N);

		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n", sum(T,1, 1, N, l, r));
		A.clear();
		T.clear();
    }
}