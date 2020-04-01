
std::vector< pair<int,int> > vt[10000];

void addEdge(int a,int b,int w)
{
    vt[a].push_back(make_pair(b,w));
    vt[b].push_back(make_pair(a,w));
}

void bellmanFord(vector< pair<int,int> > vtt[],int source,int v)
{
    int i,j;
    int n=v;
    int parent[n+1];
    int dist[n+1];
    for(i=0;i<n+1;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    parent[source]=source;
    for(i=1;i<n+1;i++)
    {
        for(j=0;j<vtt[i].size();j++)
        {
            if(dist[i]!=INT_MAX && dist[i]+vtt[i][j].second<dist[vtt[i][j].first])
            {
                dist[vtt[i][j].first]=dist[i]+vtt[i][j].second;
                parent[vtt[i][j].first]=i;
            }
        }
    }
    for(i=1;i<=v;i++)
    {
        cout << dist[i] <<  " ";
    }
}


