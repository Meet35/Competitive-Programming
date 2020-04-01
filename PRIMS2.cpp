
int parent[10000],dist[10000],vis[10000];

std::vector<pair<int,int> > adj[100000],tree[100000];
void addEdge(int u,int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

void primMST(int src,int V)
{
    for(int i=0;i<=V;i++)
    {
        dist[i]=INT_MAX;
    }
    int cost=0;
	std::set<pair<int,int> > s;
	s.insert(make_pair(0,src));
	dist[src]=0;
	//parent[src]=src;
    while (!s.empty())
	{
		pair<int,int> x = *(s.begin());
        s.erase(x);
        cost+=x.first;
        int u=x.second;
        vis[x.second]=1;
        int v=parent[u];
        int w=x.first;
        tree[u].push_back(make_pair(v,w));
        tree[v].push_back(make_pair(u,w));
		for (int i=0 ; i<adj[u].size();i++)
		{
			int u1 = adj[u][i].first;
			int weight = adj[u][i].second;
			if (vis[u1]==1)
                continue;
            if(dist[u1]>weight)
			{
			    s.erase(make_pair(dist[u1],u1));
                dist[u1]=weight;
                s.insert(make_pair(dist[u1],u1));
				parent[u1]=x.second;
			}
		}
	}
	cout << cost << endl;
