#include<iostream>
#include<stack>
#define NODE 6
#define INF 9999

using namespace std;

int cost[NODE][NODE] = {
   {0, 5, 3, INF, INF, INF},
   {INF, 0, 2, 6, INF, INF},
   {INF, INF, 0, 7, 4, 2},
   {INF, INF, INF, 0, -1, 1},
   {INF, INF, INF, INF, 0, -2},
   {INF, INF, INF, INF, INF, 0}
};

void topoSort(int u, bool visited[], stack<int>&stk) {
   visited[u] = true;       //set as the node v is visited
   for(int v = 0; v<NODE; v++) {
      if(cost[u][v]) {       //for allvertices v adjacent to u
         if(!visited[v])
            topoSort(v, visited, stk);
      }
   }

   stk.push(u);       //push starting vertex into the stack
}

void shortestPath(int start) {
   stack<int> stk;
   int dist[NODE];

   bool vis[NODE];
   for(int i = 0; i<NODE;i++)
      vis[i] = false;          // make all nodes as unvisited at first

   for(int i = 0; i<NODE; i++)     //perform topological sort for vertices
      if(!vis[i])
         topoSort(i, vis, stk);

   for(int i = 0; i<NODE; i++)
      dist[i] = INF;       //initially all distances are infinity
   dist[start] = 0;       //distance for start vertex is 0

   while(!stk.empty()) {    //when stack contains element, process in topological order
      int u = stk.top(); stk.pop();

      if(dist[u] != INF) {
         for(int v = 0; v<NODE; v++) {
            if(cost[u][v] && cost[u][v] != INF){ 
				if(dist[v] > dist[u] +cost[u][v]){
					dist[v] = dist[u] + cost[u][v];
				}
         }
      }
   }
   for(int i = 0; i<NODE; i++)
      (dist[i] == INF)?cout << "Infinity ":cout << dist[i]<<" ";
}
}

main() {
   int start = 1;
   cout << "Shortest Distance From Source Vertex "<<start<<endl;
   shortestPath(start);
}