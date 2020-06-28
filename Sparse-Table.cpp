vll a;
const int K = 28, N = 300005;
int Max[N][K], Min[N][K];
int LOG[N];
void build(ll n){
    ll i,j;
    fo(i,n){
        Max[i][0]=Min[i][0]=a[i];
    }
    for(j=1;(1<<j)<n;j++){
        fo(i,n){
            if(i+(1<<j)>=n) break;
            Max[i][j] = max(Max[i][j-1] , Max[i+(1<<(j-1))][j-1]);
            Min[i][j] = min(Min[i][j-1] , Min[i+(1<<(j-1))][j-1]);
        }
    }
}

int getmax(ll l, ll r){ //[l,r)
    int x = LOG[r-l];
    return max(Max[l][x], Max[r-x][x]);
}

int getmin(ll l, ll r){
    int x = LOG[r-l];
    return min(Min[l][x] , Min[r-x][x]);
}

void ass(ll n){
    a.resize(n);
    LOG[0]=LOG[1]=0;
    for(int i=2;i<=N;++i){
        LOG[i]=LOG[i/2]+1;
    }
}
