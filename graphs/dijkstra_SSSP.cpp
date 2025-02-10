/*
 * This program implements Dijkstra's algorithm to find the Single Source Shortest Path (SSSP) in a directed, weighted graph.
 * The graph is represented using an adjacency list.
 * The program reads the graph from the standard input, performs Dijkstra's algorithm starting from a specified source node,
 * and prints the shortest path distances from the source node to all other nodes.
 *
 * The program consists of the following main components:
 * 1. Global variables and typedefs: Definitions for convenience and global variables for the graph representation.
 * 2. dijkstra function: Implements Dijkstra's algorithm to find the shortest paths from the source node.
 * 3. main function: Reads the graph input, initializes the necessary data structures, and starts Dijkstra's algorithm.
 *
 * To compile the program, use the following command:
 * g++ dijkstra_SSSP.cpp -o <executable_name>.bin
 *
 * To execute the compiled program, use the following command:
 * ./<executable_name>.bin
 */

#include <cstdio>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

typedef pair< int,int > ii;
typedef vector< ii > vii;
typedef vector< int > vi;

vector<vii> adj_list;
priority_queue< ii,vector<ii>,greater<ii> > pq;
							//^sort the queue by increasing distance from s
							//if I dont specify, the parameter is less<ii>

/*
void dijkstra(int s, vi dist){
	pq.push(ii(0,s));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int cost = front.first, vertex = front.second;
		if(cost > dist[vertex]) continue;
		for(int i = 0;i < (int)adj_list[vertex].size();i ++){
			ii v = adj_list[vertex][i];
			if(dist[vertex] + v.second < dist[v.first]){
				dist[v.first] = dist[vertex] + v.second;
				pq.push(ii(dist[v.first],v.first));
			}
		}
	}
}*/

int main(){
	//obs: the algorithm uses (directed and weighted) graph
	
	int V,E,s,u,v,w;
	
	scanf("%d %d %d",&V,&E,&s);
	
	vi dist(V,INF); //initialize vector dist with V positions with the INF key in each position
	dist[s] = 0; //dist s to s is 0
	
	adj_list.assign(V,vii()); //assign a blank value for all vectors of pair<int,int> to adj_list
	for(int i = 0;i < E;i ++){
		scanf("%d %d %d",&u,&v,&w);
		adj_list[u].push_back(ii(v,w));
	}
	
	//Dijkstra's routine
	//it envolves a implicit breadth-first search
	pq.push(ii(0,s));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int cost = front.first, vertex = front.second;
		if(cost > dist[vertex]) continue; //if is not the minimal, search another
		for(int i = 0;i < (int)adj_list[vertex].size();i ++){
			ii v = adj_list[vertex][i];
			//if the distance already obtained is greater than an alternative path to the same vertex then
			if(dist[vertex] + v.second < dist[v.first]){
				dist[v.first] = dist[vertex] + v.second;
				pq.push(ii(dist[v.first],v.first));
				//push the shortest path obtained, and the vertex for search a another possible shortest path 
			}
		}
	}
	
	//print the distances to the vertex s
	for (int i = 0; i < V; i++)
		printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
	
	return 0;
}