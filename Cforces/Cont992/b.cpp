
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

//PROBLEM: http://codeforces.com/contest/992/problem/B

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

//src: https://www.geeksforgeeks.org/prime-factors-big-number/
vector<ll> factorize(long long n)
{
	vector<ll> ret;
    int count = 0;
 	ll pp =1;
    // count the number of times 2 divides 
    while (!(n % 2)) {
        n >>= 1; // equivalent to n=n/2;
        count++;
        pp*=2;
    }
 
    // if 2 divides it
    if (count)
        //cout << 2 << "  " << count << endl;
 		ret.pb(pp);
    // check for all the possible numbers that can 
    // divide it
    for (long long i = 3; i <= sqrt(n); i += 2) {
    //	if(primeset.find(i)==primeset.end())continue;
        count = 0;
        pp=1;
        while (n % i == 0) {
            count++;
            pp*=i;
            n = n / i;
        }
        if (count)
            //cout << i << "  " << count << endl;
            ret.pb(pp);
    }
 
    // if n at the end is a prime number.
    if (n > 2)
        //cout << n << "  " << 1 << endl;
        ret.pb(n);
    return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll l,r,x,y;
	cin>>l>>r>>x>>y;

	if(y%x!=0)
	{
		cout<<"0";return 0;
	}
	vector<ll> v = 	factorize(y/x);
	ll n = v.size();
	ll prod = 1;
	ll ans =0;
	set<pair<ll,ll>>ms;
	for(int i=0;i<n;i++){
		prod*=v[i];
	}
	for (int i = 0; i < (1<<n); i++)
        {
 			ll pp=1;
            for (int j = 0; j < n; j++)
                {
                	if ((i & (1 << j)) > 0)
                    	pp*=v[j];
            	}
            if(x*pp>=l && x*pp<=r && (x*prod/pp)>=l && (x*prod/pp)<=r){
            		ms.insert({pp,prod/pp});
            	}
        }
     cout<<(ms.size());

    }
