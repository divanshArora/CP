
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
	int n,k;
	cin>>n>>k;
	std::vector<int > v;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			v.pb(i);
			n/=i;
		}
	}
	if(v.size()<k)
	{
		cout<<"-1";
	}
	else
	{
		for(int i=0;i<k-1;i++)
		{
			cout<<v[i]<<" ";
		}
		int x=1;
		for(int i=k-1;i<v.size();i++)
		{
			x*=v[i];
		}
		cout<<x;
	}
	return 0;
}
