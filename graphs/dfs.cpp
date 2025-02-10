/*
 * This program implements Depth-First Search (DFS) on a graph.
 * The graph is represented using an adjacency list.
 * The program reads the graph from the standard input, performs DFS starting from the first node,
 * and prints the edges visited during the traversal.
 *
 * The program consists of the following main components:
 * 1. Global variables and typedefs: Definitions for convenience and global variables for the graph representation.
 * 2. dfs function: Recursively performs DFS on the graph.
 * 3. main function: Reads the graph input, initializes the necessary data structures, and starts the DFS.
 *
 * To compile the program, use the following command:
 * g++ dfs.cpp -o <executable_name>.bin
 *
 * To execute the compiled program, use the following command:
 * ./<executable_name>.bin
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define UNVISITED -1
#define VISITED 1
#define MAX 100

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;
vii adj_list[MAX];

void dfs(int u){
	dfs_num[u] = VISITED;
	for(int i = 0;i < (int)adj_list[u].size();i ++){
		ii v = adj_list[u][i];
		if(dfs_num[v.first] == UNVISITED){
			printf("Visitei aresta (%d,%d)\n",u,v.first);
			dfs(v.first);
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
		dfs_num.push_back(UNVISITED);
	}
	
	dfs(0);
	
	return 0;
}
