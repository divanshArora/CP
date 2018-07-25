
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int charlist[10]={0};

ll get_ans(string s)
{
	int subset_chars[10]={0};
	for(auto si:s)subset_chars[si-'0']++;
	for(int i=0;i<10;i++)
	{
		if(charlist[i] && !subset_chars[i])return 0;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;	
	vector<int> v;
	for(int si:s)
	{
		v.pb(si-'0');
		charlist[s[i]-'0']++;
	}
	int k = v.size();
	for(int i=1;i<=1<<k;i++)
	{
		string subset = "";
		for(int j=0;j<k;j++)
		{
			if(i&(1<<j))
			{
				subset+=v[j];
			}
		}


	}
		
}
