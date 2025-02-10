/*
 * This program implements Breadth-First Search (BFS) on a graph.
 * The graph is represented using an adjacency list.
 * The program reads the graph from the standard input, performs BFS starting from the first node,
 * and prints the vertices visited during the traversal.
 *
 * The program consists of the following main components:
 * 1. Global variables and typedefs: Definitions for convenience and global variables for the graph representation.
 * 2. lsearch function: Checks if a vertex is present in the queue.
 * 3. bfs function: Performs BFS on the graph.
 * 4. main function: Reads the graph input, initializes the necessary data structures, and starts the BFS.
 *
 * To compile the program, use the following command:
 * g++ bfs.cpp -o <executable_name>.bin
 *
 * To execute the compiled program, use the following command:
 * ./<executable_name>.bin
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>

#define UNVISITED -1
#define VISITED 1
#define MAX 100

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii>vii;
typedef vector<int> vi;

vi bfs_num;
vii adj_list[MAX];

queue<int> q;

bool lsearch(int k){
	queue<int> c (q);
	for(unsigned int i = 0;i < c.size();i ++){
		if(c.front() == k) return true;
		c.pop();
	}
	return false;
}

void bfs(int u){
	printf("Visitei vertice (%d)\n",u);
	bfs_num[u] = VISITED;
	q.push(u);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0;i < (int)adj_list[v].size();i ++){
			ii x = adj_list[v][i]; 
			if(bfs_num[x.first] == UNVISITED){
				printf("Visitei vertice (%d)\n",x.first);
				bfs_num[x.first] = VISITED;
				q.push(x.first);
			}else if(lsearch(x.first)){
				//printf("visitei vertice (%d)\n",x.first);
			}
		}
	}
}

int main(){
	ii v;
	int length;
	cin >> length;
	for(int i = 0;i < length;i ++){
		int neighbors;
		cin >> neighbors;
		for(int j = 0;j < neighbors;j ++){
			cin >> v.first >> v.second;
			adj_list[i].push_back(v);
		}
		bfs_num.push_back(UNVISITED);
	}
	
	bfs(0);
	
	return 0;
}
