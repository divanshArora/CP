#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	ll m;
	cin>>n>>m;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll i = 1;int j=0;
	vector<ll> v;
	while(m>0 && i<=1000000000)
	{
		if(j<=n-1 && arr[j]==i)
		{
			j++;
			i++;
		}
		else
		{
			//cout<<"m = "<<m<<" i = "<<i<<endl;
			if(m>=i)
			{
				v.pb(i);
				m-=i;
				i++;
			}
			else
			{
				break;
			}
		}
	}
	cout<<v.size()<<endl;
	for(auto it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}

	return 0;
}





