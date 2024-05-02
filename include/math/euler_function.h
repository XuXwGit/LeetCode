#ifndef OLA_FUNCTION_H
#define OLA_FUNCTION_H


typedef long long LL;

LL get_total_euler(int n){
    // Linear 
    vector<bool> isPrime(n + 1, true);
    vector<int> primes(n + 1, 0);
    vector<int> phi(n + 1, 0);
    phi[1] = 1;
    for(int i = 2; i<=n; ++i){
        if(isPrime[i]){
            primes[i] = i;
            phi[i] = i-1;
        }
        for(int j = 0; j * i <= n; ++j){
            isPrime[j * i] = false;
            if(i % primes[j] == 0){
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }

    int res = 0;
    for(int i = 1; i<=n; ++i){
        res += phi[i];
    }
    return res;
}


#endif // OLA_FUNCTION_H