#include<iostream>
#include<cstdlib>

using std::cout;
using std::cin;

typedef int element;
typedef struct {
    element* data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top >= (s->capacity - 1));
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "underflow");
        exit(1); // exit()은 바로 프로세스 종료..
        // 0이면 에러 없이 정상 종료
        // 1이면 에러로 인해 비정상 종료
    }
    else {
        return s->data[(s->top)--];
    }
}

element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있습니다.");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

int main() {
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    for (int i = 0; i < 3; i++) {
        cout << pop(&s) << "\n";
    }

    free(s.data);
    return 0;
}