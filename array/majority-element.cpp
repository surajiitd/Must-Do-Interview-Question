#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(auto &x:a)  cin >> x;
	    map<int,int> mp;
    	
    	int ans = -1;
    	for(int i=0;i<n;i++)
    	{
    	    int curr = a[i];
    	    if(mp[curr] >= n/2){  ans = curr; break; }
    	    mp[curr]++;
    	}
    	cout << ans <<endl;
	    
	}
	
	return 0;
}