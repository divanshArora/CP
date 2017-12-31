
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


int main()
{
	ios_base::sync_with_stdio(false);

	int t;cin>>t;
	
	while(t--)
	{
		int n;
		int ans = 0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			ans = max(x,ans);
		}

		cout<<n-ans<<endl;
	}



	return 0;
}
