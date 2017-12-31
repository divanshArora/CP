#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,b;
		cin>>n>>b;
		ll left = 0, right = n;
		ll ans = 0;
		// while(left<right)
		// {
		// 	ll mid = (left+right)/2;
		// 	//cout<<"mid = "<<mid<<endl;
		// 	if(n-mid>=b)
		// 	{
		// 		left = mid+1;
		// 		ans = max(ans,(mid*(n-mid))/b);
		// 	}
		// 	else
		// 	{
		// 		right = mid;
		// 	}
		// }
		for(ll i=n;i>=0;i-=b)
		{	
			ans = max((i*(n-i))/b,ans);
		}
		cout<<ans<<'\n';
	}
}