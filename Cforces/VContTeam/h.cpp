
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

set< ll> check;

ll mypow(ll x)
{
	if(x==0)return 1;
	ll temp = mypow(x/2);
	if(x%2==0)
	{
		return temp*temp;	
	}
	else
	{
		return temp*temp*2;
	}
}

ll calc_number(vector<int> & v)
{
	//cout<<"got vec = "<<'\n';
	// for(int i=0;i<v.size();i++)
	// {
	// 	cout<<v[i]<<" ";
	// }
	int cnt = 0;
	ll ans =0;
	for(int i=v.size()-1;i>=0;i--)
	{
		if(v[i]==1)
		{
			ans+=mypow(cnt);
		}
		cnt++;
	}
	return ans;
}
int num_dig=0;

ll fn(int num_0s , int num_1s, ll low, ll high)
{
	ll ans = 0;
	vector<int> v;
	int turn = 1;
	ll num = 0;
	while(v.size()<=num_dig)
	{
		if(turn==1)
		{
			for(int x=0;x<num_1s;x++)
			{
				v.pb(1);
			}
		}
		else
		{	
			for(int x=0;x<num_0s;x++)
			{
				v.pb(0);
			}
		}
		if(num_0s!=0){
		num = calc_number(v);
		//cout<<"calculted num = "<<num<<endl;
		if(num<=high && num>=low && check.find(num)==check.end()){
			ans++;
			//cout<<"num added to ans\n";
			//cout<<" now ans = "<<ans<<endl;
			check.insert(num);
		}
	}
		turn=1-turn;
	}
	return ans;
}	




int main()
{
	ios_base::sync_with_stdio(false);
	ll a,b;
	cin>>a>>b;
	ll ans =0;
	ll temp = b;
	while(temp>0)
	{
		temp/=2;
		num_dig++;
	}
	int xar[64][64]={{0}};
	for(int i=1;i<=63;i++)
	{
		for(int j=0;j<=63;j++)
		{
			if(xar[i][j]==0){
			ans+=fn(j,i,a,b);
			xar[i][j]=1;
		}
		}	
	}
	cout<<ans;
}
