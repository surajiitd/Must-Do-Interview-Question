#include <bits/stdc++.h>
using namespace std;

void byHashMap(int a[],int n)
{
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
void byMooreVoting(int a[],int n)
{
	int voter=a[0],votes = 1;
	
	for(int i=1;i<n;i++)
	{
		if(voter == a[i])
			votes++;
		else
		{
			if(votes==0)
			{
				voter = a[i];
				votes = 1;
			}
			else
				votes--;
		}
	}
	//if majority elem exists then always voter will come as that value.
	// now 2 cases voter may be the maj elem or it doesn't exist.
	int count = 0;
	for(int i=0;i<n;i++)
		if(a[i]==voter)	count++;
	if(count > n/2)
		cout << voter <<endl;
	else
		cout<<"majorith element doesn't exist"<<endl;
	
}
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
	    
	    //byHashMap(a,n);  //method 1

	    byMooreVoting(a,n);  //method 2
	}
	
	return 0;
}