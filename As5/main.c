#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef int element;
element stack[MAX_SIZE];
int top = -1;

int is_empty() {
    return (top == -1);
}

int is_full() {
    return (top == (MAX_SIZE - 1));
}

void push(element item) {
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else {
        stack[++top] = item;
        printf("Push %d\n", item);
    }
}

void pop() {
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        return;
    }
    else {
        int item = stack[top--];
        printf("Pop %d\n", item);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;

        if (rand_num % 2 == 0) {
            push(rand_num);
        }
        else {
            pop();
        }
    }

    return 0;
}
