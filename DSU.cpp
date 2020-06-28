struct DSU{
    vll par , sz;
    ll components=0;
    void ass(ll n){
        par.resize(n+1);
        iota(all(par),0);
        sz.assign(n+1,1);
        components=n; // Assigning n+1 sized vector according to 1-based or 0-based
    }

    void make_set(ll v){
        par[v]=v;
        sz[v]=1;
        ++components;
    }

    ll find_set(ll v){
        if(par[v]==v) return v;
        return par[v] = find_set(par[v]);
    }

    void union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
            --components;
        }
    }
    
};
