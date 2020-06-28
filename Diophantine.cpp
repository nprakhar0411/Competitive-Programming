#define ill __int128
ill egcd(ill a, ill b, ill &x, ill &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ill x1, y1;
    ill d = egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}


struct Diophantine{
    ill Xmin=-1, Xmax=-1;
    ill L, R;
    bool find_any(ill a, ill b, ill c, ill &x, ill &y, ill &g){
        ill _a = (a<0) ? -a : a;    //Checks if there exists a solution
        ill _b = (b<0) ? -b : b;
        g = egcd(_a,_b,x,y);
        if(c%g){
            return false;
        }
        x*=c/g;
        y*=c/g;
        if(a<0) x=-x;
        if(b<0) y=-y;
        return true;
    }

    void shift(ill &x, ill &y, ill a, ill b, ill cnt){
        x += cnt*b;
        y -= cnt*a;
    }

    vector<pll> print_all(ill a, ill b, ill c){
        ill g = __gcd(a,b);
        ll xmin=L, xmax=R;
        vector<pll> soln;
        while(xmin<=xmax){
            // cout << xmin << ' '<<(c-a*xmin)/b << endl;
            ill x = xmin;
            ill y = (c-a*xmin)/b;
            soln.pb({x,y});
            xmin += b/g;
        }
        return soln;
    }

    pll print_any(ill a, ill b, ill c){
        // cout << xmin << ' '<<(c-a*xmin)/b << endl;
        return {L, (c-a*L)/b};
    }

    ill find_interval(ill a, ill b, ill c, ill minx, ill maxx, ill miny, ill maxy){ 
        ill x, y, g;                                // returns number of soln.
        if(!find_any(a,b,c,x,y,g)){
            return 0;
        }
        a/=g;
        b/=g;
        c/=g;
        int sign_a = a>0 ? 1 : -1;
        int sign_b = b>0 ? 1 : -1;

        shift(x,y,a,b,(minx-x)/b);
        if(x<minx) shift(x,y,a,b,sign_b);
        if(x>maxx) return 0;
        ill lx1=x;

        shift(x,y,a,b,(maxx-x)/b);
        if(x>maxx) shift(x,y,a,b,-sign_b);
        ill rx1=x;

        shift(x,y,a,b,-(miny-y)/a);
        if(y<miny) shift(x,y,a,b,-sign_a);
        if(y>maxy) return 0;
        ill lx2=x;

        shift(x,y,a,b,-(maxy-y)/a);
        if(y>maxy) shift(x,y,a,b,sign_a);
        ill rx2=x;

        if(lx1>rx1) swap(lx1,rx1);
        if(lx2>rx2) swap(lx2,rx2);
        ill lx = max(lx1,lx2);
        ill rx = min(rx1,rx2);
        
        if(lx>rx) return 0;
        L=(ill)(lx);
        R=(ill)(rx);

        return (b<0) ? (lx-rx)/b+1 : (rx-lx)/(b)+1;
    }

};
