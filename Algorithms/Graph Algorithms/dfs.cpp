/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> adj[100010];
int vis[100010];
int dfs(int i,int co)
{
	vis[i]=1;
	cout<<i<<" ";
	int l=adj[i].size();
	for(int j=0;j<l;j++)
	{
		if(!vis[adj[i][j]])
		{
			co=dfs(adj[i][j],co+1);
		}
	}
	return co;
}						
int main()
{
	int i,a,b,n,m,cc=0;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int max=0,c;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			int c = dfs(i,1);
			if(c>max) max=c;
			cc++;
		}
	}
	cout<<"\n Max connections : "<<max<<"\n";
	return 0;
}
