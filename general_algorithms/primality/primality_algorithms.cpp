/* Grant Williams | Hw1 - Primalilty Algorithms
 * CWID: 11504292
 * Program is capable of determining whether or not a number is prime. 
 * The program makes use of a number of different algorithms and prints to stdout.
 */

#include <cmath>
#include <vector>
#include <iostream>
#include <random>

#define ll long long            // just easier to read in my opinion

/*---------- define macros for time keeping ----------*/

/*
 * use example:
 * start_t;
 * std::cout << fib(42) << std::endl;
 * end_t
 * diff_t
 * sec_t
 * print_t
 */


// start timer
#define start_t auto start = std::chrono::high_resolution_clock::now();

// end timer
#define end_t auto end = std::chrono::high_resolution_clock::now();

// get time difference as chrono object
#define diff_t auto diff = std::chrono::duration_cast< std::chrono::duration<double> > (end-start);

// get time difference as double
#define sec_t double seconds = diff.count();

// print time differences
#define print_t std::cout << "Total Elapsed Time: " << seconds << "s \n" << "Average Time Per Number: " << seconds / num_primes << "s\n";

/* ----------------------- Helper Functions ----------------------- */

// function to get our possible primes for testing
// input is the number of possible primes to test, and the lower and uppper bound to create them.
// function returns a uniform distribution for the possible primes
std::vector<ll> get_primes(const int num_primes, ll low, ll high){

    std::vector<ll> possible_primes;
    // for random numbers
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<ll int> distr(low, high); // define the range

    for(int i=0; i<num_primes; ++i) {
        possible_primes.push_back(distr(eng)); // generate numbers
    }

    return possible_primes;
}



// this function calculates (a*b)%c taking into account that a*b might overflow.
// input is long long a, b, c.
// optimized to use bitwise arithmetic whenever possible.
ll mulmod(ll a,ll b,ll c){

    ll x = 0,y=a%c;

    while(b > 0){

        if((b&1)){ // b % 2
            x = (x+y)%c;
        }

        y = (y*2)%c;
        b >>= 1; // b /= 2
    }
    return x % c;
}



// This function calculates (ab)%c.
// input is long long a, b, c.
// optimized to use bitwise arithmetic whenever possible and uses the much faster mulmod() function
// instead of calculating (a*b)%c.
ll modulo(ll a,ll b,ll c){

    ll x=1,y=a; // ll is taken to avoid overflow of intermediate results

    while(b > 0){
        if((b&1)){ // b%2
            x = mulmod(x,y,c);
        }

        y = mulmod(y,y,c); // squaring base

        b >>= 1; // b/= 2
    }
    return x % c;
}


/* --------------------Implementations----------------------------- */

/* O(n*sqrt(n)/(log n)^2)
 * no optimizations at all */
void naive(std::vector<ll> &primes, bool debug){

    ll num;
    bool flag = true;
    for (int i = 0; i < primes.size(); i++) {

        num = primes[i]; // pull the number to check off the array

        if (num < 2) {
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
            }
            continue; // goes to next prime to check
        }
        else if (num == 2) {
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " prime\n";
            }
            continue; // goes to next prime to check
        }
        else {
            for (int j = 3; j < num; j++) {
                if (num % j == 0) {
                    if (debug) {
                        //if we are debugging print the number
                        std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
                    }
                    flag = false;
                    break;
                }

            } // we checked every possiblility so it must be true

            if (flag) { // if we checked all possiblities
                if (debug) {
                    //if we are debugging print the number
                    std::cout << (i + 1) << ": " << primes[i] << " prime\n";
                }
            }
        }
            flag = true; // reset flag back to true

    } // ends primes to check
} // ends naive implementation

// O(n*sqrt(n)/(log n)^2) but smaller constant?
void trial_div(std::vector<ll> &primes, bool debug) {

    ll num;
    bool flag = true;

    for (int i = 0; i < primes.size(); i++) {

        num = primes[i]; // set number to current number to check

        if (num < 2) {
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
            }
            continue; // go to next prime
        }
        else if (num == 2) {
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " prime\n";
            }
            continue; // go to next prime
        }
        else if (num == 3) {
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " prime\n";
            }
            continue; // go to next prime
        }
        else if (!(num&1)) { // num % 2 == 0
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
            }
            continue; // go to next prime
        }

        else if (num % 3 == 0) { 
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
            }
            continue; // go to next prime
        }

        for (int j = 5; j * j < num; j += 6) { // begin to check other numbers
            if (num % j == 0 || num % (j + 2) == 0) {
                if (debug) {
                    //if we are debugging print the number
                    std::cout << (i + 1) << ": " << primes[i] << " not prime 1\n";
                }
                flag = false;
                break; // breaks loop checking this number
            } // if statement for divisibility
        } // trial division for loop

        if (debug) {
            if (flag) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " prime\n";
            }
        }
            flag = true; // reset flag back to true
    } // ends primes to check
} // ends trial division function

