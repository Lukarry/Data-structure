#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct graph *Graph;
typedef struct node *Node;
struct node {
    int vertex;
    int weight;
    Node next;
};
struct graph {
    int n;
    Node adj[MAX];
};
void initGraph(Graph *graph, int n) {
    *graph = (Graph)malloc(sizeof(struct graph));
    (*graph)->n = n;
    for (int i = 0; i < n; i++) {
        (*graph)->adj[i] = NULL;
    }
}
void addEdge(Graph graph, int u, int v, int w) {
    Node newnode = (Node)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->weight = w;
    newnode->next = graph->adj[u];
    graph->adj[u] = newnode;
}
void BFS(Graph graph, int start, int visited[], FILE *output) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    fprintf(output, "BFS from V%d: ", start);
    while (front < rear) {
        int u = queue[front++];
        fprintf(output, "V%d ", u); // 输出当前节点
        Node temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            if (!visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
            temp = temp->next;}
    }
    fprintf(output, "\n"); // BFS 输出完后换行
}
void freeGraph(Graph graph) {
    for (int i = 0; i < graph->n; i++) {
        Node temp = graph->adj[i];
        while (temp) {
            Node toFree = temp;
            temp = temp->next;
            free(toFree);}}
    free(graph);
}
int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output) {
        printf("Error opening file!\n");
        return -1;
    }
    int n, m;
    fscanf(input, "%d %d", &n, &m);
    Graph graph;
    initGraph(&graph, n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fscanf(input, "%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }
    int start;
    while (fscanf(input, "%d", &start) != EOF && start != -1) {
        int visited[MAX] = {0};
        BFS(graph, start, visited, output);
    }
    fclose(input);
    fclose(output);
    freeGraph(graph); // 释放图的内存
    printf("BFS traversal results have been written to output.txt\n");
    return 0;}
