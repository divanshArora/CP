#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

bool comp(int a, int b)
{
	return a>b;
}

int main()
{
	ios_base::sync_with_stdio(false);

	std::vector<int> v;
	for(int i=0;i<6;i++){int x;cin>>x;v.pb(x);}

	int k = v[0]+ v[1]+ v[5];
	ll ans=k*k;
	ans-=v[1]*v[1] + v[3]*v[3] + v[5]*v[5];
	cout<<ans<<endl;
	return 0;
}





