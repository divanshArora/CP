
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;



int aux[100001]={0};
int arr[100001]={0};

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

multiset<int,classcomp> ms;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,k,p;
	cin>>n>>k>>p;
	k = min(n,k);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	string str;
	cin>>str;
	p  =str.size();

	int first = 0;
	for(int i=0;i<k;i++)
	{
		if(arr[i]==1)first++;
	}
	aux[0] = first;
	for(int i=1;i<n;i++)
	{
		aux[i] = aux[i-1];
		if(arr[(i+k-1)%n]==1)aux[i]++;
		if(arr[i-1]==1)aux[i]--;
	}

//	for(int i=0;i<n;i++)cout<<" "<<aux[i]<<" ";cout<<endl;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(i+k<=n)
			{
				ms.insert(aux[i]);
			}
	}

	int last = n-1;
	int rm = n-k;
	for(int i=0;i<p;i++)
	{

		if(str[i]=='!')
		{
			ms.insert(aux[last]);
			last--;
			if(last<0)last = n-1;
			auto it = ms.find(aux[rm]);
			ms.erase(it);
			rm--;
			if(rm<0)rm = n-1;
		}
		else
		{
			cout<<*ms.begin()<<endl;
			//cout<<"sz = "<<ms.size()<<endl;
		}

	}

return 0;
}
