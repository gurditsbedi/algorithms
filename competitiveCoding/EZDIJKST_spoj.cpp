#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>

using namespace std;

// This number is very close to INT_MAX. Written in Hexadecimal
// 7FFFFFF  in hexadecimal = 2147483646 in decimal
#define INF 0x7FFFFFFE

typedef pair<int, int> iPair;

// Finds minimum distance from the source node to all the nodes.
void dijskstra() {
    // V -> Number of Vertices and E -> Number of Edges
    // src -> source node
    int V, E, src, dest, done = -1;

    // Pointer to the array containg adjacenccy lists
    // taking a little more memory than the required one.
    list<iPair> adj[10009];

    // min-priority queue
    priority_queue< iPair, vector<iPair>, greater<iPair> > pq;

    // Taking input V and E;
    cin >> V >> E;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> distance(V+1, INF);

    // Adding directed of weightage 'd'
    for (int i = 0; i < E; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back(make_pair(d,v));
    }

    cin >> src >> dest;

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    distance[src] = 0;

    /* Looping till priority queue becomes empty (or all
          distances are not finalized) */
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<iPair>:: iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); ++i) {

            // Get vertex label and weight of current adjacent of u.
            int weight = (*i).first;
            int v = (*i).second;

            //  If there is shorted path to v through u.
            if( distance[v] > distance[u] + weight){
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
        // Print the distance and exiting from the loop
        if( u == dest) {
            cout << distance[dest] << endl;
            done = 0;
            break;
        }
    }

    // If the destination was unreacable then
    // this statments execute
    if(done != 0) cout << "NO" << endl;
}

int main()
{
    int t;


    cin >> t;
    // Finds minimum Distance from the source node to all the nodes.
    for (int i = 0; i < t; i++) dijskstra();

    return 0;
}
