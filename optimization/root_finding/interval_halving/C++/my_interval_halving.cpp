/*******************************************************************************
*
* Grant Williams
*
* Version 1.0.0
* August 27, 2015
*
* Interval Halving Polynomial Root Finder
*
* Input: function f (continuous), range[L,R], tolerance (TOL), max iterations (MAX_ITER).
*
* Conditions: L < R, f(L) * f(R) < 0.
*
* Output: X Value for root such that f(x) = 0 differs from the root by less than TOL
*
*******************************************************************************/

#include <iostream>
#include <ctime>

using namespace std;

double f(double x)
{
    return (x*x*x - 4*x - 9);
}

int main()
{

    //clock stuff
    std::clock_t start;
    double duration;
    start = std::clock();
    //stop clock stuff

    int MAX_ITER = 10000;
    double TOL = 0.00001;
    double L = -10, R = 10;
    double M;
    double fun_val;

    for (int iter = 1; iter < MAX_ITER; ++iter)
    {
        M = (L + R)*0.5; // New Midpoint
        fun_val = f(M);

        if( fun_val == 0 || ((R-L)*0.5) < TOL)
        {
            std::cout<< "After " << iter << " iterations, a root was found at: " << M << std::endl;

            //clock stuff again
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
            std::cout << "Elapsed time: " << duration << " seconds" << std::endl;

            return 0;
        
        } // end if statement

    if ((fun_val * f(L)) < 0)
        R = M;
    else
        L = M;

    } // end for loop

    std::cout << "The solution does not converge or iterations are not sufficient" << std::endl;


    //clock stuff again
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout<< "Elapsed time: " << duration << " seconds" << std::endl;

    return 1;
}








