
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[n];int b[n];
	ll sum = 0;
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
	for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
	sort(b,b+n);
	ll x = b[n-1]+b[n-2];
	if(x>=sum)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}

	return 0;
}
