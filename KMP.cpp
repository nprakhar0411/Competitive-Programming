vll occ, pi;
void pre(string t){
    int m = s(t);
    pi.resize(m);
    int len=0, i=1;
    pi[0]=0;
    while(i<m){
        if(t[len]==t[i]){
            pi[i++]=++len;
        }else{
            if(len) len = pi[len-1];
            else{
                pi[i++]=0;
            }
        }
    }
}


ll search(string s, string pat) {
    ll n = s(s), m = s(pat);
    ll i=0, j=0;
    while(i<n) {
        if(s[i]==pat[j]){
            ++i;
            ++j;
            if(j==m){
                j = pi[j-1];
                occ.pb(i-m); //0-indexed occurence
            }
        }else{
            if(j) j=pi[j-1];
            else ++i;
        }
    }
    return s(occ);
}
