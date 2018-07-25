
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

ll modpower(ll x, ll y, ll p) //x^y mod p
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y %2!= 0)
            res = (res*x) % p;
 
        // y must be even now
        y = y/2;
        x = (x*x) % p;  
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int arr[27];
	fill(arr,arr+27,0);
	for(int i=0;i<s.length();i++)
	{
			arr[s[i]-'a']++;	
	}
	int cnt =0;
	for(int  i=0;i<27;i++)
	{
		if(arr[i]>0 && cnt<k){
			for(int j=0;j<s.length();j++)
			{
				if(s[j]-'a'==i && cnt<k)
				{
					s[j] ='-';
					cnt++;
				}
			}
		}
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='-')
		{
			cout<<s[i];
		}
	}
	cout<<'\n';
}
