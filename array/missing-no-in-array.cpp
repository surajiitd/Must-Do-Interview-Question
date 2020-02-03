#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n,temp,sum=0;
	    cin >> n;
	    for(int i=1;i<=n-1;i++)
	    {
	        cin >> temp;
	        sum+=temp;
	    }
	    int tot = n*(n+1)/2;
	    cout << tot-sum<<endl;
	   
	}
	
	return 0;
}
