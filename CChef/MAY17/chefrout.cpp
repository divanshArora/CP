 
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
		string str;
		cin>>str;
		int i=0,n=str.size();
		while(i<n && str[i]=='C')i++;
		while(i<n && str[i]=='E')i++;
		while(i<n && str[i]=='S')i++;
		if(i==n)cout<<"yes\n";else cout<<"no\n";

	}
 	return 0;
}
