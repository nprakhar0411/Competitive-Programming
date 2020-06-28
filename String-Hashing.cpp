const int p1=31,p2=47,m1=(int)(1e9l+7),m2=(int)(1e9l+9), N=(int)(1e6l+5);
vvl hashes(N,vll(2));
vll pop1(N), pop2(N);

void ass(){
    pop1[0]=pop2[0]=1;
    for(int i=1;i<N;++i){
        pop1[i]=mul(pop1[i-1],p1,m1);
        pop2[i]=mul(pop2[i-1],p2,m2);
    }
}

void gethash(string & s){
    ll n = s(s), i;
    hashes[0][1]=hashes[0][0]=(s[0]-'a'+1);
    repa(i,1,n){
        hashes[i][0]=mul(hashes[i-1][0],p1,m1)+(s[i]-'a'+1);
        hashes[i][1]=mul(hashes[i-1][1],p2,m2)+(s[i]-'a'+1);
    }
}

pll sub_hash(ll l, ll r){ //[l,r] 0-indexed
    if(l==0) return {hashes[r][0],hashes[r][1]};
    return {(hashes[r][0]+m1-mul(hashes[l-1][0],pop1[r-l+1],m1))%m1 ,
                 (hashes[r][1]+m2-mul(hashes[l-1][1],pop2[r-l+1],m2))%m2};
}

pll hashstr(string & s){
    ll n = s(s), i;
    ll h1, h2;
    h1=h2=s[0]-'a'+1;
    repa(i,1,n){
        h1=mul(h1,p1,m1)+(s[i]-'a'+1);
        h2=mul(h2,p2,m2)+(s[i]-'a'+1);
    }
    return {h1,h2};
}
