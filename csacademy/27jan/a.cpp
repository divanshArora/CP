#include <bits/stdc++.h>

using namespace std;
int a[50001],b[50001];

int main() {
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++)
    	{
    		cin>>a[i];
    	}
    	for(int i=0;i<n;i++)
    	{
    		cin>>b[i];
    	}

    	sort(a,a+n);
    	sort(b,b+n);
    	if(a[(n/2)-1]<b[n/2] && b[(n/2)-1]<a[n/2])
    	{
    		for(int i=1;i<=n;i++){
    			cout<<n-i+1<<" ";
    		}
    	}
    	else 
    	{
    		cout<<"-1";
    	}
    	cout<<endl;
    }
    return 0;
}