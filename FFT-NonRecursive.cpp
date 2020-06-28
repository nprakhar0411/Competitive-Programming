#include<complex>
using cd = complex<ld>;
const ld PI = acos(-1);

ll get(vector<cd> & a, vector<cd> & b){
    ll n=1;
    while(n < s(a)+s(b)) n*=2;
    a.resize(n);
    b.resize(n);
    return n;
}

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, int invert) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }

    for (int len = 2; len <= n; len*=2) {
        ld ang = 2.0 * PI / len * invert;
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert==-1) {
        for (cd & x : a)
            x /= n;
    }
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
