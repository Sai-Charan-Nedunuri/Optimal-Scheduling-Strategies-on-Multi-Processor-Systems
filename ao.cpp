CODE FOR AO
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
map<T,list<pair<T,int>>> adjlist;
public: Graph(){
}
void addedge( T u, T v,int comm ,bool bidir=true){
adjlist[u].push_back(make_pair(v,comm));
if(bidir==true){
adjlist[v].push_back(make_pair(u,comm));
}
}
void print(){
//Iterate over the map
for(auto i:adjlist){
cout<<i.first<<"->";
//i.second is linked list
for(auto entry :i.second){
cout<<"("<<entry.first<<","<<entry.second<<")"; } cout<<endl; } } void AO(){ } int heuristic(){ } }; // Graph reserval novel pruning technique -- modification still needed class reserval { public: void eventualSafeNodes(vector<vector<int>>& graph){ int n=graph.size(); unordered_map<int,vector<int>> next; unordered_map<int,int> odegree; unordered_map<int,bool> visited; for (int i=0;i<n;++i){ odegree[i]=graph[i].size(); visited[i]=false; for (auto j:graph[i]) next[j].push_back(i); } } vector<int> topological_sort(vector<vector<int>>& graph){ vector<int> ans; while (true){ bool flag=false; for (int i=0;i<n;++i) if (odegree[i]==0 && !visited[i]){ flag=true; visited[i]=true; ans.push_back(i);
for (auto j:next[i]) --odegree[j]; } if (!flag) break; } sort(ans.begin(),ans.end()); return ans; } }; // Finding the critical path in the directed graph vector<int> order; void topo(int src,vector<int> &vis,vector<vector<pair<int,int> > > g){ vis[src] = 1; for(auto x:g[src]){ if(!vis[x.first]) topo(x.first,vis,g); } order.push_back(src); } void critical_path(){ vector<int> vis(v,0); for(int i=0;i<v;i++){ if(!vis[i]){ topo(i,vis,g); } } vector<int> dist(v); for(int i=0;i<v;i++) dist[i] = INT_MIN; dist[src] = 0; for(int i=v-1;i>=0;i--){ if(dist[order[i]]!=INT_MIN){ for(auto x:g[order[i]]){ int v = dist[x.first]; int w = x.second; int u = dist[order[i]]; if(u + w > v) dist[x.first] = u + w; } } } for(int i=0;i<v;i++){
if(i!=src and dist[i]!=INT_MIN){
cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
}
}
}
map<int,int> computation_cost;
int no_of_processors;
int main() {
Graph<int> g;
g.addedge(1,2,1);
g.addedge(1,3,4);
g.addedge(2,3,1);
g.addedge(3,4,2);
g.addedge(1,4,7);
g.print();
int n;
cout<<"enter the no. of individual nodes";
cin>>n;
for(int i=1;i<=n;i++){
int p;
cin>>p;
computation_cost[i]=p;
}
/* Another representation of the task graph using matrix
int n,comm,comp;
pair<int,int> task_graph[n+1][n+1];
cout<<"enter the no. of task"<<endl;
for(int i=1;i<=n;i++ ){
for(int j=1;j<=n;j++){
//Enter the computation cost and the communication cost
cin>>comp>>comm;
task_graph[i][j]=make_pair(comp,comm);
}
}
*/
cout<<"Enter the no. of processors "<<endl;
cin>>no_of_processors;
// Finding no. of free tasks
return 0;
}