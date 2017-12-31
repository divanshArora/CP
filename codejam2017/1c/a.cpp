
using namespace std;
#include <bits/stdc++.h>
#include <math.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007


vector< pair < ll, pair <int,int> > > vpp;


double area(int r, int h)
{
	return ((2*M_PI*r*h)); 
}

double xans  = 0.0;

int main()
{
	ios_base::sync_with_stdio(false);
	int tt;
	int nt;cin>>nt;
	for(int tt=0;tt<nt;tt++)
	{


		int n,k;
		cin>>n>>k;
		
		vpp.clear();
		for(int i=0;i<n;i++)
		{
			int x,y;cin>>x>>y;

			vpp.pb(make_pair(x*x*y,make_pair(x,y)));
		}
		sort(vpp.begin(),vpp.end());
		double xans = 0.0;
		int i=n-1;
		ll minr = 1000000000000000;
		ll maxr = -1;
		while(k--)
		{
			xans+=area(vpp[i].SS.FF,vpp[i].SS.SS);
			ll rad= vpp[i].SS.FF;
			if(rad<minr)
			{
				minr = rad;
			}
			if(rad>maxr)
			{
				maxr = rad;
			}

			i--;
		}
		if(minr==maxr)minr=0;

		xans+=2*M_PI*(maxr*maxr-minr*minr);
	


















		cout<<"Case #"<<tt+1<<": "<<xans<<endl;
	}
}
