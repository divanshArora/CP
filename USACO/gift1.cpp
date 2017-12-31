/*
ID: divansh2
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>	
#define  pb push_back
#define ll long long

using namespace std;


int main() {

	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

    int np;
    cin>>np;
    map<string , int> msi;
    vector< string> vs;
    for(int i=0;i<np;i++)
    {
        string s;cin>>s;
        vs.pb(s);
        msi.insert({s,0});
    }
    for(int i=0;i<np;i++)
    {
        string s;cin>>s;
        int money,ng;
        cin>>money>>ng;
        if(ng!=0)
        msi[s] -= (money/ng)*ng;
        for(int j=0;j<ng;j++)
        {
            string ss;
            cin>>ss;
            msi[ss]+=money/ng;
        }
    }
    for(int i=0;i<np;i++)
    {
        cout<< vs[i]<<" "<<msi[vs[i]]<<'\n';
    }

    return 0;
}