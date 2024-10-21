#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int q[MAX];
bool visited[MAX] = {0};
int G[MAX][MAX];
int front = 0;
int rear = 0;

void push(int data)
{
    q[front++] = data;
}

int pop()
{
    return q[rear++];
}

bool isEmpty()
{
    return (front == rear);
}
void bfs(int node, int edge, int start)
{
    push(start);
    while (!isEmpty())
    {
        int u = pop();
        if (!visited[u])
        {
            visited[u] = true;
            printf("%d ", u);
            for (int v = 1; v <= node; v++)
            {
                if (G[u][v] && !visited[v])
                {
                    push(v);
                }
            }
        }
    }
}

int main()
{
    int node, edge;
    scanf("%d %d", &node, &edge);
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
    }
    bfs(node, edge, 1);
}