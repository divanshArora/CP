//Source mypow: http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull long long 
#define FF first
#define SS second
const ull MOD1 = 1000000007;
const ull MOD2 = 1000000009;
 
using namespace std;
 
 
 
ull mypow(ull x, ull y, ull md)
{
	if(y==0)
	{
		ull r = 1;
		return r;
	}
	ull temp = mypow(x,y/2,md)%md;
	temp = ((temp%md)*(temp%md))%md;	
	if(y%2==0)
	{
		return temp%md;
	}
	else
	{
		return (temp*(x%md))%md;
	}
 
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ull n;
		cin>>n;
		n--;
		if(n==0)
		{
			cout<<"0 0\n";
		}
		else
		{
			ull q = ((2*n - 1));
			ull a = n;
			ull b = n+1;
			if(n%2==0)a/=2;else b/=2;
			
			ull gd = __gcd(a,q);
			a/=gd;
			q/=gd;
			gd= __gcd(b,q);
			b/=gd;
			q/=gd;
 
			ull kama = ((a%MOD1)*(b%MOD1))%MOD1;
			//cout<<"q init = "<<q<<endl;
			ull kazi = mypow(q,MOD1-2,MOD1)%MOD1;
			//cout<<"q = "<<q<<endl;
			
			ull ans = (kama*kazi)%MOD1;
			cout<<ans%MOD1<<" ";
			/////////////////////////////////////////////////
			kama = ((a%MOD2)*(b%MOD2))%MOD2;
			//cout<<"q init = "<<q<<endl;
			kazi = mypow(q,MOD2-2,MOD2)%MOD2;
			//cout<<"q = "<<q<<endl;
			
			ans = (kama*kazi)%MOD2;
			cout<<ans%MOD2<<'\n';
 
 
 
		}
	}
	return 0;
}
 