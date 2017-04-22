
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
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]-arr[i+1] == 1)
			{
				int t = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = arr[i];
			}
		}
		if(is_sorted(arr,arr+n))
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}


}
