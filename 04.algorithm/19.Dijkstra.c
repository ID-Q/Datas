/*************************************************************************
	> File Name: 19.Dijkstra.c
	> Author: zhengdongqi
	> Mail: 
	> Created Time: 五  5/24 16:47:12 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

const int INF = 0x3f3f3f3f;

typedef struct Graph {
    int n;
    int visited[MAX_N], dist[MAX_N];
    int mat[MAX_N][MAX_N];
}Graph;

void init(Graph *g, int input_n) {
    g->n = input_n;
    for (int i = 0; i < g->n; ++i) {
        for (int j = 0; j < g->n; j++) {
            g->mat[i][j] = INF;
        }
    }
}

void insert(Graph *g, int x, int y, int weight) {
    g->mat[x][y] = weight;
    g->mat[y][x] = weight;
}

void dijkstra(Graph *g, int v) {
    for (int i = 0; i < g->n; i++) {
        g->visited[i] = 0;
        g->dist[i] = INF;
    }
    g->dist[v] = 0;
    for (int i = 0; i < g->n; i++) {
        int min_dist = INF, min_vertex;
        for (int j = 0; j < g->n; j++) {
            if (g->visited[j] || g->dist[j] >= min_dist) continue;
            min_dist = g->dist[j];
            min_vertex = j;
        }
        g->visited[min_vertex] = 1;
        for (int j = 0; j < g->n; j++) {
            if (g->visited[j] || min_dist + g->mat[min_vertex][j] >= g->dist[j]) continue;
            g->dist[j] = min_dist + g->mat[min_vertex][j];
        }
    }
}

int main() {
     int n, m, v;
    Graph g;
    scanf("%d%d", &n, &m);
    init(&g, n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        insert(&g, a, b, c);
    }
    scanf("%d", &v);
    dijkstra(&g, v);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, g.dist[i]);
    }
    return 0;
}
