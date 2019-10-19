#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;

    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}

bool isNegCycleBellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return true;
    }

    return false;
}

int main()
{
    int V = 5;
    int E = 8;
    cin>> V >> E;
    struct Graph* graph = createGraph(V, E);

    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph->edge[a-1].src = a-1;
        graph->edge[a-1].dest = b-1;
        graph->edge[a-1].weight = c;
    }

    if (isNegCycleBellmanFord(graph, 0))
        cout << 1;
    else
        cout << 0;

    return 0;
}
