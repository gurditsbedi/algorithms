#include <cstdio>
#include <list>
#include <queue>
#include <utility>

using namespace std;
// This number is very close to INT_MAX. Written in Hexadecimal
// 7FFFFFF  in hexadecimal = 2147483647 in decimal
#define INF 0x7FFFFFFE
// Maxmium Number of vertices in the graph
#define MAXV 10001

typedef pair<int, int> iPair;

// Graph and number of vertices
list<iPair> adj[MAXV];
int V;

// Returns a <vector> of minimum distance from the source node to all the nodes.
vector<int> dijkstrasAllNodes(int src)
{
    // min-priority queue
    priority_queue< iPair, vector<iPair>, greater<iPair> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> distance(V+1, INF);

    // Insert source itself in priority queue and initialize its distance as 0.
    pq.push(make_pair(0, src));
    distance[src] = 0;

    // Looping till priority queue becomes empty (or all
    //      distances are not finalized)
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<iPair>:: iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++) {

            // Get vertex label and weight of current adjacent of u.
            int weight = (*i).first;
            int v = (*i).second;
            //  If there is shorted path to v through u.
            if (distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    return distance;
}

// Scans Neccesary Data, and implements the logic for the problem
int scrtservice(){
    // E -> Number Of Edges. S, A, H according to the problem
    // minTime is the answer
    int E, S, A, H;
    int minTime = 0;

    // Taking input V and E;
    scanf("%d %d", &V, &E);

    // Adding undirected of weightage 'd'
    for (int i = 1; i <= E; i++) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        adj[u].push_back(make_pair(d,v));
        adj[v].push_back(make_pair(d,u));
    }
    scanf("%d %d %d", &S, &A, &H);

    // Creating distance <vector> and feeding them
    vector<int> sumOfDistance(V+1, 0);
    vector<int> sourceDistance = dijkstrasAllNodes(S);
    vector<int> townhallDistance = dijkstrasAllNodes(H);
    vector<int> ammunitionDistance = dijkstrasAllNodes(A);

    // Calculating time taken by each group to perform the 4 given objectives
    for (int i=1; i < V+1; i++) {
        sumOfDistance[i] = sourceDistance[i] + 2*ammunitionDistance[i] + townhallDistance[i];
        // Just a safety check. Preventing non enemy building
        // to interfere in the minTime Calculation
        sumOfDistance[S] = 0; sumOfDistance[A] = 0; sumOfDistance[H] = 0;
        if (sumOfDistance[i] > minTime) minTime = sumOfDistance[i];
    }

    printf("%d\n", minTime);
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scrtservice();
        // clearing the graph
        for (int i = 1; i < V+1; i++) adj[i].clear();
    }
    return 0;
}
