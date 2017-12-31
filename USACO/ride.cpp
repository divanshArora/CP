/*
ID: divansh2
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>	

#define ll long long

using namespace std;

ll fn(string s)
{
	    ll ans = 1;
    for(int i=0;i<s.length();i++)
    {
    	ans*=s[i]-'A'+1;	
    	ans%=47;
    }

    return ans%47;
}

int main() {

	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);

    string s,a;
    cin>>s>>a;
    //cout<<"fns = "<<fn(s)<<" " <<fn(a); 
    if(fn(s)==fn(a))
    {
    	cout<<"GO\n";
    }
    else
    {
    	cout<<"STAY\n";
    }
    return 0;
}