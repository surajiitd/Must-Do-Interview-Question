#include <bits/stdc++.h>
using namespace std;
int minSwaps(int a[], int n){
    /*Your code here */
    int ans = 0;
    int vis[n] = {0};
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        v[i] = {a[i],i};
    }
    sort(v.begin(),v.end());
    
    for(int i=0;i<n;i++)
    {
        if(vis[i])  continue;
        int cycle_len=0;
        int j=i;
        while(!vis[j])
        {
            vis[j] = 1; cycle_len++;
            j = v[j].second;
        }
        ans += cycle_len-1;
    }
    return ans;
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    cout<<minSwaps(a,n)<<endl;
}
