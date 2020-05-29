#include<bits/stdc++.h>
using namespace std;
vector <int> bfs(vector<int> g[], int N) {
    queue<int> q;
    q.push(0);
    vector<int> vis(N,0);
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(vis[node])   continue;
        vis[node] = 1;
        ans.push_back(node);
        for(int i=0;i<g[node].size();i++)
        {
            int nw = g[node][i];
            if(vis[nw] == 0)    q.push(nw);
        }
        
    }
    return ans;
    
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
    
    vector<int> ans = bfs(g,n);
    for(auto x:ans)
        cout<<x<<",";

}
/*
surajpatni@s:~/Documents/Must-Do-Interview-Question/graph$ ./a.out
5 4
0 1
0 2
0 3   
2 4
0,1,2,3,4,
*/
