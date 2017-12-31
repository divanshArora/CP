
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll arr[10000]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		arr[s[i]-'A']++;
	}
	ll ans= 1000000000000;

	// ans = min(ans, arr['B'-'A']);ans = min(ans, arr['u'-'A']);ans = min(ans, arr['l'-'A']);ans = min(ans, arr['b'-'A']);
	// ans = min(ans, arr['a'-'A']); ans = min(ans, arr['s'-'A']);ans = min(ans, arr['a'-'A']);ans = min(ans, arr['u'-'A']);
	// ans = min(ans, arr['r'-'A']);
	ans = min(ans,arr['B'-'A']);
	ans = min(ans,arr['u'-'A']/2);
	ans = min(ans,arr['l'-'A']);
	ans = min(ans,arr['b'-'A']);
	ans = min(ans,arr['a'-'A']/2);
	ans = min(ans,arr['s'-'A']);
	//ans = min(ans,arr['a'-'A']);
	//ans = min(ans,arr['u'-'A']);
	ans = min(ans,arr['r'-'A']);
	if(ans==1000000000000)ans =0;

	cout<<ans;
	
	return 0;
}
