
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
	int n,m;
	cin>>n>>m;	
	int arr[n+m+8];
	for(int i=0;i<m+n+8;i++)arr[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			cout<<"i+j = "<<i+j<<endl;
			arr[i+j]++;
		}
	}
	int maxi = 0;
//	for(int i=0;i<m+n+4;i++)cout<<" - "<<arr[i]<< " ";
	for(int i=1;i<=m+n+6;i++)
	{
		maxi = max(arr[i],maxi);
	}
	for(int i=0;i<=m+n+6;i++)
	{
		if(arr[i]==maxi)
		{
			cout<<i<<'\n';
		}
	}
}
