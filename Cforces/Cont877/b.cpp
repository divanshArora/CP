
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

// int gcd(int a, int b) {
//   while (a > 0 && b > 0)
//     if (a > b) a %= b;
//     else b %= a;
//   return a + b;
// }

// ll modpower(ll x, ll y, ll p) //x^y mod p
// {
//     ll res = 1;      // Initialize result
 
//     x = x % p;  // Update x if it is more than or 
//                 // equal to p
 
//     while (y > 0)
//     {
//         // If y is odd, multiply x with result
//         if (y %2!= 0)
//             res = (res*x) % p;
 
//         // y must be even now
//         y = y/2;
//         x = (x*x) % p;  
//     }
//     return res;
// }

int lft[5001]={0};
int rt[5001]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int n = s.length();
	int tot = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			lft[i]++;
			tot++;
		}
		if(i>0)lft[i]+=lft[i-1];
		int j = n-i-1;
		if(j<=n-2)
		{
			rt[j]+=rt[j+1];
		}
		if(s[j]=='a')
		{
			rt[j]++;
		}
	}
	int ans = 0;
	int i=-1;
	for(int j=i+1;j<n+1;j++)
		{
			int rem = tot-(rt[j]);
			ans = max(rt[j]+(max(j-rem,0)),ans);
		}
	for(i=0;i<n+1;i++)
	{
		for(int j=i+1;j<n+1;j++)
		{
			int rem = tot-(lft[i]+rt[j]);
			ans = max(lft[i]+rt[j]+(max(j-i-1-rem,0)),ans);
		}
	}
	cout<<ans;

	return 0;
}
