//
// Created by Вадим Герасимович on 4/21/23.
//

#include "FFF.h"
int input(int min, int max) {
    int x;
    while (scanf("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void push(Stack** s, int data) {
    Stack* new_node = malloc(sizeof(Stack));
    if (new_node == NULL) {
        fprintf(stderr, "Error: unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = *s;
    *s = new_node;
}

int pop(Stack** s) {
    if (*s == NULL) {
        fprintf(stderr, "Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    int data = (*s)->data;
    Stack* temp = *s;
    *s = (*s)->next;
    free(temp);
    return data;
}

int is_empty(Stack* s) {
    return s == NULL;
}

int find_min(Stack* s) {
    int min = s->data;
    while (s != NULL) {
        if (s->data < min) {
            min = s->data;
        }
        s = s->next;
    }
    return min;
}

void clear_stack(Stack** s) {
    while (*s != NULL) {
        Stack* temp = *s;
        *s = (*s)->next;
        free(temp);
    }
}

void print_stack(Stack* s) {
    printf("Stack: ");
    if (s == NULL){
        printf("Stack underflow\n");
        return;
    }
    while (s != NULL) {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

int task1(){
    Stack* s = NULL;
    int max_size, data;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max_size);
    for (int i = 0; i < max_size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        push(&s, data);
        if (is_empty(s)) {
            break;
        }
    }
    int sum = 0;
    int min = find_min(s);
    while (!is_empty(s)) {
        int data = pop(&s);
        if (data == min) {
            break;
        }
        sum += data;
    }
    printf("Sum of elements before the minimum element: %d\n", sum);
    clear_stack(&s);
    //print_stack(s);
    return 0;
}

void merge_sorted(Stack* s1, Stack* s2, Stack* result) {
    while (s1 != NULL && s2 != NULL) {
        if (s1->data < s2->data) {
            push(&result, pop(&s1));
        } else {
            push(&result, pop(&s2));
        }
    }
    while (s1 != NULL) {
        push(&result, pop(&s1));
    }
    while (s2 != NULL) {
        push(&result, pop(&s2));
    }
    //return *result;
}
struct FILO* moveToPointer(struct FILO* head, int n) {
    while (head != NULL && n != 1) {
        head = head->next;
        n--;
    }

    return head;
}
struct FILO* mergeFILO(struct FILO* h2, struct FILO* h1, struct FILO* h3, int size) {
    struct FILO* temp1 = h1;
    while (temp1 != NULL && size != 0) {
        struct FILO* temp2 = moveToPointer(h2, size);
        if (temp1->data <= temp2->data) {
            push(&h3, temp2->data);
            size--;
        }
        else {
            push(&h3, temp1->data);
            temp1 = temp1->next;
        }
    }
    if (temp1 != NULL) {
        while (temp1 != NULL) {
            push(&h3, temp1->data);
            temp1 = temp1->next;
        }
    }
    else if (size != 0) {
        while (size != 0) {
            struct FILO* temp2 = moveToPointer(h2, size);
            push(&h3, temp2->data);
            size--;
        }
    }
    return h3;
}
int task2(){
    Stack *s1 = NULL, *s2 = NULL, *s3 = NULL;
    int n, i, x, max, min;
    printf("Введите количество элементов в стеках: ");
    n= input(1,99);
    printf("Введите элементы в первый стек по убыванию:\n");
    printf("Enter element 1: ");
    x= input(-9999,9999);
    push(&s1,x);
    max=x;
    for (i = 0; i < n-1; i++) {
        printf("Enter element %d: ", i+2);
        while (scanf("%d", &x) != 1 || x < -9999 || x > max || x % 1 != 0 || getchar() != '\n') {
            printf("Item > max. Try again: ");
            rewind(stdin);
        }
        push(&s1, x);
        max=x;
    }
    printf("Введите элементы во второй стек по возрастанию:\n");
    printf("Enter element 1: ");
    x= input(-9999,9999);
    push(&s2,x);
    min=x;
    for (i = 0; i < n-1; i++) {
        printf("Enter element %d: ", i+2);
        while (scanf("%d", &x) != 1 || x < min || x > 9999 || x % 1 != 0 || getchar() != '\n') {
            printf("Item < max. Try again: ");
            rewind(stdin);
        }
        push(&s2, x);
        min=x;
    }
    s3=mergeFILO(s1,s2,s3,n);
    printf("Упорядоченный по возрастанию третий стек:\n");
    clear_stack(&s1);
    clear_stack(&s2);
    print_stack(s3);
    clear_stack(&s3);
    return 0;
}

int task3(){
    printf("Задание не сделано, не надо сюда жмать)))\b");
    return 0;
}