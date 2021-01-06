/*************************************************************************
	> File Name: 06.Trie.c
	> Author: zhengdongqi
	> Mail: 1821260963@qq.com
	> Created Time: 五  5/24 13:23:05 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

int cnt = 0;
int letter_cnt = 0;

Node *getNewNode() {
    cnt += 1;
    Node *p = (Node *)calloc(1, sizeof(Node));
    return p;
}

void insert(Node *node, const char *s) {
    Node *p = node;
    for (int i = 0; s[i]; i++) {
        if (p->next[s[i] - BASE_LETTER] == NULL) {
            p->next[s[i] - BASE_LETTER] = getNewNode();
        }
        p = p->next[s[i] - BASE_LETTER];
    }
    p->flag = 1;
    return ;
}

int query(Node *node, const char *s) {
    Node *p = node;
    for (int i = 0; s[i]; i++) {
        p = p->next[s[i] - BASE_LETTER];
        if (p == NULL) return 0;
    }
    return p->flag;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int main() {
    char str[100];
    int n, m;
    scanf("%d%d", &n, &m);
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        letter_cnt += strlen(str);
        insert(root, str);
    }
    printf("rate : %lf\n", 1.0 * letter_cnt / (cnt * sizeof(Node)));
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        printf("query(%s) = %d\n", str, query(root, str));
    }
    return 0;
}
