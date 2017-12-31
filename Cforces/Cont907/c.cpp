
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int dp[26]={0};


bool chk()
{
	int x=0;
	for(int i=0;i<26;i++)
	{	
		if(dp[i]==-1)x++;
	}
	return (x==25 || x==26);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	ll ans = 0;
	int isfirst =1;
	bool flag=false;
	unordered_set<char> ms;
	for(int i=0;i<n;i++)
	{
		string op, s;
		cin>>op>>s;
		if(((ms.size()==1) || chk()))flag=true;
		if(op[0]=='!')
		{	
			if(isfirst==1)
			{
				for(int j=0;j<s.length();j++)
				{
					ms.insert(s[j]);
				}
				isfirst=0;
			}
			else
			{
				unordered_set<char>ns;
				int xf=1;
				for(int j=0;j<s.length();j++)
				{
					if(dp[s[j]-'a']!=-1){
					if(ms.find(s[j])!=ms.end())
					{
						ns.insert(s[j]);
						xf=0;
					}
					else
					{
						dp[s[j]-'a']=-1;
					}
					}
				}
				if(xf==0)ms=ns;	
			}
			if(flag==true)ans++;
		}
		if(op[0]=='?' && i!=n-1)
		{
			dp[s[0]-'a']=-1;
			auto it = ms.find(s[0]);
			if(it!=ms.end())
			{
				ms.erase(it);				
			}
			if(flag==true)ans++;
		}
		if(op[0]=='.')
		{
			for(int j=0;j<s.length();j++)
			{
				dp[s[j]-'a']=-1;
				auto it = ms.find(s[j]);
				if(it!=ms.end())
				{
					ms.erase(it);
				}
			}
		}
		if(op[0]=='?' && i==n-1)
		{	
			if(flag==true && ((ms.find(s[0])==ms.end() && ms.size()==1) || dp[s[0]-'a']==-1 ))ans++;
		}
	}
	cout<<ans;
	return 0;
}
