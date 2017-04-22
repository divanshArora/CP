
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll mpow(ll a,ll x)
{
	if(x==0){
		return 1;
	}
	ll t = mpow(a,x/2);
	if(x%2!=0)return t*t*a;
	return t*t;

}
int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{


		ll k,n;
		cin>>n>>k;
		ll i=0,j;
		ll cnt = 0;
		for(i=1,j=0;i<=k;i*=2,j++)
		{
			cnt+=i;
			if(cnt>=k)
			{
				break;
			}
		}
		//cnt--;
		//cout<<"cnt = "<<cnt<<endl;
		ll level = j;
		//cout<<"level = "<<level<<endl;
		ll num = k - cnt;
		if(num==0)
		{
			num = mpow(2,level);
		}
		//cout<<"num = "<<num<<endl;
		ll u = mpow(2,level);
		//cout<<"u = "<<u<<endl;
		while(n>2 && n%2!=0)
		{
			n/=2;
			u/=2;
		}
		cout<<"n = "<<n<<" u = "<<u<<endl;
		while(u>1	)
		{
			n--;
			//cout<<"n!! = "<<n<<"num  ="<<num<<" u  ="<<u<< endl;
			if(num>=u)
			{
				//cout<<"min=="<<endl;
				n = min(n/2,n-(n/2));
			}
			else	
			{
				//cout<<"max =="<<endl;
				n = max(n/2,n-(n/2));
			}
			u/=2;
			//cout<<"n!! = "<<n<<endl;
			//cout<<"----------------------"<<endl;

		}
		//cout<<"n = "<<n<<endl;
		n--;
		cout<<"Case #"<<tt<<": "<<max(n/2,n-(n/2))<<" "<<min(n/2,n-(n/2))<<endl;
	}

	return 0;
}
