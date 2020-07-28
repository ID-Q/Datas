/*************************************************************************
	> File Name: 17.FloodFill.c
	> Author: zhengdongqi
	> Mail: 
	> Created Time: 五  5/24 16:16:29 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_N 1000

typedef struct Graph {
    int n;
    int color[MAX_N];
    int mat[MAX_N][MAX_N];
}Graph;

void init_Graph(Graph *g, int input_n) {
    g->n = input_n;
    for (int i = 0; i < g->n; i++) {
        g->color[i] = 0;
        for (int j = 0; j < g->n; j++) {
            g->mat[i][j] = 0;
        }
    }
}

void insert(Graph *g, int x, int y) {
    g->mat[x][y] = 1;
    g->mat[y][x] = 1;
}

void floodfill(Graph *g) {
    int color_cnt = 0;
    int q[MAX_N], head, tail;
    for (int i = 0; i < g->n; i++) {
        if (g->color[i]) continue;
        color_cnt++;
        head = tail = 0;
        q[tail++] = i;
        while (head < tail) {
            int vertex = q[head++];
            g->color[vertex] = color_cnt;
            for (int j = 0; j < g->n; j++) {
                if (!g->mat[vertex][j] || g->color[j]) continue;
                q[tail++] = j;
            }
        }
    }
    for (int i = 1 ; i <= color_cnt; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->n; j++) {
            if (g->color[j] != i) continue;
            printf("%d ", j);
        }
        printf("\n");
    }
    return ;
}

int main() {
    int n, m;
    Graph g;
    scanf("%d%d", &n, &m);
    init_Graph(&g, n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        insert(&g, a, b);
    }
    floodfill(&g);
    return 0;
}
