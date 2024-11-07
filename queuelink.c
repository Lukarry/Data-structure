#include<stdio.h>
#include<stdlib.h>
// 定义树节点结构
typedef struct Node {
    char val;
    struct Node *left;
    struct Node *right;
} *Tree;

// 定义链式队列节点结构
typedef struct QueueNode {
    Tree data;
    struct QueueNode *next;
} QueueNode;

// 定义链式队列结构
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 创建一个空队列
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 入队操作
void enqueue(Queue *q, Tree t) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = t;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出队操作
Tree dequeue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    }
    QueueNode *temp = q->front;
    Tree data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// 检查队列是否为空
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// 创建树的函数
Tree createtree() {
    Tree bt = NULL;
    char ch;
    scanf("%c", &ch);
    if (ch != '#') {
        bt = (Tree)malloc(sizeof(struct Node));
        bt->val = ch;
        bt->left = createtree();
        bt->right = createtree();
    }
    return bt;
}

// 链式队列实现的层序遍历函数
void levelorder(Tree bt) {
    if (bt) {
        Queue *q = createQueue();
        enqueue(q, bt);
        while (!isEmpty(q)) {
            Tree current = dequeue(q);
            printf("%c", current->val);
            if (current->left) {
                enqueue(q, current->left);
            }
            if (current->right) {
                enqueue(q, current->right);
            }
        }
        // 释放队列结构
        free(q);
    }
}

int main() {
    Tree bt = createtree();
    printf("level-order:");
    levelorder(bt);
    return 0;
}
