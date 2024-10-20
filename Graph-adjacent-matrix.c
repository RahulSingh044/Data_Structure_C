#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define true 1
#define false 0

void insertEdge(int graph[MAX][MAX], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}


void deleteEdge(int graph[MAX][MAX], int u, int v)
{

    graph[u][v] = 0;
    graph[v][u] = 0;
}


int searchEdge(int graph[MAX][MAX], int u, int v)
{
    return graph[u][v];
}


void bfs(int graph[MAX][MAX], int start){
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while(front < rear){
        int curr = queue[front++];
        printf("%d \t",curr);
        
        for(int i=0; i<MAX; i++){
            if(graph[curr][i] == 1 && !visited[i]){
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int graph[MAX][MAX], int start, int visited[MAX]) {
    visited[start] = true;
    printf("%d \t", start);
    for (int i = 0; i < MAX; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main(){
    int graph[MAX][MAX] = { 0 };


    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 0);
    insertEdge(graph, 2, 3);

    printf("BFS starting from node 2:\n");
    bfs(graph, 2);

    int visited[MAX] = {0};

    printf("DFS starting from node 2:\n");
    dfs(graph, 2, visited);

    return 0;
}
