struct Gauss {
    ll LOGN ;
    vll table;
    void ass(ll bits){
        LOGN=bits;
        table.assign(bits+1,0);
    }
    
 
    ll size() {
        ll ans = 0;
        for(ll i = 0; i < LOGN; i++) {
            if(table[i]) ans++;
        }
        return ans;
    }
 
    bool can(ll x) {
        for(ll i = LOGN-1; i >= 0; i--) {
            x = std::min(x, x ^ table[i]);
        }
        return x == 0;
    }
 
    void add(ll x) {
        for(ll i = LOGN-1; i >= 0 && x; i--) {
            if(table[i] == 0) {
                table[i] = x;
                x = 0;
            } else {
                x = std::min(x, x ^ table[i]);
            }
        }
    }
 
    ll best() { //Maximum value acheivable
        ll x = 0;
        for(ll i = LOGN-1; i >= 0; i--) {
            x = std::max(x, x ^ table[i]);
        }
        return x;
    }
};
