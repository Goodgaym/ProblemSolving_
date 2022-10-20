#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 1020

bool chk[MAX];
void dfs(int v);
void bfs(int v);
int n, m, v;    // ������ ����, ���� ����, Ž�� ���� ��ȣ
int arr[MAX][MAX];
queue<int> q;

int main(){
	int a, b;
	scanf("%d %d %d", &n ,&m, &v);
	for (int i = 0; i < m; i++)	{
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}
	dfs(v);
	memset(chk, false, MAX);
	printf("\n");
	bfs(v);
	return 0;
}

// DFS�� ���Լ����� ����, ��͸� �����
void dfs(int v){
	chk[v] = true;  // üũ
	printf("%d ", v);   // ���
	for (int i = 1; i <= n; i++) // ���� ��ġ���� ����Ǿ� �ִ� ��� �ʺ� ��ȸ
		if (arr[v][i] == 1 && !chk[i])  // ����Ǿ� �ִ� ��� �� �湮���� ��� �湮
			dfs(i); // ����Ǿ� �ִ� ������ ���� ��ȸ
}

// BFS�� ���Լ����� ť�� �����
void bfs(int v){
	chk[v] = true;  // ù �湮 üũ
	q.push(v);      // ù �湮 Ǫ��
	int now;
	while (!q.empty()){     // ����Ǿ� �ִ� �� ��� �湮 �Ҷ����� �۵���
		now = q.front();    // �湮�ѰͰ� ����Ǿ� �ִ� ���� Ȯ�� ����
		printf("%d ", now); // ���
		q.pop();    // ���� ������ ��
		for (int i = 1; i <= n; i++)    // �ʺ� ��ȸ
			if (arr[now][i] == 1 && !chk[i]){     // ����Ǿ� �ִ� ��� �� �湮���� ��� �湮
				chk[i] = true;      // ť�� ���� �� üũ
				q.push(i);      // ť�� Ǫ�� (���� ��ȸ �غ�)
			}
	}
}