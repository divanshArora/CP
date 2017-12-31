
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

	int n,t,k,d;
	cin>>n>>t>>k>>d;
	int without = ((n+k-1)/k)*t;
	int with;
	int till_d = ((d+t-1)/t)*k;

	if(n-till_d>0)
	{
		if(t>d)
		{
			cout<<"YES";
		}
		else
		{
			if(d%t!=0)
			{
				cout<<"YES";
			}
			else
			{
				if(n-till_d>k)
				{
					cout<<"YES";
				}
				else{
					cout<<"NO";
				}
			}
		}
	}
	else
	{
		cout<<"NO";
	}


	return 0;
}
