
class DSU
{
    public:
    int connected;
    std::vector<int> par;
    std::vector<int> siz;
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            par.push_back(i);
            siz.push_back(1);
        }
        connected=n;
    }

    int getPar(int n)
    {
        if(n!=par[n])
        {
            par[n]=getPar(par[n]);
        }
        return par[n];
    }

    void unite(int x, int y)
    {
        int par_x=getPar(x);
        int par_y=getPar(y);
        if(par_x==par_y)
            return;

        connected--;

        if(siz[par_x]>siz[par_y])
        {
            siz[par_x]+=siz[par_y];
            par[par_y]=par_x;
        }
        else
        {
            siz[par_y]+=siz[par_x];
            par[par_x]=par_y;
        }
        return;
    }
};


