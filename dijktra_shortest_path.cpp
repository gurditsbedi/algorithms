/* Implementation of dijkstra's algorithm to find shortest path.
 *
 * dijkstrasAllNodes: find shortest path from source
 *          all the vertices.
 * dijkstras: finds shortest path from source to
 *            destination.
 * Both the methods also print the paths.
 */

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

// This number is very close to INT_MAX. Written in Hexadecimal
// 7FFFFFF  in hexadecimal = 2147483646 in decimal
#define INF 0x7FFFFFFE
// Maxmium Number of vertices in the graph
#define MAXV 10001

typedef pair<int, int> iPair;

void printPath(int node, int parent[])
{
    if( parent[node] == -1) return;
    printPath(parent[node] , parent );
    cout << node << " ";
}

// Finds minimum distance from the source node to all the nodes.
void dijkstrasAllNodes()
{
    // V -> Number of Vertices and E -> Number of Edges
    // src -> source node
    int V, E, src;

    // Pointer to the array containg adjacenccy lists
    list<iPair> adj[MAXV];

    // min-priority queue
    priority_queue< iPair, vector<iPair>, greater<iPair> > pq;

    // Taking input V and E;
    cin >> V >> E;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> distance(V, INF);

    // To be used in finding of the the minimum path
    // An array to store the parent of the vertex.
    int parent[MAXV];
    memset(parent, -1, sizeof(parent)/sizeof(parent[0]));

    // Adding undirected of weightage 'd'
    for (int i = 0; i < E; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back(make_pair(d,v));
        adj[v].push_back(make_pair(d,u));
    }

    cin >> src;

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    distance[src] = 0;

    /* Looping till priority queue becomes empty (or all
          distances are not finalized) */
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<iPair>:: iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {

            // Get vertex label and weight of current adjacent of u.
            int weight = (*i).first;
            int v = (*i).second;
            //  If there is shorted path to v through u.
            if ( distance[v] > distance[u] + weight){
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    cout << "Vertex   Distance from Source   Path from the source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << " \t\t " << distance[i];
        cout << "\t\t\t0 ";
        printPath(i, parent);
        cout << endl;
    }
}

// Finds minimum distance from the source node to destination node.
void dijkstra()
{
    // V -> Number of Vertices and E -> Number of Edges
    // src -> source node and dest -> destination node
    int V, E, src, dest;

    // Pointer to the array containg adjacenccy lists
    list<iPair> adj[MAXV];

    // min-priority queue
    priority_queue< iPair, vector<iPair>, greater<iPair> > pq;

    // Taking input V and E;
    cin >> V >> E;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> distance(V, INF);

    // To be used in finding of the the minimum path
    // An array to store the parent of the vertex.
    int parent[MAXV];
    memset(parent, -1, sizeof(parent)/sizeof(parent[0]));

    // Adding undirected of weightage 'd'
    for (int i = 0; i < E; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back(make_pair(d,v));
        adj[v].push_back(make_pair(d,u));
    }

    cin >> src >> dest;

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    distance[src] = 0;

    /* Looping till priority queue becomes empty (or all
          distances are not finalized) */
    while (!pq.empty()){
        int u = pq.top().second;
        if ( u == dest) {
            cout << "Source:\t\t" << src << endl;
            cout << "Destination:\t" << dest << endl;
            cout << "Distance:\t" << distance[u] << endl;
            cout << "Path:\t\t0 ";
            printPath(dest, parent);
            cout << endl;
            break;
        }
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<iPair>:: iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {

            // Get vertex label and weight of current adjacent of u.
            int weight = (*i).first;
            int v = (*i).second;

            //  If there is shorted path to v through u.
            if (distance[v] > distance[u] + weight){
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
}


int main()
{
    int t;

    cin >> t;
    // Finds minimum Distance from the source node to all the nodes.
    for (int i = 0; i < t; i++) dijkstra();

    return 0;
}

/* Sample Test For dijkstrasAllNodes
input:
1
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
output:
Vertex   Distance from Source   Path from the source
0        0          0
1        4          0 1
2        12         0 1 2
3        19         0 1 2 3
4        21         0 7 6 5 4
5        11         0 7 6 5
6        9          0 7 6
7        8          0 7
8        14         0 1 2 8
*/


/* Sample Test For dijkstra
input:
1
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0 4
output:
Source:     0
Destination:    4
Distance:   21
Path:       0 7 6 5 4
*/