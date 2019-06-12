/*************************************************************************
	> File Name: 04.branchtree.c
	> Author: zhengdongqi
	> Mail: 1821260963@qq.com
	> Created Time: 六  4/13 18:32:35 2019
 ************************************************************************/

#include <stdio.h>

#define swap(a, b) ({ \
	__typeof(a) __temp = (a);\
	(a) = (b);\
    (b) = __temp;\
})

#define MAX_M 1000000
#define MAX_N 500000
#define MAX_K 20


struct Edge {
    int to, next;
} g[MAX_M + 5];
int head[MAX_N + 5] = {0}, cnt = 0;
int gas[MAX_N + 5][MAX_K + 5] = {0}, deep[MAX_N + 5] = {0};
int father[MAX_N + 5] = {0};
int val[MAX_N + 5] = {0};

void add(int a, int b) {
    g[++cnt].to = b;
    g[cnt].next = head[a];
    head[a] = cnt;
    return ;
}

void dfs1(int fa, int ind) {
    father[ind] = fa;
    for (int i = 1; i <= MAX_K; i++) {
        gas[ind][i] = gas[gas[ind][i - 1]][i - 1];
    }
    for (int i = head[ind]; i; i = g[i].next) {
        if (g[i].to == fa) continue;
        int to = g[i].to;
        deep[to] = deep[ind] + 1;
        gas[to][0] = ind;
        dfs1(ind, to);
    }
    return ;
}

int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    for (int i = MAX_K; i >= 0; i--) {
        if (deep[gas[x][i]] < deep[y]) continue;
        x = gas[x][i];
    }
    if (x == y) return x;
    for (int i = MAX_K; i >= 0; i--) {
        if (gas[x][i] == gas[y][i]) continue;
        x = gas[x][i], y = gas[y][i];
    }
    return gas[x][0];
}

int query(int ind) {
    int ans = 0;
    for (int i = head[ind]; i; i = g[i].next) {
        if (g[i].to == father[ind]) continue;
        ans += query(g[i].to);
    }
    ans += val[ind];
    return ans;
}

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    deep[0] = -1;
    dfs1(0, s);
    for (int i = 0; i < m; i++) {
        int a, b, c, d, temp;
        scanf("%d", &a);
        switch (a) {
            case 1: {
                scanf("%d%d%d", &b, &c, &d);
                val[b] += d;
                val[c] += d;
                temp = lca(b, c);
                val[temp] -= d;
                val[father[temp]] -= d;
            } break;
            case 2: {
                scanf("%d", &b);
                printf("%d\n", query(b));
            } break;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", val[i]);
    }
    printf("\n");
    return 0;
}

