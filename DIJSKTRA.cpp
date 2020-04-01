

int dist[100005],vis[100005];
std::vector<pair<int, int> > vt[100005];


void addEdge(int a , int b , int w)
{
    vt[a].push_back(make_pair(b,w));
    vt[b].push_back(make_pair(a,w));
}


void dijkstra(int source, int v)
{
    int i,sour,j;
	for(i=1;i<=v;i++)
	{
	    dist[i]=INT_MAX;
		vis[i]=0;
	}
	dist[source]=0;
	std::set<pair<int, int> > s;
	s.insert(make_pair(0, source));
	while(!s.empty())
	{
		pair<int,int> x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
        sour=x.second;
		for(i=0;i<vt[sour].size();i++)
		{
			if(dist[vt[sour][i].first] > vt[sour][i].second+dist[sour])
			{
				dist[vt[sour][i].first] = vt[sour][i].second+dist[sour];
				s.insert(make_pair(dist[vt[sour][i].first],vt[sour][i].first));
			}
		}
	}
	for(i=1;i<=v;i++)
    {
        cout << dist[i] <<  " ";
    }
}


