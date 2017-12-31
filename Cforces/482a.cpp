//http://codeforces.com/problemset/problem/482/A
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
	int n,k;cin>>n>>k;
	int diff=n-1;
	int last = 1;
	cout<<last<<" ";
	for(int i=1;i<=k-1;i++)
	{
		//cout<<"diff = "<<diff<<endl;
		cout<<last + diff<<" ";
		last+=diff;
		if(diff>0)
		diff--;
		else diff++;
		diff=-diff;
	}
	if(diff<0)	
	diff=-1;
	else diff=1;
	for(int i=1;i<=n-k;i++)
	{
		cout<<last+diff<<" ";
		last= last+diff;
	}
	//cout<<"final diff = "<<diff<<endl;

	return 0;
}
