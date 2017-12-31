//SEGMENT TREE FROM http://codeforces.com/blog/entry/18051
//Problem link: https://www.codechef.com/JULY17/problems/PSHTTR/
//Logic: 
/*
    Flatten tree to form array of cost. Give each node the cost of it's incoming edge using dfs
    like this: http://codeforces.com/blog/entry/43230
    Then make segment tree and follow this:
    https://stackoverflow.com/questions/39363745/find-the-number-of-elements-greater-than-x-in-a-given-range
*/
 
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define FF first
#define SS second
using namespace std;
 
 
 
bool mycomp(tuple<int, int, int, int> a, tuple<int, int, int, int> b)
{
     if(get<0>(a)<get<0>(b))
     {
         return true;
     }
     if(get<0>(a)>get<0>(b))
     {
         return false;
     }
     if(get<2>(a)<get<2>(b))
     {
         return true;
     }
     if(get<2>(a)>get<2>(b))
     {
         return false;
     }
     if(get<1>(a)<get<1>(b))
     {
         return true;
     }
     else
     {
         return false;
     }
}
int tree[(int)8e5];
int xortree[(int)8e5];
int answer[(int)8e5];
vector<int> arr;
vector< int> cost;
ll timewa= 0;
ll st[(int)1e5 + 3];
ll et[(int)1e5 + 3];
 
bool visited[(int)1e5 +3];
int wt[(int)1e5+3];
inline void dfs(int src, vector< vector< pair< int, ll> > > &graph )
{
        //cout<<" src entry  "<<src<< " time init "<< timewa<<endl;
        visited[src]= true;
        //arr.pb(src);
        st[src]= timewa;
        //timewa++;
        for(int i=0;i<graph[src].size();i++)
        {
            if(visited[graph[src][i].FF]==false)
            {
                //arr.pb(graph[src][i].FF);
                timewa++;
                cost.pb(wt[graph[src][i].FF]);
                dfs(graph[src][i].FF,graph);
            }
        }
        timewa++;
        //arr.pb(src);
        cost.pb(wt[src]);
 
        et[src] = timewa;
        //cout<<" src exit  "<<src<< " time exit"<< timewa<<endl;
}
 
int depth_arr[(int)1e5+3];
 
 
inline void dfs_par(int src, int depth,vector< vector< pair< int, ll> > > &graph  )
{
    depth_arr[src] = depth;
    visited[src] = true;
    for(int i=0;i<graph[src].size();i++)
    {
        if(visited[graph[src][i].FF]==false)
        {
            wt[graph[src][i].FF] = graph[src][i].SS;
            dfs_par(graph[src][i].FF,depth+1,graph);
        }
    }
}
 
inline void fill_array(vector< vector< pair< int, ll> > > &graph)
{
    //arr.pb(0);
    cost.pb(wt[0]);
    dfs(0,graph);
}
 
inline void print_depth(int n, vector< vector< pair< int, ll> > > &graph  )
{
    dfs_par(0,0,graph);
 
    for(int i=0;i<n;i++)
    {
        visited[i]= false;
    }
    fill_array(graph);
    //
    //debug(n);
}
 
 
inline void build(int n)
{
 
    for(int i=n-1;i>0;i--)
    {
        tree[i] = tree[2*i] ^ tree[2*i + 1];
    }
}
 
 
 
int query( int l, int r, int n)
{
    int res = 0;
    l+=n;r+=n;
    for(;l<r;l/=2,r/=2)
    {
        if(l&1)
        {
            res^=tree[l];
            l++;
        }
        if(r&1)
        {
            r--;
            res^=tree[r];
        }
    }
    return res;
}
void modify(int p, int value, int n) {  // set value at position p
  for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p]^ tree[p^1];
}
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cost.clear();timewa=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        vector< vector< pair< int, ll> > > graph(n+1);
        for(int i=0;i<n-1;i++)
        {
            int u,v;ll c;
            cin>>u>>v;cin>>c;
            u--;v--;
            graph[u].pb({v,c});
            graph[v].pb({u,c});
        }
        //fill_array(graph);
        //debug(n);
        print_depth(n,graph);
        //Base array for tree is cost
        for(int i=0;i<cost.size();i++)
        {
            //tree[i+cost.size()].clear();
            //xortree[i+cost.size()].clear();
            tree[i+cost.size()]=0;
            xortree[i+cost.size()]=0;
        }
        build(cost.size());
        vector<pair<int,int> >newarray;
        vector< tuple< int, int, int, int> > query_array;
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int u,v,k;
            cin>>u>>v>>k;
            u--;v--;
            query_array.pb(make_tuple(k,st[u],st[v],i));
            //int ans = query(0,st[u]+1,k,cost.size())^query(0,st[v]+1,k,cost.size());
            //cout<<ans<<'\n';
        }
 
        //NEW METHOD
        for(int i=0;i<cost.size();i++)
        {
            query_array.pb(make_tuple(cost[i],i,-1,-1));
        }
        sort(query_array.begin(), query_array.end(),mycomp);
        for(int i=0;i<query_array.size();i++)
        {
            //cout<<" "<<get<0>(query_array[i])<<" "<<get<1>(query_array[i])<<" "<<get<2>(query_array[i])<<" --"<<endl;
            if(get<2>(query_array[i])!=-1)
            {
                //GOT A QUERY
                int a = get<1>(query_array[i]);
                int b = get<2>(query_array[i]);
                answer[get<3>(query_array[i])] = query(0,a+1,cost.size())^query(0,b+1,cost.size());
            }
            else
            {
                //INSERT
                modify(get<1>(query_array[i]),get<0>(query_array[i]), cost.size());
            }
        }
        for(int i=0;i<m;i++)
        {
            cout<<answer[i]<<'\n';
        }
 
    }
    return 0;
}
 