#include<bits/stdc++.h>
using namespace std;
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   a: input vector of vector.
*   n, m: Row and column of given matrix
*/

void DFS(vector<vector<int>> &a,int i,int j)
{
    int n=a.size(),m = a[0].size();
    if(i<0 || i>n-1 || j<0 || j>m-1 || a[i][j]==0)  return;

    a[i][j] = 0;
    DFS(a,i+1,j);DFS(a,i,j+1);DFS(a,i-1,j);DFS(a,i,j-1);
    DFS(a,i+1,j+1);DFS(a,i-1,j-1);DFS(a,i+1,j-1);DFS(a,i-1,j+1);
    
}
int findIslands(vector<vector<int>> a, int n, int m) {
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] )
            {
                ans++;
                DFS(a,i,j);
            }
        }
    }
    return ans;
    // Your code here
}
int main()
{
    int n,m;   //row and colm
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(auto &x:a)
        for(auto &y:x)   cin>>y;

    cout<<findIslands(a,n,m);
}
/*
surajpatni@s:~/Documents/Must-Do-Interview-Question/graph$ ./a.out
3 3
1 1 0 
0 0 1 
1 0 1

output:
2
*/