/*************************************************************************
	> File Name: 01.vector.c
	> Author: zhengdongqi
	> Mail: 1821260963@qq.com
	> Created Time: 二  4/ 9 19:03:15 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

int expand(Vector *v) {
    int extra_size = v->size;
    int *p;
    while (extra_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extra_size));
        if (p) break;
        extra_size /= 2;
    }
    if (extra_size == 0) return 0;
    v->data = p;
    v->size += extra_size;
    return 1;
}

int insert(Vector *v, int ind, int val) {
    if (ind < 0 || ind > v->length) return 0;
    if (v->length == v->size) {
        if (!expand(v)) return 0;
    }
    for (int i = v->length - 1; i >= ind; i--){
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if (ind < 0 || ind >= v->length) return 0;
    for(int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

int search(Vector *v, int val) {
    int ind = 0;
    while (ind <= v->length && v->data[ind] != val) {
        ind += 1;
    }
    if (v->data[ind] == val) return ind;
    return 0;
}

void output(Vector *v) {
    if(v == NULL) return ;
    printf("vector = [");
    for (int i = 0; i < v->length; i++) {
        printf(" %d", v->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

int main() {
    #define MAX_OP 20 
    int op, ind, val;
    Vector *v = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;
        ind = rand() % (v->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0: 
            case 1:
            case 2: {
                printf("insert \033[31m%d\033[0m to vector at \033[32m%d\033[0m = \033[33m%d\033[0m\n", val, ind, insert(v, ind, val));
                output(v);
                printf("search  \033[31m%d\033[0m from vector = \033[32m%d\033[0m\n", val, search(v, val));
            } break;
            case 3: {
                printf("erase element at \033[31m%d\033[0m from vector \033[32m%d\033[0m\n", ind, erase(v, ind));
                output(v);
            } break;
            default: 
                fprintf(stderr, "wrong op \033[31m%d\033[0m\n", op);
            break;
        }
    }
    clear(v);
    return 0;
}

