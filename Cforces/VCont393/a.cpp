
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	cin>>str;
	ll ans =0;
	for(int i=1;i<str.size();i++)
	{
		if(str[i]=='K' && str[i-1]=='V')
		{
			ans++;
			str[i]='-';
			str[i-1]='-';
		}		}
	for(int i=1;i<str.size();i++)
	{
			if(str[i]=='V' && str[i-1]=='V')
			{
				ans++;
				break;
			}
			else if(str[i]=='K' && str[i-1]=='K')

			{
				ans++;break;
			}
		
	}
	cout<<ans;


}

