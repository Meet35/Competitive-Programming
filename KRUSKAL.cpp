

std::vector<pair<int,pair<int,int> > > edge;


void addEdge(int u,int v,int w)
{
    edge.push_back(make_pair(w,make_pair(u,v)));
}

void KruskalMST(int V)
{
    int u,v,w,par_u,par_v;
    int i = 0;
    int cost=0;
    sort(edge.begin(),edge.end());

    DSU dsu(V);
    for(i=0;i<edge.size();i++)
    {
        u=edge[i].second.first;
        v=edge[i].second.second;
        w=edge[i].first;
        par_u=dsu.getPar(u);
        par_v=dsu.getPar(v);
        if(par_u!=par_v)
        {
            cost+=w;
            dsu.unite(par_u,par_v);
        }
    }
    cout << cost << endl;

    return;
}


