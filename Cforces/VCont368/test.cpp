#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define INF 10000000000
using namespace std;


vector<vector < ll> > v(1000001);

int main()
{
	ios_base::sync_with_stdio(false);

	
	ll n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<m*n;i++)
	{
		v[i].pb(0);
	}
	ll prev_state = 0;
	for(int i=1;i<=q;i++)
	{	

		int optn;cin>>optn;
		if(optn==1)
		{
			int x,y;cin>>x>>y;
			x--;y--;
			v[m*x + y].pb(i);
		}

	}


	return 0;
}