
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll arr[100005];
ll actual_arr[100004];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>actual_arr[i];
		arr[i] =actual_arr[i];
	}
	for(int i=1;i<n;i++)
	{
		arr[i]+=arr[i-1];
	}
	if(arr[n-1]%2!=0)
	{
		cout<<"NO";
		return 0;
	}
	ll target = arr[n-1]/2;

	multiset< ll > ms;
	for(int i=0;i<n;i++)
	{
		ms.insert(actual_arr[i]);
		if(arr[i]==target)
		{
			cout<<"YES";
			return 0;
		}
		else if(arr[i]>target)
		{
			ll tofind =  arr[i]-target;
			if(ms.find(tofind)!=ms.end())
			{
				cout<<"YES";
				return 0;
			}
		}
	}

	reverse(actual_arr,actual_arr+n);
	for(int i=0;i<n;i++)
	{
		arr[i] =actual_arr[i];
		//cout<<actual_arr[i]<<" ";
	}
	arr[0] = actual_arr[0];
	for(int i=1;i<n;i++)
	{
		arr[i]+=arr[i-1];
	}
	ms.clear();
	for(int i=0;i<n;i++)
	{
		ms.insert(actual_arr[i]);
		if(arr[i]==target)
		{
			cout<<"YES";
			return 0;
		}
		else if(arr[i]>target)
		{
			ll tofind =  arr[i]-target;
			if(ms.find(tofind)!=ms.end())
			{
				cout<<"YES";
				return 0;
			}
		}
	}	

	cout<<"NO";

	return 0;
}
