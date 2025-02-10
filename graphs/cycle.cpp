/*
 * This program implements a Depth-First Search (DFS) to detect cycles in a directed graph.
 * The graph is represented using an adjacency list.
 * The program reads the graph from the standard input, performs DFS starting from a specified node,
 * and prints whether a cycle is detected in the graph.
 *
 * The program consists of the following main components:
 * 1. Global variables and typedefs: Definitions for convenience and global variables for the graph representation.
 * 2. dfs_cycle function: Recursively performs DFS on the graph to detect cycles.
 * 3. main function: Reads the graph input, initializes the necessary data structures, and starts the DFS.
 *
 * To compile the program, use the following command:
 * g++ cycle.cpp -o <executable_name>.bin
 *
 * To execute the compiled program, use the following command:
 * ./<executable_name>.bin
 */

#include <cstdio>
#include <vector>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef pair< int,int > ii;
typedef vector< ii > vii;
typedef vector< int > vi;

vector< vii > adj_list;
vi dfs_num; 

// Depth-First Search (DFS) function to detect cycles in the graph
void dfs_cycle(int u, bool *cycle) {
    dfs_num[u] = VISITED; // Mark the current node as visited
    for (int i = 0; i < (int) adj_list[u].size(); i++) {
        ii v = adj_list[u][i]; // Get the adjacent node
        if (dfs_num[v.first] == UNVISITED) {
            dfs_cycle(v.first, cycle); // Recursively visit the adjacent node
        } else {
            *cycle = true; // If an already visited node is found, a cycle exists
        }
    }
}

int main(){
	int V, E, s, u, v, w;
	bool cycle = false;
	
	scanf("%d %d %d",&V, &E, &s);
	
	adj_list.assign(V,vii());
	for(int i = 0; i < E; i ++){
		scanf("%d %d %d",&u,&v,&w);
		adj_list[u].push_back(ii(v, w));
	}
	
	for(int i = 0; i < V; i ++){
		printf("v%d: ", i);
		for(int j = 0;j < (int) adj_list[i].size(); j ++){
			ii v = adj_list[i][j];
			printf("v%d; ", v.first);
		}
		printf("\n");
	}
	
    // Initialize the visit status of each node as unvisited
	for(int i = 0; i < V; i ++) dfs_num.push_back(UNVISITED);
	
	dfs_cycle(s, &cycle);

    // Print whether a cycle was detected
	(cycle ? printf("SIM\n") : printf("NAO\n"));

	return 0;
}
