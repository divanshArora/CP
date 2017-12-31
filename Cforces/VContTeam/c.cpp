
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector< ll > v;
		for(int i=0;i<n;i++)
		{
			ll ttt;
			cin>>ttt;
			v.pb(ttt);
		}
		priority_queue<ll,vector<ll>,greater<ll> > my_min_heap(v.begin(),v.end());
		ll ans = 0;
		while(my_min_heap.size()>=2)
		{
			ll a=0;
			a=my_min_heap.top();
			//cout<<"a1= "<< a<<endl;
			my_min_heap.pop();
			a+=my_min_heap.top();
			//cout<<"a2= "<< a<<endl;
			my_min_heap.pop();
			ans+=a;
			my_min_heap.push(a);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
