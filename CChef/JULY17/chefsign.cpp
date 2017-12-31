
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int maxi = 1;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='>')
			{
				int cur=1;
				int j=i;
				while(j<s.length() && s[j]=='>' || s[j]=='=')
				{
					if(s[j]=='>')
					{	
						cur++;
					}
					j++;
				}
				maxi = max(cur, maxi);
				i=j-1;
			}
			else
			{
				int cur=1;
				int j=i;
				while(j<s.length() && s[j]=='<' || s[j]=='=')
				{
					if(s[j]=='<')
					{	
						cur++;
					}
					j++;
				}
				maxi = max(cur, maxi);	
				i=j-1;
			}
		}
		cout<<maxi<<'\n';
	}
}
