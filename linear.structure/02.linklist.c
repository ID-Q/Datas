/*************************************************************************
	> File Name: 02.linklist.c
	> Author: zhengdongqi
	> Mail: 1821260963@qq.com
	> Created Time: 二  4/ 9 20:54:57 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkListNode {
    int data;
    struct LinkListNode *next;
} LinkListNode;

typedef struct LinkList {
    LinkListNode head;
    int length;
} LinkList;

LinkListNode *getNewNode(int val) {
    LinkListNode *p = (LinkListNode *)malloc(sizeof(LinkListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *getNewList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkList *l, int ind, int val) {
    if (ind < 0 || ind > l->length) return 0;
    LinkListNode *p = &(l->head), *new_node = getNewNode(val);
    while (ind--) p = p->next;
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return 1;
}

int search(LinkList *l, int val) {
    int ind = 0;
    LinkListNode *p =l->head.next;
    while (p && p->data != val) p = p->next, ind += 1;
    if (ind == l->length) p->data = val;
    return ind;
}

int delete(LinkList *l, int ind) {
    if (ind < 0 || ind > l->length) return 0;
    LinkListNode *p = &(l->head), *delete_node;
    while (ind--) p = p->next;
    delete_node = p->next;
    p->next = delete_node->next;
    free(delete_node);
    l->length -= 1;
    return 1;
}

void clear(LinkList *l) {
    LinkListNode *p = l->head.next, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

//反转链表
LinkList *reverse(LinkList *l) {
    LinkListNode *new = l->head.next, *p, *q;
    p = new;
    new = NULL;
    while (p) {
        q = p->next;
        p->next = new;
        new = p;
        p = q;
    }
    l->head.next = new;
    return l;
}

//链表排序
LinkList *sort(LinkList *l) {
    LinkListNode *p, *end = NULL;
    while (end != p) {
        p = l->head.next;
        while (p->next != end) {
            if (p->data > p->next->data) {
                p->data ^= p->next->data;
                p->next->data ^= p->data;
                p->data ^= p->next->data;
            }
            p = p->next;
        }
        end = p;
    }
    l->head.next = p;
    return l;
}

//链表去重
LinkList *unique(LinkList *l) {
    LinkListNode *p, *q;
    p = l->head.next;
    while (p) {
        if (p->next == NULL) break;
        if (p->data == p->next->data) {
            q = p->next->next;
            free(p->next);
            p->next = q;
        } else {
            p = p->next;
        }
    }
    l->head.next = p;
    return l;
}

void output(LinkList *l) {
    printf("\033[31mhead\033[0m -> ");
    LinkListNode *p = l->head.next;
    while(p) {
        printf("\033[33m%d\033[0m -> ", p->data);
        p = p->next;
    }
    printf("\033[31mNULL\033[0m\n");
    return ;
}

void output_search(LinkList *l, int ind) {
    int offset = 0;
    char str[100];
    LinkListNode *p = l->head.next;
    offset += sprintf(str, "head -> ");
    while (ind != 0) {
        offset += sprintf(str, "%d -> ", p->data);
        ind -= 1;
        p = p->next;
    }
    for (int i = 0; i < offset; i++) printf(" ");
    printf("\033[32m^\033[m\n");
    for (int i = 0; i < offset; i++) printf(" ");
    printf("\033[32m|\033[0m\n\n");
    return ;
}

int main() {
    LinkList *l = getNewList();
    int ind, val;
    while (~scanf("%d %d", &ind, &val)) {
        printf("insert %d to LinkList at %d = %d\n", val, ind, insert(l ,ind ,val));
        output(l);
        ind = search(l, val);
        output_search(l, ind);
    }
    return 0;
}
