#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		string arr;
			cin>>arr;
		
		vector<ll>v;
		v.pb(0);
		for(int i=1;i<n;i++)
		{
			if(arr[i]!=arr[i-1])
			{
				v.pb(i);
			}
		}
		v.pb(n);
		int sz = v.size();
		vector<ll> vdiff;
		for(int i=1;i<sz;i++)
		{
			vdiff.pb(v[i]-v[i-1]);
		}
		cout<<endl;
		k= min(k,n);
		ll divfactor= 1;
		sort(vdiff.begin(),vdiff.end());
		cout<<"vdiff: "<<endl;
		for(int i=0;i<vdiff.size();i++)
		{
			cout<<vdiff[i]<<" ";
		}
		ll l = 1,r=n+1;
		int cry=0;
		while(l<r)
		{
			cry++;
			cout<<"l = "<<l<<" r= "<<r<<endl;
			ll mid = (l+r)/2;
			ll temp = mid;
			ll x = upper_bound(vdiff.begin(),vdiff.end(),mid)-vdiff.begin();
			cout<<"x = "<<x<<endl;
			cout<<"temp initial = "<<temp<<endl;
			for(int i=x;i<vdiff.size();i++)
			{
				ll u = vdiff[i];
				cout<<" u = "<<u<<endl;
				if(vdiff[i]<3)
					continue;
				while(u>mid && temp>=0 )
				{	
					u=u/2;
					temp--;
					cout<<"u  = "<<u<<"temp = "<<temp<<endl;
				}
			}

			cout<<"tmp final  = "<<temp<<endl;
			cout<<"MID = "<<mid<<endl;
			if(temp>=0)
			{
				r=mid-1;
			}
			else
			{
				l = mid;
			}
			if(l>=r)
			{
				cout<<mid<<endl;
			}
			// if(cry==10)
			// break;
		}




	}	

	return 0;
	
}
















