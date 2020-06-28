const double pi = acos(-1);
#include <complex>
#define cd complex<double>

ll get(vector<cd> & a, vector<cd> & b){
    ll n=1;
    while(n < s(a)+s(b)) n*=2;
    a.resize(n);
    b.resize(n);
    return n;
}

void fft(vector<cd> & a, ll invert){ // -1 for invert
    ll n = s(a);
    if(n==1) return ;
    vector<cd> a0(n/2), a1(n/2);
    ll i;
    for(i=0; 2*i<n;++i){
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
    
    ld ang = 2.0*pi/(1.0*n)*invert;
    complex<double> w(1,0), wn(cos(ang),sin(ang)); // Use cosl/sinl for higher precision.
    // debug(n,invert);
    for(i=0; 2*i<n;++i){
        a[i] = a0[i] + w*a1[i];
        a[n/2+i] = a0[i] - w*a1[i];
        w *= wn;
        if(invert==-1){
            a[i]/=2;
            a[n/2+i]/=2;
        }
    }
    return ;
}

vector<cd> p_mul(vector<cd> & a, vector<cd> &b){
    fft(a,1);
    fft(b,1);
    vector<cd> c;
    ll i;
    fo(i,s(a)) c.pb(a[i]*b[i]);
    fft(c,-1);
    return c;
}
