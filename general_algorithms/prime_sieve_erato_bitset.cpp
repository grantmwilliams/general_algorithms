// Sieve Algorithm Based on Sieve of Eratosthenes Using Bitset
#include <iostream>
#include <bitset>
#define SIZE 2000000
#define MAX (int)(SIZE-3)/2

using namespace std;

long long sum = 0;                                                   //array that stores the primes up to sqrt(SIZE)
bitset<MAX+1> bset;                                                  //auxiliary bitset used to make the sieve

void setPrimes()
{
    int i,j;
    for(i=0;i*i<=SIZE;i++)                                           //we only have to get primes up to sqrt(SIZE)
        if(!bset.test(i))
            for(j=i+1;(2*j+1)*(2*i+3)<=SIZE;j++)
                bset.set(((2*j+1)*(2*i+3)-3)/2);                   //setting all non-primes
                                                         //store the first prime (that is 2)
    for(i=1,j=0;j<MAX+1;j++)
        if(!bset.test(j))
            sum+=2*j+3;                                        //store the remaining odd primes
    std::cout << "Sum of the first " << SIZE << " primes is: " << sum << std::endl;
    
}

int main(){
    

    setPrimes();
    
}