
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll arr[(int)6e5];

ll brr[(int)6e5]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<n;i++)
	{
		arr[i]+=arr[i-1];
	}
		
	ll res= 0;

	if(abs(arr[n-1])%3!=0)
	{
		cout<<"0";return 0;
	}
	ll part = arr[n-1]/3;
	int a=1,b=0,c=0;
	int i=n-1;
	if(part ==0)
	{
		ll ans=0;
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]==0)
			{
				ans++;
			}
		}
		cout<< max((ans*(ans-1)/2),0LL);
		return 0;
	}

	vector<int> v;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]==part)
		{
			v.pb(1);
		}
		else if(arr[i]==2*part)
		{
			v.pb(2);
		}
	}	
	i=0;
	ll one = 0, two = 0;
	while(i<v.size())
	{
		if(v[i]==1)one++;
		if(v[i]==2)
		{
			two++;
			res+=one;
		}
		i++;
	}


	cout<<res;
	return 0;	
}
