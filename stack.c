#include <stdio.h>
#include <stdlib.h>

// -------------------------------------------
struct node** initStack();
void push(struct node** root, int value);
int pop(struct node** root);
void freeStack(struct node** root);
void freeRec(struct node* root);

struct node {
    int v;
    struct node* next;
};

// -------------------------------------------
void freeStack(struct node** root) {
    freeRec(*root);
    free(root);
}

// -------------------------------------------
void freeRec(struct node* root) {
    if (root == NULL) {return;}

    freeRec(root->next);
    free(root);
}

// -------------------------------------------
int pop(struct node** root) {
    if (*root == NULL) {
        printf("Stack is empty!\n");
        return 0;
    }
    int v = (*root)->v;
    struct node* q = *root;
    *root = (*root)->next;
    free(q);
    printf("%d popped\n", v);
    return v;
}

// -------------------------------------------
void push(struct node** root, int value) {
    if (*root == NULL) {
        *root = malloc(sizeof(struct node));
        struct node* p = *root;
        p->v = value;
        p->next = NULL;
    } else {
        struct node* p = malloc(sizeof(struct node));
        p->v = value;
        p->next = *root;
        *root = p;
    }
}

// -------------------------------------------
struct node** initStack() {
    struct node** root = malloc(sizeof(struct node*));
    *root = NULL;
    return root;
}

// -------------------------------------------
int main() {
    struct node** stack = initStack();
    push(stack, 5);
    push(stack, 8);
    push(stack, 6);
    int x = pop(stack);
    int y = pop(stack);
    int t = pop(stack);
    int r = pop(stack);

    freeStack(stack);

    return 0;
}