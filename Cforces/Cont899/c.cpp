
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
    ll t;
    cin>>t;
    while(t--){
	ll n;
    cin>>n;
//        cout<<n<<'\n';

    ll l=1, r=1;
    ll sm = (n*(n+1))/4;
    ll ms = 1;
    while(ms!=sm && r<=n && l<=n)
    {
        if(ms>sm)
        {
            ms-=l;
            l++;
        }
        else if(ms<sm)
        {
            r++;
            ms+=r;
        }
        else
        {
            break;
        }
    }
    if( ((n*(n+1))/2 )%2!=0)
    {
//        cout<<1<<'\n';
//        cout<<r<<" "<<l<<" ";  
        ll sm=0;
        for(ll i=l;i<=r;i++)
        {
            sm+=i;
        }
        if(sm!=(n*(n+1))/4 -1 && sm!=(n*(n+1))/4)
        {
            cout<<"ERROR"<<n<<'\n';
            cout<<"sm = "<<sm<<'\n';
            cout<<"nsm  = "<< (n*(n+1))/4<<'\n';
        }

    }
    else
    {
        // cout<<"0"<<'\n';
        // cout<<r<<" "<<l<<" ";  
        ll sm=0;
        for(ll i=l;i<=r;i++)
        {
            sm+=i;
        }
        if(sm!=(n*(n+1))/4)
        {
            cout<<"Sm= "<<sm<<'\n';
            cout<<"nsm  = "<< (n*(n+1))/4<<'\n';
        }

    }


}
return 0;
}
