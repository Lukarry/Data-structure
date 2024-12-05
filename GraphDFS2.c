#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;
typedef struct Graph {
    int n;                 // 顶点数
    Node* adj[MAX_NODES];  // 邻接表
} Graph;
void initGraph(Graph* graph, int n) {
    graph->n = n;
    for (int i = 0; i < n; i++) {
        graph->adj[i] = NULL;}
}
void addEdge(Graph* graph, int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;}
void dfs(Graph* graph, int start, int visited[], FILE* output) {
    visited[start] = 1;
    fprintf(output, "V%d ", start);
    Node* temp = graph->adj[start];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(graph, temp->vertex, visited, output);
        }
        temp = temp->next;}}
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->n; i++) {
        Node* temp = graph->adj[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);}}}
int main() {
    Graph graph;
    int n, m;
    int u, v, w;
    int start;
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    if (!input || !output) {
        printf("Error opening file!\n");
        return 1;}
    fscanf(input, "%d %d", &n, &m);
    initGraph(&graph, n);
    for (int i = 0; i < m; i++) {
        fscanf(input, "%d %d %d", &u, &v, &w);
        addEdge(&graph, u, v, w);
    }
    while (fscanf(input, "%d", &start) == 1 && start != -1) {
        int visited[MAX_NODES] = {0};
        fprintf(output, "DFS From V%d: ", start);
        dfs(&graph, start, visited, output);
        fprintf(output, "\n");
    }
    freeGraph(&graph);
    fclose(input);
    fclose(output);
    printf("DFS results have been written to output.txt\n");
    return 0;
}
