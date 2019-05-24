/*************************************************************************
	> File Name: my_random.c
	> Author: zhengdongqi
	> Mail: 1821260963@qq.com
	> Created Time: 四  4/11 20:48:21 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

static int seed = 1;

void my_srand(int s) {
    seed = ((s ^ (s < 7) ^ (s >> 5)) % 100 + 100 ) % 100 + 1;
}
int my_random() {
    seed = (seed * 3) % 101;
    return seed;
}

int main() {
    /*int b = rand(), length = 0;
    while (b != rand()) length += 1;
    printf("%d\n", length);*/
    for (int i = 0; i < 100; i++) {
        printf("%d\n", my_random());
    }
    return 0;
}
