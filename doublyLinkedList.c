#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------
struct node {
    int v;
    struct node* next;
    struct node* previous;
};

struct List {
    struct node* head;
    struct node* tail;
};

struct List* initList(int value);
void printList(struct List* list);
struct List* append(struct List* list, int value);
void freeList(struct List* list);
void freeRec(struct node* head);
struct List* insert(struct List* list, int value);

// ----------------------------------------
struct List* insert(struct List* list, int value) {
    struct node* head = list->head;
    list->head = malloc(sizeof(struct node));
    list->head->v = value;
    list->head->next = head;
    head->previous = list->head;
    return list;
}

// ----------------------------------------
void freeList(struct List* list) {
    struct node* head = list->head;
    freeRec(head);
    free(list);
}

void freeRec(struct node* head) {
    if (head == NULL) {free(head); return;}

    freeRec(head->next);
    free(head);
}

// ----------------------------------------
struct List* append(struct List* list, int value) {
    struct node* prevTail = list->tail;
    list->tail->next = malloc(sizeof(struct node));
    list->tail = list->tail->next;
    list->tail->v = value;
    list->tail->next = NULL;
    list->tail->previous = prevTail;
    return list;
}

// ----------------------------------------
struct List* initList(int value) {
    struct List* list = malloc(sizeof(struct List));
    list->head = malloc(sizeof(struct node));
    list->head->v = value;
    list->head->previous = NULL;
    list->tail = list->head;
    list->head->next = NULL;
    return list;
}

// ----------------------------------------
void printList(struct List* list) {
    struct node* p = list->head;
    int count = 0;
    while (p != NULL) {
        printf("[%d] = %d\n", count, p->v);
        p = p->next;
        count++;
    }
    printf("\n");
}

// ----------------------------------------
int main() {
    struct List* list = initList(5);
    printList(list);

    list = append(list, 10);
    printList(list);
    list = insert(list, 9);
    printList(list);
    printf("%d", list->tail->previous->v);
    freeList(list);
    return 0;
}