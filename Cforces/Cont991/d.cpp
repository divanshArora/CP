
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
	string arr[2];
	cin>>arr[0];
	cin>>arr[1];
	int n = arr[0].length();
	ll ans =0;
	for(int k=0;k<n;k++)
	{
		int free = 0;
		if(k+2<n){
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<2;j++)
				{
					if(arr[j][k+i]=='0')
					{
						free++;
					}
				}
			}
		
		if(free==6)
		{
			k+=2;
			ans+=2;
			continue;
		}
	}
		free=0;
		if(k+1<n){
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(arr[j][k+i]=='0')
				{
					free++;
				}
			}
		}
		if(free>=3)
		{
			ans++;
			k+=1;
			continue;
		}
	}
	}
	cout<<ans;


}
