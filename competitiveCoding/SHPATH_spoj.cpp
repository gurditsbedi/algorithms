#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#include <map>
#include <cstdio>

using namespace std;

#define INF 0x3f3f3f3f
#define LEN 16

typedef pair<int, int> iPair;

// Finds minimum distance from the source node to all the nodes.
void dijskstra()
{
    // V -> Number of Vertices and E -> Number of Edges
    // src -> source node
    int V, src, dest, times;
    // city names to be stored here
    char srcstr[LEN], deststr[LEN], nodestr[LEN];

    // using list to link node number(list index number) and city name
    map<string, int> M;

    // Pointer to the array containg adjacenccy lists
    // taking little more memory than required.
    list<iPair> adj[10009];

    // Taking input V
    scanf("%d", &V);

    // Adding undirected of weightage 'd'
    for (int i = 1; i <= V; i++) {
        int Efori;
        scanf("%s", nodestr);
        scanf("%d", &Efori);
        M[nodestr] = i;
        for (int j = 1; j <= Efori; ++j) {
            int d,v;
            scanf("%d %d", &v, &d);
            adj[i].push_back(make_pair(d, v));
        }
    }

    scanf("%d", &times);
    for (int a = 0; a < times; ++a) {
        // min-priority queue
        priority_queue< iPair, vector<iPair>, greater<iPair> > pq;

        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> distance(V+1, INF);

        // scaning source and destination city names and also
        // assigning corresponding node number to src and dest
        scanf("%s %s", srcstr, deststr);
        src = M[srcstr];
        dest = M[deststr];

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
                    // printf("distance: %d\n", distance[dest]);
                    printf("%d\n", distance[dest]);
                    break;
                }
        }
    }
}


int main()
{
    int t;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) dijskstra();

    return 0;
}
