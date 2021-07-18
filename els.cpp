CODE FOR ELS
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
cout<<"("<<entry.first<<","<<entry.second<<")";
}
cout<<endl;
}
}
void ELS(){
/*OPEN ←sinit
while OPEN a!=∅ do
s←headOf(OPEN)
if s complete state then
return optimal solution s
end-if
Expand s to new states NEW
for all si belongs to NEW do
Calculate f(si)
Insert si into OPEN, unless duplicate in CLOSED or OPEN
end-for
CLOSED ←CLOSED + s; OPEN←OPEN - s
end-while
*/
}
int heuristic(){
// max. of idle-time, bottom-level, data-ready time
// calculating the computational weightage for idle-time calculation
// use traversal technique to calculate--complete it using BFS
queue<int> q;
// Assume starting node equal to one
int src=1;
map<int,bool> visited;
map<int,int> parent;
q.push(src);
visited[src]=true;
parent[src]=0;
long long int total_comp=0;
for(int i=1;i<=n;i++){
total_comp +=computation_cost[i];
}
while(!q.empty()){
int node=q.front();
cout<<node<<" ";
q.pop();
// Neighbors of current node
for(int Neighbour:adjlist[node]){
if(!visited[Neighbour]){
q.push(Neighbour);
visited[Neighbour]=true;
parent[Neighbour]=node;
}
}
}
//for calculation of bottom we from current node to goal node recursively with data-ready time.
}
};
class state{
// This contains the list of the task associated with each of the processor
public:
int proc_list[11][11];
};
// This contains the open and closed list used in the implementation of ELS
vector<state> open;
vector<state> closed;
bool dulplicates(state s1,state s2){
// Before checking for duplicates we need to normalize both the states .
// This normalising is done by sorting individual processors according to no. of task
//checking same entries
for(int i=1;i<=10;i++){
for(int j=1;j<=10;i++){
if(s1.proc_list[i][j]!=s2.proc_list[i][j]){
return false;
}
}
}
return true;
}
// Functor for comparision in fork graph maintaining ascending order
bool mycompare(pair<int,int> a, pair<int,int> b){
if(a.second<b.second){
return true;
}
return false;
}
// Functor for maintaining descending order in join graph
bool mycompare2(pair<int,int> a, pair<int,int> b){
if(a.second>b.second){
return true;
}
return false;
}
void pruning(){
//fixed task order
//equivalent states
//heuristic
//identical task scheduling--maintain a parent array while traversing.
// if task graph is fork
sort(adjlist[src],adjlist[src]+n-1,mycompare);
// if graph is join
sort(adjlist[src],adjlist[n-1],mycompare2);
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