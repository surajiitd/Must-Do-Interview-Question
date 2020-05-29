#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &a,int i,int j,int flag)
{
	int v = a.size();
	if(i<0 || i>v-1 || j<0 || j>v-1)	return false;
    if(a[i][j]==2)  return true;
    if(a[i][j]==0 || a[i][j]==1 && flag )  return false;
    a[i][j] = 0;	//block the cell from where we explored once.
    return dfs(a,i+1,j,1)||dfs(a,i,j+1,1)||dfs(a,i-1,j,1)||dfs(a,i,j-1,1);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int v;
	    cin>>v;
	    vector<vector<int>> a(v,vector<int>(v));
	    int di,dj;
	    for(int i=0;i<v;i++)
	    {
	        for(int j=0;j<v;j++)
	        {
	            cin>>a[i][j];
	            if(a[i][j] == 1)
	            {
	                di=i,dj=j;
	            }
	        }
	    }
	    cout<<dfs(a,di,dj,0)<<endl;
	}
	return 0;
}