// O( k * log(n)^3 ) in this case k = 12, and the algorithm is deterministic instead of probabilistic
void miller_rabin(std::vector<ll> &primes, bool debug){

    /*
     * instead of testing random numbers in the algorithm we use a set of preset values as shown in vector arr.
     * the values have been proven to allow for the algorithm to deterministically evaluate whether
     * the input number, n, is prime assuming n < 18,446,744,073,709,551,616.
     *
     * Feitsma and Galway first proved this statement for n < 3,825,123,056,546,413,051.
     *
     * Jiang and Deng followed with a second (and separate) proof that verified Feitsma and Galway in their paper:
     * "Strong pseudoprimes to the first eight prime bases". Mathematics of Computation (2014)
     *
     * Sorenson and Jonathan extended the proof for n < 18,446,744,073,709,551,616.
     * Sorenson, Jonathan; Webster, Jonathan (2015). "Strong Pseudoprimes to Twelve Prime Bases"
     *
     */

    ll num; bool flag = true;

    std::vector<int> arr = {2,3,5,7,11,13,17,19,23,29,31,37}; // numbers to test with mod

    for (int i = 0; i < primes.size(); i++){
        num = primes[i]; // set num as current prime to test

        if(num<2){
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
            }
            continue; // go to next prime
        }
        if(num!=2 && !(num&1)){ // num%2 == 0
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
            }
            continue; // go to next prime
        }

        ll s=num-1;

        while(!(s&1)){ // while s % 2 == 0
            s >>= 1; // s /= 2
        }

        for(int j=0;j<arr.size();j++){

            ll a = arr[j],temp = s;
            ll mod=modulo(a,temp,num);

            while(temp!=num-1 && mod!=1 && mod!=num-1){

                mod=mulmod(mod,mod,num);
                temp <<=1; // temp *= 2
            }
            if(mod!=num-1 && !(temp&1)){ //temp%2 == 0
                if (debug) {
                    //if we are debugging print the number
                    std::cout << (i + 1) << ": " << primes[i] << " not prime\n";
                }
                flag = false;
                break; // breaks inner loop
            }
        }
        if(flag){
            if (debug) {
                //if we are debugging print the number
                std::cout << (i + 1) << ": " << primes[i] << " prime\n";
            }
        }
        flag = true; // reset flag back to true
    } // ends primes to check
} // ends miller function



/* ---------------------Testing Function--------------------------- */
void test_algorithms(std::vector<bool> algs, ll low, ll high, int num_primes, bool debug){

    // gets the numbers we actually want to test
    std::vector<ll> possible_primes = get_primes(num_primes, low, high);


    // function testing actually goes here!
    for (int i = 0; i < algs.size(); i++){

        if (i == 0 && algs[i]){ // naive division function
            std::cout << "Naive Trial Division: " << std::endl;
            start_t
            naive(possible_primes,debug);
            end_t
            diff_t
            sec_t
            print_t
        }
        else if (i == 1 && algs[i]){ // trial division function
            std::cout << "Optimized Trial Division: " << std::endl;
            start_t
            trial_div(possible_primes,debug);
            end_t
            diff_t
            sec_t
            print_t
        }else if(i == 2 && algs[i]){
            std::cout << "Miller-Rabin: " << std::endl;
            start_t
            miller_rabin(possible_primes,debug);
            end_t
            diff_t
            sec_t
            print_t
        }

        if (i != algs.size() - 1)
            std::cout << "-------------------------------------------------\n";
    }
}


int main(){

    ll low = 1000000000000000000 - 150000, high = 1000000000000000000; // ranges for our numbers to test
    int num_primes = 10;
    bool debug = 1; // used to debug algorithms with printing
    std::vector<bool> algs;

    // change these to set which algorithms to test.
    bool naive_alg =        false;       algs.push_back(naive_alg);
    bool trial_div_alg =    true;       algs.push_back(trial_div_alg);
    bool miller_rabin_alg = true;       algs.push_back(miller_rabin_alg);


    test_algorithms(algs, low, high, num_primes, debug);



    return 0;
}



