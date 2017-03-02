#include<bits/stdc++.h>
#define ll long long 
using namespace std; 
int main(){
	string s;
	getline(cin,s);int count =1;int e=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ' || (s[i]>='0'&&s[i]<='9'))cout<<s[i];
		else{ if(s[i]>='A' && s[i]<='Z')
			{cout<<(char)(s[i]+ e*count);e=-e;
			}
		else {cout<< (char)(s[i]+e*count); e=-e;}if(e==1){count++;}}
	}
	return 0;
}