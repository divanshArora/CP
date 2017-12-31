
//TRIE hint from http://www.geeksforgeeks.org/longest-common-prefix-set-5-using-trie/
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


vector< string> plus_vec;
vector< string> minus_vec;



typedef struct vertex{

	vertex * edges[26];
	bool isleaf;
	bool islast;
}vertex;

int global_flag = 0;

vertex * create_vertex()
{	
	vertex * node = new vertex;
	if(node)
	{
		node->isleaf = false;
		node->islast = true;
		for(int i=0;i<26;i++)
		{
			(node->edges)[i] = NULL;
		}
	}

	return node;
}


void insert(string s, vertex * root)
{
	vertex * it = root;
	for(int i=0;i<s.size();i++)
	{

		if((it->edges)[s[i]-'a']==NULL)
		{
			(it->edges)[s[i]-'a'] = create_vertex();
		}
		it= (it->edges)[s[i]-'a'];
	}
	it->isleaf = true;
}
vector<string> ansvec; 

int solve(string s, vertex * root)
{
	int i=0;
	vertex * it = root;
	for(i=0;i<s.size();i++)
	{
		//cout<<" i = "<<i<<endl;
		if((it->edges)[s[i]-'a']==NULL)
		{
			//cout<<" found null "<<endl;
			if(i==s.size())
			{
				//cout<<"was leaf "<<endl;
				return -1;
			}
			else
			{
				//cout<<" returned "<<i<<endl;
				return i;
			}
		}
		else
		{
			//cout<<"wasn't null "<<endl;
			it = (it->edges)[s[i]-'a'];
		}
	}
	//cout<<" loop end returning -1"<<endl;
	return -1;
}



void print_tree(vertex * root, string s)
{
	vertex * it = root;
	if(it->isleaf==true)
	{
		ansvec.pb(s);
		return;
	}
	for(int i=0;i<26;i++)
	{
		if((it->edges)[i]!=NULL)
		{
					
			print_tree((it->edges)[i],s+(char)(i+'a'));
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string op;
		cin>>op;
		if(op=="+")
		{
			string str;
			cin>>str;
			plus_vec.pb(str);
		}
		else
		{
			string str;
			cin>>str;
			minus_vec.pb(str);

		}
	}
	
	vertex * root = create_vertex();
	root->islast = false;
	for(int i=0;i<plus_vec.size();i++)
	{
		insert(plus_vec[i], root);
	}
	/////////////////////////////////////
	set< string> ms;
	for(int i=0;i<minus_vec.size();i++)
	{

		int res = solve(minus_vec[i],root);
		if(res==-1)
		{
			cout<<-1<<endl;
			return 0;
		}
		else
		{
			ms.insert(minus_vec[i].substr(0,res+1));
		}
	}
	// if(global_flag==1)
	// {
	// 	cout<<-1<<endl;
	// 	return 0;
	// }
	cout<<ms.size()<<endl;
	for(auto it = ms.begin();it!=ms.end();it++)
	{
		cout<<*it<<endl;
	}


	return 0;
}
