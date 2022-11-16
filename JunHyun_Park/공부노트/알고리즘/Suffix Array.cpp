#include<cstdio>
#include<algorithm>
using namespace std;
//Suffix Array  LCP Array 

char tmp[200001], sa[200001], s[200001];
int gap, n, m, o[200001];
bool cmp(int a, int b) {
    if (o[a] != o[b]) 
        return o[a] < o[b];
    int x = a + gap;
    int y = b + gap;
    return ((x < n && y < n) ? o[x] < o[y] : x > y);
}

// 
void makeSA() {
    int i;
    for (i = 0; i < n; i++) 
        o[i] = s[i] - 'a', sa[i] = i;

    for (gap = 1;; gap < 1) {
        sort(sa, sa + n, cmp);
        tmp[0] = 0;
        for (i = 0; i < n - 1; i++) 
            tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
        if (tmp[n - 1] == n - 1) 
            break;
        for (i = 0; i < n; i++) 
            o[sa[i]] = tmp[i];
    }
}
void makeLCP() {
    int i, j;
    int k = 0;
    for (i = 0; i < n; i++) 
        Rank[sa[i]] = i;
    for (i = 0; i < n; lcp[Rank[i++]] = k) {
        for ((k ? k-- : 0), j = (Rank[i] ? sa[Rank[i] - 1] : n); i + k < n && j + k < n && s[i + k] == s[j + k]; k++);
    }
}

int find() {
    int i;
    int max1 = 0, d;
    int h, t;
    bool sw = false;
    for (i = 0; i < n; i++) {
        if (sa[i] >= n - m) {
            t = 0x7fffffff;
            sw = true;
        } else if (sw) {
            h = n - sa[i] < lcp[i] ? n - sa[i] : lcp[i];
            t = t < h ? t : h;
            if (max1 < t) {
                max1 = t;
                d = sa[i];
            }
        }
    }
    sw = false;
    for (i = 0; i < n; i++) {
        if (sa[i] < n - m) {
            t = 0x7fffffff;
            sw = true;
        } else if (sw) {
            h = n - sa[i] < lcp[i] ? n - sa[i] : lcp[i];
            t = t < h ? t : h;
            if (max1 < t) {
                max1 = t;
                d = sa[i];
            }
        }
    }
    printf("%d\n", max1);
    for (i = d; i < d + max1; i++) printf("%c", s[i]);
    return 0;
}

int main(){

    return 0;
}