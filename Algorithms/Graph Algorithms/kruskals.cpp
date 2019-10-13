/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;

# define M 100010
# define pb push_back
int id[M],nodes,edges;
pair<long long , pair<int,int> > p[M];
vector<int> v1,v2;
vector <long long> W;
void init()
{
	for(int i=0;i<M;i++)
		id[i]=i; //id[i] -> parent of i. Initially parent of i is i itself.
}

int root(int x)
{
	while(id[x]!=x)
	{
		int temp=id[x];
		id[x]=id[id[x]];
		x=temp;
	}
	return x;
}

void union1(int x, int y)
{
	int p = root(x);
	int q = root(y);
	id[p]=id[q];
}

long long kruskals(pair<long long, pair<int,int> > p[])
{
	int x,y;
	long long w,ans=0;
	for(int i=0;i<edges;i++)
	{
		x=p[i].second.first;
		w=p[i].first;  // only .first here.
		y=p[i].second.second;
		if(root(x)!=root(y))
		{
			ans+=w;
			union1(x,y);
			v1.pb(x);
			v2.pb(y);
			W.pb(w);
		}
	}
	return ans;
}
int main()
{
	cin>>nodes>>edges;
	init();
	int x,y;
	long long w;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y>>w;
		p[i]=make_pair(w,make_pair(x,y));
	}
	sort(p,p+edges);
	long long ans = kruskals(p);
	cout<<ans<<endl;
	
	int l=v1.size();
	for(int i=0;i<l;i++)
	{
		cout<<"edge added -> "<<v1[i]<<"- "<<v2[i]<<" weight is "<<W[i]<<endl;
	} 
	return 0;
}
