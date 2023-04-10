#include <stdio.h>
#include <stdlib.h>

// -------------------------------------------
struct node* initList(int value);
void printLinkedList(struct node* root);
struct node* addList(struct node* root, int value);
void freeList(struct node* root);

struct node {
    int v;
    struct node* next;
};

// -------------------------------------------
void freeList(struct node* root) {
    if (root == NULL) {free(root); return;}

    freeList(root->next);
    free(root);
}

// -------------------------------------------
void printLinkedList(struct node* root) {
    struct node* p = root;
    int count = 0;
    while (p != NULL) {
        printf("[%d] = %d\n",count, p->v);
        p = p->next;
        count++;
    }
    printf("\n");
}

// -------------------------------------------
struct node* addList(struct node* root, int value) {
    if (root == NULL) {
        root = malloc(sizeof(struct node));
        root->v = value;
        root->next = NULL;
        return root;
    } else {
        struct node* p = root;
        while (p->next != NULL) {p = p->next;}
        p->next = malloc(sizeof(struct node));
        p = p->next;
        p->v = value;
        p->next = NULL;
        return root;
    }
}

// -------------------------------------------
struct node* initList(int value) {
    struct node* root = malloc(sizeof(struct node));
    root->v = value;
    root->next = NULL;
    return root;
}

// -------------------------------------------
int main() {
    struct node* list = initList(5);
    printLinkedList(list);
    addList(list, 5);
    addList(list, 10);
    printLinkedList(list);
    freeList(list);
    return 0;
}