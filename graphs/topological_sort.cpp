/*
 * This program implements Topological Sort on a directed graph using Depth-First Search (DFS).
 * The graph is represented using an adjacency list.
 * The program reads the graph from the standard input, performs Topological Sort,
 * and prints the vertices in topologically sorted order.
 *
 * The program consists of the following main components:
 * 1. Global variables and typedefs: Definitions for convenience and global variables for the graph representation.
 * 2. dfs_ts function: Recursively performs DFS on the graph to generate the topological sort order.
 * 3. main function: Reads the graph input, initializes the necessary data structures, and starts the Topological Sort.
 *
 * To compile the program, use the following command:
 * g++ topological_sort.cpp -o <executable_name>.bin
 *
 * To execute the compiled program, use the following command:
 * ./<executable_name>.bin
 */

#include <cstdio>
#include <vector>
#include <cstring>

#define VISITED 1
#define UNVISITED -1

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> adj_list;
vi ts, dfs_num;

void dfs_ts(int u){
	dfs_num[u] = VISITED;
	for(int i = 0;i < (int)adj_list[u].size();i ++){
		ii v = adj_list[u][i];
		if(dfs_num[v.first] == UNVISITED) dfs_ts(v.first);
	}
	ts.push_back(u);
}

int main(){
	int V,E,s,u,v,w;
	
	scanf("%d %d %d",&V, &E, &s);
	
	adj_list.assign(V,vii());
	for(int i = 0;i < E;i ++){
		scanf("%d %d %d",&u,&v,&w);
		adj_list[u].push_back(ii(v,w));
	}
	
	for(int i = 0;i < V;i ++) dfs_num.push_back(UNVISITED);
	
	ts.clear();
	
	for(int i = 0;i < V;i ++)
		if(dfs_num[i] == UNVISITED) dfs_ts(i);

	for(int i = (int) ts.size() - 1;i >= 0;i --)
		printf("%d ",ts[i]);
	printf("\n");
	
	
	return 0;
}
