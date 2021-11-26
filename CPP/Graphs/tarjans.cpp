#include<iostream>
#include<stack>
#define NODE 8
using namespace std;
int graph[NODE][NODE] = {
   {0, 0, 1, 0, 0, 0, 0, 0},
   {1, 0, 0, 0, 0, 0, 0, 0},
   {0, 1, 0, 1, 0, 0, 0, 0},
   {0, 0, 0, 0, 1, 0, 0, 0},
   {0, 0, 0, 0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0, 0, 1, 0},
   {0, 0, 0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 1, 0, 0, 0}
};
int min(int a, int b) {
   return (a<b)?a:b;
}
void strongUtil(int u,int low[],int disc[],stack<int>&stk,bool stkMember[]){
	static int time=0;
	low[u]=disc[u]=++time;
	stkMember[u]=true;
	stk.push(u);
	for(int v=0;v<NODE;v++){
		if(graph[u][v]){
			if(disc[v]==-1){
				strongUtil(v,low,disc,stk,stkMember);
				low[u]=min(low[u],low[v]);
			}else if(stkMember[v]==true){
				low[u]=min(low[u],disc[v]);
			}
		}
	}
	int popMember=0;
	if(disc[u]==low[u]){
		while(stk.top()!=u){
			popMember=stk.top();
			cout<<popMember<<" ";
			stkMember[popMember]=false;
			stk.pop();
		}
		popMember=stk.top();
		cout<<popMember<<endl;
		stkMember[popMember]=false;
		stk.pop();
	}
}
void strongConComponent(){
	int low[NODE];
	int disc[NODE];stack<int>stk;
	bool stkMember[NODE];
	for(int i=0;i<NODE;i++){
		low[i]=disc[i]=-1;
		stkMember[i]=false;
	}
	for(int i=0;i<NODE;i++){
		if(disc[i]==-1){
			strongUtil(i,low,disc,stk,stkMember);
		}
	}
}
int main() {
   strongConComponent();
}