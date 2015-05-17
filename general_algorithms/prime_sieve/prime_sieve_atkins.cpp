//Implementation of Sieve of Atkins Using Vector Arrays
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void sieve_atkins(long long int n){
    long long int sum=0;
    vector<bool> is_prime(n+1);
    is_prime[2]=true;
    is_prime[3]=true;
    for (long long int i = 5; i <=n; i++) {
        is_prime[i]=false;
    }
    long long int lim = ceil(sqrt(n));
    for (long long int x = 1; x <= lim; x++) {
        for (long long int y = 1; y<=lim; y++) {
            long long int num = (4 * x * x + y * y);
            if (num <= n && (num % 12 == 1 || num % 12 == 5)) {
                is_prime[num]=true;
            }
            num = (3 * x * x + y * y);
            if (num <=n && (num%12 == 7)) {
                is_prime[num]=true;
            }
            if (x > y) {
                num = (3 * x * x - y * y);
                if (num <= n && (num % 12 == 11)) {
                    is_prime[num]=true;
                }
            }
        }
    }
    for (long long int i = 5; i<=lim; i++) {
        if (is_prime[i]) {
            for (long long int j = i*i; j<=n; j+=i) {
                is_prime[j]=false;
            }
        }
    }
    
    for (long long int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            sum += i;
        }
    }
    cout << sum<<endl;
}

int main(){
    
    long long int n = 2000000;
    cout<<"Sum of primes below "<<n<<" is: ";
    sieve_atkins(n);
    
    return 0;
    
}
