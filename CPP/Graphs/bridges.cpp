#include<iostream>
#define NODE 5
using namespace std;

int graph[NODE][NODE] = {
   {0, 1, 1, 1, 0},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {0, 0, 0, 1, 0}
};
                               
int min(int a, int b) {
   return (a<b)?a:b;
}
                               
void bridgeFind(int u, bool visited[], int disc[], int low[], int parent[]) {
   static int time = 0;
   visited[u] = true;               //make the first vertex is visited
   disc[u] = low[u] = ++time;  //initialize discovery time and the low time

   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {   //for all vertex v, which is connected with u
         if(!visited[v]) {
            parent[v] = u;    //make u node as parent
            bridgeFind(v, visited, disc, low, parent);
                   
            low[u] = min(low[u], low[v]);    //when subtree from v is connected to one of parent of u node
            if(low[v] > disc[u])
               cout << "Bridge " << u << "--"<<v<<endl;
         } else if(v != parent[u])    //update low of u for previous call
            low[u] = min(low[u], disc[v]);
      }
   }
}

void bridges() {
   bool *vis = new bool[NODE];
   int *disc = new int[NODE];
   int *low = new int[NODE];
   int *parent = new int[NODE];
   
   for(int i = 0; i<NODE; i++) {
      vis[i] = false;    //no node is visited
      parent[i] = -1;    //initially there is no parent for any node
   }
   
   for(int i = 0; i<NODE; i++)
      if(!vis[i])    //if any node is unvisited, the graph is not connected
         bridgeFind(i, vis, disc, low, parent);
}

int main() {
   cout << "Bridges in given graph:"<<endl;
   bridges();
}