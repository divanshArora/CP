#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll arr[(int)1e5+3];

ll gcd(ll a, ll b )
{
	if(a==0)return b;
	return gcd(b%a,a);
}

ll check(ll a)
{
	while(a>0 && a%2==0)
	{
		a/=2;
	}
	while(a>0 && a%3==0)
	{
		a/=3;
	}
	return a;

}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	// sort(arr,arr+n);
	// ll gcdx = arr[0];
	// for(int i=1;i<n;i++)
	// {
	// 	gcdx = gcd(gcdx,arr[i]);
	// }
	//cout<<"gcdx = "<<gcdx<<endl;
	// for(int i=0;i<n;i++)arr[i]/=gcdx;
		ll targ = check(arr[0]);
	for(int i=0;i<n;i++)
	{
		if(targ!=check(arr[i])){cout<<"No";return 0;}
	}
	cout<<"Yes";

	return 0;
}





