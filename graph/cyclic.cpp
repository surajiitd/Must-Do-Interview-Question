// Detect cycle in an undirected graph
/*
logic: For every visited vertex ‘v’,
if there is an adjacent ‘u’ such that
u is already visited and u is not parent of v,
then there is a cycle in graph.
If we don’t find such an adjacent for any vertex, we say that there is no cycle.

*/
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> g[], vector<bool> &vis,int i,int parent,bool &ans)
{
    if(ans==false)  return;
    //cout<<i<<",";
    for(int x:g[i])
    {
        if(x==parent)    continue;
        if(vis[x]){
            //cout<<"\nfalse on node "<<x<<endl;
            ans = false;    return;
        }
        else
        {
            vis[x] = true;
            DFS(g,vis,x,i,ans);
        }
    }
}
bool isCyclic(vector<int> g[], int V)
{
    vector<bool> vis(V,false);
    bool ans = true;
    for(int i=0;i<V;i++)
    {
        if(!vis[i]){ //cout<<"\ncalling on node "<<i<<endl;
            vis[i] = true;
            DFS(g,vis,i,-1,ans);
        }
    }
    return !ans;
   // Your code here
   
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> g[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<isCyclic(g,n)<<endl;

}