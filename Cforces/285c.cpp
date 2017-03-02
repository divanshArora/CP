#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll arr[3*((int)1e5)+4];

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll inc=0,dec=0;
	int targ=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>targ)
		{
			dec+=arr[i]-targ;
		}
		else
		{
			inc+=targ-arr[i];
		}
		targ++;
	}

	cout<< inc+dec<<'\n';

}






