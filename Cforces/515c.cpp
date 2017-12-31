
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int cnt[10]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	int kk;cin>>kk;
	ll n;
	cin>>n;
	string arr[10] ={"","","2","3","223","5","53","7","7222","3372"};
	string ans;
	while(n>0)
	{
		int x = n%10;
			//cout<<"x = "<<x<<endl;
		ans+=arr[x];
		n/=10;
	}
	sort(ans.rbegin(),ans.rend());
	cout<<ans;
	return 0;
}
