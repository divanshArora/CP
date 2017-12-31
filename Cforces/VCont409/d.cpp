
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

vector<pair< ll ,ll > > vp;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		vp.pb({x,y});
	}
	double ans = numeric_limits<double>::max();
	for(int i=2;i<n+3;i++)
	{
		double dist = 2*sqrt((vp[i%n].FF - vp[(i-2)%n].FF)*(vp[i%n].FF - vp[(i-2)%n].FF) + (vp[i%n].SS - vp[(i-2)%n].SS)*(vp[i%n].SS - vp[(i-2)%n].SS));
		double num = abs((vp[i%n].SS - vp[(i-2)%n].SS)*vp[(i-1)%n].FF - (vp[i%n].FF - vp[(i-2)%n].FF)*vp[(i-1)%n].SS + vp[i%n].FF*vp[(i-2)%n].SS - vp[i%n].SS*vp[(i-2)%n].FF);
		if(num<=ans*dist)
		{
			ans = num/dist;
		}
	}	
	cout<<setprecision(9)<<ans;
}
