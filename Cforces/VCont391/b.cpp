
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

int arr[100005];
int s[100005]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		s[arr[i]]++;
	}
	ll ans = 1;
	for(int i=2;i<100005;i++)
	{
		ll temp= 0;
			for(int j=i;j<100005;j+=i)
			{
				if(s[j]>0)
				{
					temp+=s[j];
					ans = max(ans,temp);
				}
			}
	}
	cout<<ans;
	return 0;
}
