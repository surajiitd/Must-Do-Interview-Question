#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

vector<vector<int>> dp;
int mc(vector<vector<int>> &a,vector<vector<bool>> &vis,int i,int j)
{
    int n = a.size();
    if(i<0 || i>n-1|| j<0 || j>n-1 || vis[i][j]) return MAX;
    if(i==n-1 && j==n-1)    return a[i][j];
    if(dp[i][j] != -1)  return dp[i][j];
    you
    int d[] = {0,1,0,-1,0};
    int min = MAX;
    vis[i][j] = true;
    for(int x=0;x<4;x++)
    {
        int curr = mc( a,vis,i+d[x],j+d[x+1] );
        if(min > curr) min = curr;
    }
    vis[i][j] = false;
    //dp[i][j] = a[i][j] + min(mc(a,i+1,j),mc(...),.....);
    return dp[i][j] = a[i][j] + min;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    dp.clear();
	    dp.resize(n,vector<int>(n,-1));
	    vector<vector<int>> a(n,vector<int>(n));
	    for(auto &x:a)
	        for(auto &y:x)  cin>>y;
	    vector<vector<bool>> vis(n,vector<bool>(n,false));
	    cout<<mc(a,vis,0,0)<<endl;
	}
	return 0;
}