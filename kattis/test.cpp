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
	string s;
	cin>>s;
	cout<<s[0];
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!=s[i-1])
		{
			cout<<s[i];
		}
	}
}
