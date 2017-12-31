using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;
vector< string> vp;
vector<string> vm;

int main()
{
	int n;cin>>n;string s;
	//INPUT
	//vp is array of plus strings vm is of minus
	for(int i=0;i<n;i++)
	{
		string op;cin>>op;
		if(op=="+")
		{	cin>>s;
			vp.pb(s);
		}
		else
		{
			cin>>s;
			vm.pb(s);
		}
	}
	//INPUT ENDS
	set< string> ans;
	int arr[n+1];
	for(int i=0;i<n;i++)arr[i]=-1;
	for(int i=0;i<vp.size();i++)
	{
		for(int j=0;j<vm.size();j++)
		{
			int k=0;
			cout<<" comparing " << vm[j]<< " to "<< vp[i]<<endl;
			while(k<vp[i].size() && k< vm[j].size() && (vp[i])[k]==(vm[j])[k])
			{
				cout<<"k = "<< k<<endl;
				k++;
			}
			if(k==vm[j].size())
			{
				cout<<"-1";
				return 0;
			}
			if(k+1>arr[j]){
				//ans.insert((vm[j]).substr(0,k+1));
				arr[j] = k+1;
			}
		}
	}
	for(int i=0;i<vm.size();i++)
	{
		ans.insert(vm[i].substr(0,arr[i]));
	}
	//sort 
	//sort(ans.begin(),ans.end()); --> set is already sorted

	//print answer
	cout<<ans.size()<<'\n';
	for(auto i=ans.begin();i!=ans.end();i++)
	{
		cout<<*i<<" ";
	}

	return 0;
}