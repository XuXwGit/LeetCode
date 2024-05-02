#ifndef QUICK_POW_H
#define QUICK_POW_H

#define MOD 1000000007

typedef long long LL;

// a^k mod p
int quick_pow(int a, int b, int p){
    int res = 1;
    a %= p;
    while(k){
        if(k & 1){
            res = ((LL)res * a) % p;
            k >>= 1;
            a = (LL)(a * a) % p;
        }
    }

    return res;
}


#endif // 