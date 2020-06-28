vll lis, lds;
ll LIS(vector<ll> const& a) {
    ll n = a.size();
    lis.resize(n);
    const ll INF = 2e18;
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (ll i = 0; i < n; ++i) {
        ll j = upper_bound(all(d), a[i]) - d.begin();

        // if (d[j-1] <= a[i] && a[i] <= d[j]) { //Longest non-decreasing subsequence
        //     d[j] = a[i];
        //     lis[i]=j;
        // }

        //Uncomment if Longest strictly increasing needed
        ll k = lower_bound(all(d), a[i]) - d.begin();
        lis[i]=k;
        if (d[j-1] < a[i] && a[i] < d[j]) { 
            d[j] = a[i];
        }
        
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

ll LDS(vector<ll> const& a) {
    ll n = a.size();
    lds.resize(n);
    const ll INF = 2e18;
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (ll i = n-1; i>=0; --i) {
        ll j = upper_bound(all(d), a[i]) - d.begin();

        // if (d[j-1] <= a[i] && a[i] <= d[j]) { //Longest non-increasing subsequence
        //     d[j] = a[i];
        //     lds[i]=j;
        // }

        //Uncomment if Longest strictly decreasing needed
        ll k = lower_bound(all(d), a[i]) - d.begin();
        lds[i]=k;
        if (d[j-1] < a[i] && a[i] < d[j]) { 
            d[j] = a[i];
        }

    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
