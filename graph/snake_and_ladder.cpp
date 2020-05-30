#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    vector<vector<int>> gr(31);
	    
	    for(int i=0;i<n;i++)
	    {
	        int u,v;    cin>>u>>v;    
	        for(int i=1;i<=6 && u-i>=1 ;i++)
	        {
	            gr[u-i].push_back(v);
	        }
	        //gr[u].push_back(v);
	    }
	    for(int i=1;i<30;i++)
	    {
	        for(int j=1;j<=6;j++)
	        {
	            if(i+j > 30)    break;
	            gr[i].push_back(i+j);
	        }
	    }
	    //BFS
	    queue<int> q;
	    q.push(1);
	    int ans = 0;
	    vector<bool> vis(31,false);
	    while(!q.empty())
	    {
	        int siz = q.size();
	        while(siz--)
	        {
	            int node = q.front();   q.pop();
	            if(vis[node])	continue;
	            vis[node] = true;
	            if(node==30){   cout<<ans<<endl; return 0;}
	            for(int x:gr[node])
	                q.push(x);
	        }ans++;
	    }
	}
	return 0;
}