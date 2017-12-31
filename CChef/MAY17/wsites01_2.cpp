
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
}vertex;

int global_flag = 0;

vertex * create_vertex()
{	
	vertex * node = new vertex;
	if(node)
	{
		node->isleaf = false;
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

void solve(string s, vertex * root , string astr)
{

	vertex * it = root;
	for(int i=0;i<s.size();i++)
	{
		if((it->edges)[s[i]-'a']==NULL)
		{
			astr+=s[i]-'a';
			break;
		}
		else
		{
			astr+=s[i]-'a';
			it = (it->edges)[s[i]-'a'];
		}
	}
	ansvec.pb(astr);
}



void print_tree(vertex * root)
{
	if(root==NULL)
		{
			cout<<"end reached"<<endl;
			return;
		}
	for(int i=0;i<26;i++)
	{
		if((root->edges)[i]!=NULL)
		{
			cout<<(char)(i+'a')<<endl;
			cout<<"islast = "<<root->islast<<endl;
			cout<<"isleaf = "<<root->isleaf<<endl;
			print_tree((root->edges)[i]);
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
	for(int i=0;i<plus_vec.size();i++)
	{
		insert(plus_vec[i], root);
	}
	print_tree(root);
	for(int i=0;i<minus_vec.size();i++)
	{
		string a;
		solve(minus_vec[i],root,a);
	}
	for(int i=0;i<ansvec.size();i++)
	{
		cout<<ansvec[i]<<" ";
	}



	return 0;
}
