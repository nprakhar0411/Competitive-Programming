struct Node{
    ll sum=0;  
};

struct FT_2D{ // Everything is 0-indexed
    ll N, M;
    std::vector<std::vector<Node>> bit;
    void ass(ll m, ll n){ // m fenwick trees of length n
        N = n;
        M = m;
        bit.assign(m,std::vector<Node>(n));
    }

    void update(ll i, ll idx, ll val){
        for(;idx<N;idx = idx|(idx+1)) {
            bit[i][idx].sum += val;
        }
    }

    

    ll get(ll i, ll idx){
        ll sum = 0;
        for(;idx>=0; idx = (idx & (idx+1))-1) {
            sum += bit[i][idx].sum;
        }
        return sum ;
    }

    ll query(ll i, ll L, ll R){ // [L,R]
        if(L<=0) return get(i,R);
        return get(i, R) - get(i, L-1);
    }   

    ll query(ll i, ll L){
        return get(i, L);
    }

    ll bin_search(ll i, ll sum){ // Minimum index where prefix sum becomes
        ll l=0, r=N;       // greater than equal to sum. O(log2(n))
        ll mid;            
        while(r-l>=2){
            mid = (l+r)/2;
            if(get(i, mid-1)<sum) l = mid;
            else r=mid; 
        }
        if(get(i, l)>=sum) return l;
        return r;
    }
    ///Binary lifting in idxth Fenwick tree
    ll bin_lift(ll idx, ll sum){ // Minimum index where prefix sum becomes 
        ll pr = 0;       // greater than equal to sum. O(log(n))
        ll pos = 0; 
        ll LOGN = (ll)log2(N);
        for(ll i=LOGN;i>=0;--i){ 
            if(pos + (1LL<<i)-1 < N and pr + bit[idx][pos + (1LL<<i)-1].sum < sum){
                pr += bit[idx][pos + (1LL<<i)-1].sum;
                pos += (1LL<<i); 
            }
        }
        return pos; 
    }

}; // Everything is 0-indexed, Ranges are - [L,R]
