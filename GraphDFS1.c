#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
typedef struct {
    int n;
    int adj[MAX_NODES][MAX_NODES];
} Graph;
void initGraph(Graph* graph, int n) {
    graph->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->adj[i][j] = 0;
        }
    }
}
void addEdge(Graph* graph, int u, int v, int w) {
    graph->adj[u][v] = w;
}
void dfs(Graph* graph, int start, int visited[], FILE* output) {
    visited[start] = 1;
    fprintf(output, "V%d ", start);

    for (int i = 0; i < graph->n; i++) {
        if (graph->adj[start][i] != 0 && !visited[i]) {
            dfs(graph, i, visited, output);
        }
    }
}

int main() {
    Graph graph;
    int n, m; // 顶点数和弧数
    int u, v, w; // 边的起点、终点和权值
    int start; // 起始顶点
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    if (!input || !output) {
        printf("Error opening file!\n");
        return 1;
    }
    fscanf(input, "%d %d", &n, &m);
    initGraph(&graph, n);
    for (int i = 0; i < m; i++) {
        fscanf(input, "%d %d %d", &u, &v, &w);
        addEdge(&graph, u, v, w);
    }
    while (fscanf(input, "%d", &start) == 1 && start != -1) {
        int visited[MAX_NODES] = {0}; // 初始化访问标记数组
        fprintf(output, "DFS From V%d: ", start);
        dfs(&graph, start, visited, output);
        fprintf(output, "\n");
    }
    fclose(input);
    fclose(output);
    printf("DFS results have been written to output.txt\n");
    return 0;
}
