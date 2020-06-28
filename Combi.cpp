const int SIZE = 1001100;
ll fac[SIZE], ifac[SIZE];

void calc(){
    fac[0]=ifac[0]=1;
    ll i;
    repa(i,1,SIZE-1){
        fac[i]= mul(fac[i-1],i,mod);
        ifac[i]=powi(fac[i],mod);
    }
}

ll ncr(ll n , ll r){
    if(r>n or r<0) return 0;
    return mul(mul(fac[n],ifac[r],mod),ifac[n-r],mod);
}
