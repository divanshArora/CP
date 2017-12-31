
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

vector< int > ans;

void solve(int n, int i, int flag, int N)
{
	cout<<"n = "<<n<<" i = "<<i<<'\n';
	if(n<=0)return;
	if(n==3)
	{
		ans.pb(i+1);
		ans.pb(i);
		ans.pb(i+2);
		ans.pb(i+1);		
		return;
	}
	if(n==2)
	{
		ans.pb(i);
		ans.pb(i+1);
		ans.pb(i);
		return;
	}	
	ans.pb(i);
	ans.pb(N-i+1);
	if(i>1)
	{
		ans.pb(i+1);
		ans.pb(N-i+1-1);
	}
	solve(n-2,i-1,false,N);
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	if(n==3)
	{
		cout<<"4\n2 1 3 2";
		return 0;
	}
	if(n==2)
	{
		cout<<"3\n2 1 2";
		return 0;
	}


	cout<<2*n<<'\n';
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" ";
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" ";
	}

	return 0;
}
