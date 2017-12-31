
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define MOD 1000000007

typedef vector<ll> vll;

ll ans = 1LL;

pair<int,int> arr[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int last;
	for(int i=0;i<n;i++)
	{
		int x,h;
		cin>>x>>h;
		arr[i]={x,h};
	}
	last  = arr[0].first;
	for(int i=1;i<n-1;i++)	
	{
		//cout<<"last = "<<last<<" ans = "<<ans<<endl;
		int x = arr[i].first;int h= arr[i].second;

		if(x-h > last)
		{
			ans++;
			last = x;
		}
		else if(x+h<arr[i+1].first)
		{
			ans++;
			last = x+h;
		}
		else
		{
			last = x;
		}
		//cout<<"new ans = "<<ans<<endl;
	}
	if(n!=1)
	ans++;

	cout<<ans;
}
