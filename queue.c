#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------
struct queue {
    struct node** head;
    struct node** tail;
};

struct node {
    int v;
    struct node* next;
};

struct queue* initQueue();
int dequeue(struct queue* queue);
void enqueue(struct queue* queue, int value);
void freeQueue(struct queue* queue);
void freeRec(struct node* root);

// -------------------------------------------
int dequeue(struct queue* queue) {
    if (*(queue->head) == NULL) {
        printf("Queue is empty!\n");
        return 0;
    }

    struct node* p = *(queue->head);
    int v = p->v;
    *(queue->head) = p->next;
    free(p);
    printf("%d dequeued\n", v);
    return v;
}

// -------------------------------------------
void enqueue(struct queue* queue, int value) {

    if (*(queue->head) == NULL) {
        struct node* p = malloc(sizeof(struct node));
        p->v = value;
        p->next = NULL;
        *(queue->head) = p;
        *(queue->tail) = p;
    } else {
        struct node* p = malloc(sizeof(struct node));
        p->v = value;
        p->next = NULL;
        (*(queue->tail))->next = p;
        *(queue->tail) = p;
    }
}

// -------------------------------------------
struct queue* initQueue() {
    struct queue* root = malloc(sizeof(struct queue));
    root->head = malloc(sizeof(struct node*));
    root->tail = malloc(sizeof(struct node*));
    struct node* p = NULL;
    *(root->head) = p;
    *(root->tail) = p;
    return root;
}

// -------------------------------------------
void freeQueue(struct queue* queue) {
    freeRec(*(queue->head));
    free(queue->head);
    free(queue->tail);
    free(queue);
}

// -------------------------------------------
void freeRec(struct node* root) {
    if (root == NULL) {return;}

    freeRec(root->next);
    free(root);
}

// -------------------------------------------
int main() {
    struct queue* queue = initQueue();
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    int x = dequeue(queue);
    int i = dequeue(queue);
    int v = dequeue(queue);
    int t = dequeue(queue);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    int s = dequeue(queue);
    int h = dequeue(queue);
    int g = dequeue(queue);
    int f = dequeue(queue);

    freeQueue(queue);

    return 0;
}