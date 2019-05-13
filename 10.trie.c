/*************************************************************************
	> File Name: 10.trie.c
	> Author: zhengdongqi
	> Mail: 1821260963@qq.com
	> Created Time: 日  5/12 15:32:08 2019
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

Node *getNewNode() {
    Node *p = (Node *)calloc(1, sizeof(Node));
    return p;
}

void insert(Node *node, const char *s) {
    Node *p = node;
    for (int i= 0; s[i]; i++) {
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
        if (p->next[s[i] - BASE_LETTER] == NULL) {
            return 0;
        }
        p = p->next[s[i] - BASE_LETTER]; 
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
        insert(root, str);
    }
    for (int j = 0; j < m; j++) {
        scanf("%s", str);
        printf("%s -> %d\n", str, query(root, str));
    }
    return 0;
}
