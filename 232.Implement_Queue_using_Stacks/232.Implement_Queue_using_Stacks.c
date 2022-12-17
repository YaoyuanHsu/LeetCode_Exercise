typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct {
    NODE *head, *tail;
} MyQueue;

MyQueue* myQueueCreate() {
    struct MyQueue* Q = calloc(1, sizeof(MyQueue));
    return Q;
}

void myQueuePush(MyQueue* obj, int x) {
    NODE* tmp = calloc(1, sizeof(NODE));
    tmp->data = x;
    tmp->next = NULL;
    if (!obj->head)
        obj->head = tmp;
    if (!obj->tail)
        obj->tail = tmp;
    else {
        obj->tail->next = tmp;
        obj->tail = obj->tail->next;
    }
}

int myQueuePop(MyQueue* obj) {
    NODE* tmp = obj->head;
    if (!tmp)
        return NULL;
    int data = tmp->data;
    if (obj->head == obj->tail) {
        free(tmp);
        obj->head = NULL;
        obj->tail = NULL;
    } else {
        obj->head = tmp->next;
        free(tmp);
    }
    return data;
}

int myQueuePeek(MyQueue* obj) {
    return obj->head->data;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->head == NULL;
}

void myQueueFree(MyQueue* obj) {
    NODE *pre, *tmp = obj->head;
    while (tmp != NULL) {
        pre = tmp;
        tmp = tmp->next;
        free(pre);
    }
}