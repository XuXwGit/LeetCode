# ifndef _MOD_H_
# define _MOD_H_

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

template<typename T>
T add(T x, T y){
    x % MOD;
    y % MOD;
    return (x + y)%MOD;
}

template<typename T>
T add(T x, T y, T m){
    x %= m;
    y %= m;
    return (x + y)%m;
}

template<typename T>
T sub(T x, T y){
    x %= MOD;
    y %= MOD;
    return (x - y + MOD)%MOD;
}

template<typename T>
T sub(T x, T y, T m){
    x %= m;
    y %= m;
    return (x - y + m)%m;
}

template<typename T>
T mul(T x, T y){
    x %= MOD;
    y %= MOD;
    return (x*y)%MOD;
}

template<typename T>
T mul(T x, T y, T m){
    x %= m;
    y %= m;
    return (x*y)%m;
}

template<typename T>
T fastPow(T x, T n){
    T res = 1;
    x %= MOD;
    while(n){
        if(n & 1){
            res = (res * x)%MOD;
        }
        x = (x*x)%MOD;
        n >>= 1;
    }
    return res;
}

template<typename T>
T fastPow(T x, T n, T m){
    T res = 1;
    x %= m;
    while(n){
        if(n & 1){
            res = (res * x)%m;
        }
        x = (x*x)%m;
        n >>= 1;
    }
    return res;
}

template<typename T>
T div(T x, T y){
    x %= MOD;
    y = fastPow(y, MOD-2);
    return (x*y)%MOD;
}

# endif // _MOD_H_