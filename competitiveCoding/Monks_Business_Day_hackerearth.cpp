#include <iostream>
#include <cstring>

using namespace std;
#define INF 0x3f3f3f3f

// To store and edge
typedef struct edge {
    int u, v, w;
} Edge;

int businessday()
{
    // E -> Number Of Edges. src = 1 (given)
    int V, E, src = 1;
    // variable to represent a graph
    int u, v, w;

    // Taking input V and E;
    cin >> V >> E;

    // List to store edges using array of structs, distance array and
    // positiveLoop array(nodes which have positive self loop are
    // marked with 0 else -1 )
    Edge edgeList[E];
    int distance[V+1];
    int positiveLoop[V+1];

    for (int i = 0; i < V+1; i++) positiveLoop[i] = -1;

    // Adding directed edge of weightage 'w'
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        // marking the loops with positive self edges
        if (u == v && w > 0) positiveLoop[u] = 0;
        w = -w;
        edgeList[i].u = u; edgeList[i].v = v; edgeList[i].w = w;
    }

    // Intialize Single Source Graph
    for (int i = 0; i < V+1; i++) distance[i] = INF;
    distance[src] = 0;

    // Bellman–Ford relaxtion loop
    for (int i = 1; i < V-1; i++) {
        for (int j = 0; j < E; j++) {
            u = edgeList[j].u;
            v = edgeList[j].v;
            w = edgeList[j].w;
            if (u != v) {
                if (distance[u] != INF && distance[v] > distance[u] + w)
                    distance[v] = distance[u] + w;
            }
        }
    }

    // If a node with positive self loop is reachable from the
    // start node, we return 0 (success)
    for (int i = 1; i < V+1; i++) {
        if ( distance[i] != INF && positiveLoop[i] == 0)
            return 0;
    }

    // Bellman–Ford negative cycle checking loop
    for (int i = 1; i < V-1; i++) {
        for (int j = 0; j < E; j++) {
            u = edgeList[j].u;
            v = edgeList[j].v;
            w = edgeList[j].w;
            if (u != v) {
                if (distance[u] != INF && distance[v] > distance[u] + w){
                    return 0;
                }
            }
        }
    }

    return -1;
}

int main()
{
    int T, returnValue;
    cin >> T;

    for (int i = 0; i < T; i++) {
        returnValue = businessday();
        if (returnValue == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
