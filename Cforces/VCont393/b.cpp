
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
	string x,y;
	cin>>x>>y;
	string ans;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]<y[i])
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<y;
	return 0;
}




