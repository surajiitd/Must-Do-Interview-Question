#include<bits/stdc++.h>
using namespace std;

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool DFS(vector<int> g[],vector<bool> &vis,int i)
{
    for(int x:g[i])
    {
        if(vis[x])  return true;
        else
        {
            vis[x] = true;
            if(DFS(g,vis,x))    return true;
            vis[x] = false;
        }
    }
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    //bool ans = true;
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i]){
            vis[i] = true;
            if(DFS(adj,vis,i))
                return true;
            vis[i] = false;
        }
    }
    return false;
    
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
    }
    cout<<isCyclic(n,g)<<endl;

}