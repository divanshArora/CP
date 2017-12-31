
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

	int n;
	cin>>n;
	vector<pair<int,int>> v(n+1);
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[i] = {a,b};
	}
	for(int i=0;i<n;i++)
	{
		if(v[i].FF!=v[i].SS)
		{
			cout<<"rated";return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[i].SS<v[j].SS)
			{
				cout<<"unrated";
				return 0;
			}
		}
	}
	cout<<"maybe";


	
	return 0;
}
