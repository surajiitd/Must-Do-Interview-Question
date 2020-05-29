#include<bits/stdc++.h>
using namespace std;
/*
vector <int> dfs(vector<int> g[], int N)
{
	stack<int> st;
	vector<int> vis(N,0);
	vector<int> ans;
	st.push(0);
	while(!st.empty())
	{
		int node  = st.top();
		st.pop();
		ans.push_back(node);
		vis[node] = 1;
		for(int i=0;i<g[node].size();i++)
		{
			int nw = g[node][i]; 
			if(vis[nw]==0)
				st.push(nw);
		}
	}   
    return ans;
    // Your code here

}*/
void DFS(vector<int> g[],vector<bool> &vis,vector<int> &ans,int i)
{
    ans.push_back(i);
    for(int j=0;j<g[i].size();j++)
    {
    	int nw = g[i][j];
        if(!vis[nw])
        {
            vis[nw] = true;
            DFS(g,vis,ans,nw);
        }
    }

}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> g[n];
	vector<bool> vis(n,false);
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> ans;
	vis[0] = true;
	DFS(g,vis,ans,0);
	for(auto x:ans)
		cout<<x<<",";

}