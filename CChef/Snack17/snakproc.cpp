
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
	int t;
	cin>>t;
	while(t--)
	{
		int n;cin>>n;
		string s;
		cin>>s;
		string a,b;int turn =0;
		for(int i=0;i<n;i++)
		{
			if(s[i]!='.')
			{
				a+=s[i];
				if(turn==0)
					{
						b+='H';
					}
					else
					{
						b+='T';
					}
					turn^=1;
			}
		}
		if(a==b && !(a.length()%2))
		{
			cout<<"Valid\n";
		}
		else
		{
			cout<<"Invalid\n";
		}
	}

	return 0;
}
