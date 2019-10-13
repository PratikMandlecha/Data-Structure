#include<bits/stdc++.h>
using namespace std;
// Declare adjacency list in form of vector of pairs containing (weights,vertex 2)
// Declare Set of pair <int,int> for weights from source to vertex , vertex. Also dist and vis arrays.
/*
insert source in S.
curr = *(S.begin())
relax all nodes in a[curr.second];
if distance is less than initial value then update distances and insert that back into set S.


*** Check whether directed or not graph. ***
*/
# define M 1000010
# define pb push_back

int dist[M],vis[M];
vector<pair<int , int > > a[M];
set <pair<int,int> > S;

int main()
{
	int i,x,y,w,n,m;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y>>w;
		a[x].pb(make_pair(w,y));
		a[y].pb(make_pair(w,x));
	}
	dist[1]=0;
	for(i=2;i<=n;i++)
	{
		dist[i]=INT_MAX;
	}
	S.insert(make_pair(0,1));
	pair<int,int> curr;
	int node,wt;
	while(!S.empty())
	{
		curr = *(S.begin());
		node = curr.second;
		wt   = curr.first;
		S.erase(S.begin());
		if(vis[node]==1)
			continue;
		int l=a[node].size(),v;
		for(i=0;i<l;i++)
		{
			w=a[node][i].first;
			v=a[node][i].second;
			if(dist[v]>w+dist[node])
			{
				dist[v]=w+dist[node];
				a[node][i].first=dist[v];
				S.insert(a[node][i]); // Red node it is not the shortest but the updated weight 
			}
		}
		vis[node]=1;
	}
	for(i=2;i<=n;i++)
	{
		cout<<dist[i]<<" ";
		// cout<<"Shortest Distance to vertex "<<i<<" -> "<<dist[i]<<endl;
	}
	return 0;
}