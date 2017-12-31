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

int search(string a, string b)
{
	bool ans = false;
	int anscnt=0;
	for(int i=0;i<a.length();i++)
	{
		ans = true;
		int x = i;
		for(int j=0;j<b.length();j++)
		{
			if(a[x]!=b[j])
			{
				ans = false;
			}
			x++;
		}
		if(ans==true)
		{
			ans = false;
			anscnt++;
		}
	}
	return anscnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	string arr[5] = {"Danil", "Olya", "Slava", "Ann" ,"Nikita"};
	int cnt = 0;
	for(int i=0;i<5;i++)
	{
		int ans = search(s,arr[i]);
		if(ans>0)cnt+=ans;
	}
	if(cnt==1)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
 