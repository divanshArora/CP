#include <bits/stdc++.h>

using namespace std;

vector<long long int> Ra,Ba;
int main() {
    ios_base::sync_with_stdio(false);
    long long int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<a;i++)
    {
    	long long int x; 
    	cin>>x;
    	Ra.push_back(x);
    }
    for(int i=0;i<b;i++)
    {
    	long long int x; 
    	cin>>x;
    	Ba.push_back(x);
    }
    sort(Ra.begin(),Ra.end());
    sort(Ba.begin(),Ba.end());
    long long int fa=0;
    for(int i=0;i<a;i++)
    {	
    	auto ans = upper_bound(Ba.begin(),Ba.end(),Ra[i]);	
    	//cout<<"ans= "<<ans-Ba.begin()<<endl;
    	if(ans-Ba.begin()==b)
    	{
    		    	fa += Ra[i]-Ba[ans-Ba.begin()-1];

    	}
    	else if(ans-Ba.begin()-1>=0)
    		fa += min(Ba[ans-Ba.begin()]-Ra[i],Ra[i]-Ba[ans-Ba.begin()-1]);
    	else
    		fa += Ba[ans-Ba.begin()]-Ra[i];
    }	
    cout<<fa<<endl;

    return 0;
}