
/* This is solution for the program listed on hackerrank.com
 * URL : https://www.hackerrank.com/challenges/bfsshortreach
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define NOV 1002

using namespace std;

int bfsAlgo(){
	int numOfVertices, numOfEdges;
    int x, y, start, distance=1, front, currVertex;
	vector<int> vertex[NOV];
	queue<int> vQueue;
	int visited[NOV];

	// making all the visited -1. -1 signifies that the vertices can't be reaced.
	memset(visited, -1, sizeof(visited));

	// Scanning n:number of vertices and m:number of edges
	cin>> numOfVertices >> numOfEdges;

	// Adding the edges for the undirected graph
	for(int i = 1; i <= numOfEdges; i++){
		cin>> x >> y;
		vertex[x].push_back(y);
		vertex[y].push_back(x);
	}
	// Getting the starting vertex
	cin>> start;

	// print the summary of each vertex in this form
	// vertext-name(degree of it): vertices connected with given vertex
	for(int i = 1; i <= numOfVertices; i++){
		cout<< i << "(" << vertex[i].size() << ") :";
		for(int j = 0; j < vertex[i].size(); j++){
			cout<< vertex[i][j] << " ";
		}
		cout<< endl;
	}

	// The BFS algorithm
	// -1 is being used as a level partioner in the queue of visited vertices
	// If -1 is in the front, the distance is increased and -1 is again
	// pushed to signify the next level
	vQueue.push(start); visited[start] = 0;
	vQueue.push(-1);
	while(!vQueue.empty()){
		front = vQueue.front(); vQueue.pop();
		for(int i = 0; i < vertex[front].size(); i++){
			currVertex = vertex[front][i];
			if(visited[currVertex] == -1){
				vQueue.push(currVertex);
				visited[currVertex] = distance;
			}
		}
		if(vQueue.front() == -1){
			distance++;
			vQueue.pop();
			vQueue.push(-1);
		}
	}
	cout<< "\n";

	for(int i = 1; i <= numOfVertices; i++){ cout<< i << " - " << visited[i] << "\n"; }

	cout<< "\n";
	for(int i = 1; i <= numOfVertices; i++){
		if( i != start){
			if( visited[i] != -1)
				cout<< visited[i]*6 << " ";
			else
				cout<< visited[i] << " ";
		}
	}
	//cout << "Empty: " <<  bool(vQueue.empty()) << endl;

	cout<< "\n";
	cout<< "\n";
	cout<< "\n";
	return 0;
}

int main(){
	int t;

	cin>> t;
	for(int i = 0; i < t; i++){ bfsAlgo(); }
	return 0;
}
