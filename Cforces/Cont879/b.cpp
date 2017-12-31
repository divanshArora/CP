#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;


deque<ll> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	ll n,k;
	cin>>n>>k;
	k=min(k,n);
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		dq.push_back(a);
	}
	ll prev = dq.front();
	while(k>0)
	{
		ll a = dq.front();
		dq.pop_front();
		ll b = dq.front();
		dq.pop_front();
		if(a>b)
		{
			dq.pb(b);
			dq.push_front(a);
		}
		else
		{
			dq.pb(a);
			dq.push_front(b);	
		}
		if(dq.front()==prev)
		{
			k--;
		}
		else
		{
			prev= dq.front();
		}
	}
	cout<<dq.front();

	return 0;
}
