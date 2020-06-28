
struct Node{
    ll sum=0;  
};

struct FT{ // Everything is 0-indexed
    ll N;
    std::vector<Node> bit;
    void ass(ll n){
        N = n;
        bit.resize(n);
    }

    void update(ll idx, ll val){
        for(;idx<N;idx = idx|(idx+1)) {
            bit[idx].sum += val;
        }
    }

    void build(vll const & a){
        for(ll i=0; i<s(a); ++i) {
            update(i,a[i]);
        }
    }

    ll get(ll idx){
        ll sum = 0;
        for(;idx>=0; idx = (idx & (idx+1))-1) {
            sum += bit[idx].sum;
        }
        return sum ;
    }

    ll query(ll L, ll R){ // [L,R]
        if(L<=0) return get(R);
        return get(R) - get(L-1);
    }   

    ll query(ll L){
        return get(L);
    }

    ll bin_search(ll sum){ // Minimum index where prefix sum becomes
        ll l=0, r=N;       // greater than equal to sum. O(log2(n))
        ll mid;            
        while(r-l>=2){
            mid = (l+r)/2;
            if(get(mid-1)<sum) l = mid;
            else r=mid; 
        }
        if(get(l)>=sum) return l;
        return r;
    }

    ll bin_lift(ll sum){ // Minimum index where prefix sum becomes 
        ll pr = 0;       // greater than equal to sum. O(log(n))
        ll pos = 0; 
        ll LOGN = (ll)log2(N);
        for(ll i=LOGN;i>=0;--i){ 
            if(pos + (1LL<<i)-1 < N and pr + bit[pos + (1LL<<i)-1].sum < sum){
                pr += bit[pos + (1LL<<i)-1].sum;
                pos += (1LL<<i); 
            }
        }
        return pos; 
    }

}; // Everything is 0-indexed, Ranges are - [L,R]
