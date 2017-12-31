
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
	int i=0;
	for(i=0;i<s.size();i++)
	{
		//cout<<"astr = "<<astr<<endl;
		//cout<<"str = "<<s<<endl;
		if((it->edges)[s[i]-'a']==NULL)
		{
			astr+=s[i];
			break;
		}
		else
		{
			astr+=s[i];
			it = (it->edges)[s[i]-'a'];
		}
	}
	if( (i==s.size() && it->isleaf) || (it->edges)[i]!=NULL )
	{
		global_flag = 1;
		return;
	}
	ansvec.pb(astr);
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
	for(int i=0;i<plus_vec.size();i++)
	{
		insert(plus_vec[i], root);
	}
	for(int i=0;i<minus_vec.size();i++)
	{
		string a;
		solve(minus_vec[i],root,a);
	}
	if(global_flag==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<ansvec.size();i++)
	{
		cout<<ansvec[i]<<endl;
	}
	
	root = new vertex;
	for(int i=0;i<ansvec.size();i++)
	{
		insert(ansvec[i],root);
	}
	ansvec.clear();
	string xxx;
	print_tree(root,xxx);
	cout<<ansvec.size()<<endl;
	for(int i=0;i<ansvec.size();i++)
	{
		cout<<ansvec[i]<<endl;
	}
	
	



	return 0;
}
