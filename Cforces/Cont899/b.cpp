
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
	
    int leap[12]= {31,29,31,30,31,30,31,31,30,31,30,31};
    int non_leap[12] =  {31,28,31,30,31,30,31,31,30,31,30,31};  

    int c[5][36];
    for(int i=0;i<12;i++)
    {
        c[0][i]=non_leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[0][i+12]=non_leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[0][i+24]=non_leap[i];
    }

    for(int i=0;i<12;i++)
    {
        c[1][i]=non_leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[1][i+12]=non_leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[1][i+24]=leap[i];
    }

    for(int i=0;i<12;i++)
    {
        c[2][i]=non_leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[2][i+12]=leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[2][i+24]=non_leap[i];
    }    

    for(int i=0;i<12;i++)
    {
        c[3][i]=leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[3][i+12]=non_leap[i];
    }
    for(int i=0;i<12;i++)
    {
        c[3][i+24]=non_leap[i];
    }

    int  n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<36;j++)
        {
            if(c[i][j]==arr[0])
            {
                int flag =0;
                for(int k=0;k<n;k++)
                {
                    if(arr[k]!=c[i][j+k])
                    {
                        flag =1;
                    }
                }
                if(flag==0)
                {
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";



	return 0;
}
