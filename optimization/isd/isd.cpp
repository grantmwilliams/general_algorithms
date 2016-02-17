/*******************************************************************************
* Incremental Steepest Descent Algorithm
*
* Grant Williams
*
* Version 1.0.0
* Feb 10, 2016
*
* Implementation of the incremental steepest descent algorithm
*
* To Compile Please use icc -std=c++11 if using intel or g++ -std=c++11 if using GCC.
*
*
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <chrono>
#include <future>


typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::duration<double> secs;


double f1(double x, double y) {

    // Beale's Function
    // minimum is 0 at (3,0.5)
    // boundaries are [-4.5, 4.5] for x & y
    return (1.5 - x + x * y) * (1.5 - x + x * y) + (2.25 - x + x * y * y) * (2.25 - x + x * y * y) + (2.625 - x + x * y * y * y) * (2.625 - x + x * y * y * y);
}

double x_partial(double x, double y, double step) {

    double x_prime = (f1(x + step, y) - f1(x - step, y)) / (2 * step);
    return x_prime;
}

double y_partial(double x, double y, double step) {

    double y_prime = (f1(x, y + step) - f1(x, y - step)) / (2 * step);
    return y_prime;
}

double isd(double tol, int max_iter, double step){

    // coefficients for gradient
    double const alpha = 1.1; // expansion
    double const beta = 0.5; // contraction
    double ds = 0.5; // gradient variable
    double x, y, grad, gradx, grady, coeff, dx, dy, last_fit, fit;

    // boundaries for variables
    double low = -4.5;
    double high = 4.5;

    // seed random number generator (is this the thread safe way to do this??)
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<double> unif(low,high);

    // get random initial guesses
    double x0 = unif(gen);
    double y0 = unif(gen);

    bool constraint = true;

    /* begin actual ISD algorithm */
    /*******************************************************************************/
    last_fit = f1(x0,y0); // get initial fitness
    fit = last_fit; // initialized current fitness

    int iter = 0; // has to be initlized here instead of in for loop because of if statement below for loop.

    //begin main loop
    for (; iter < max_iter; iter++){

        gradx = -1 * x_partial(x0, y0, step);
        grady = -1 * y_partial(x0, y0, step);
        grad = std::sqrt(gradx * gradx + grady * grady);

        if (grad == 0){
            return fit; // if gradient is 0 both derivatives are 0 so we are at a minimum point
        }

        coeff = ds / grad; // get cauchy coefficient

        // advance x and y by coefficient
        x = x0 + coeff * gradx;
        y = y0 + coeff * grady;

        if (x < low || x > high || y < low || y > high){
            constraint = false;
        }

        //get new fitness
        fit = f1(x,y);

        if (std::abs(fit-last_fit)<= tol){
            //std::cout << "fit: " << fit << " lastfit: " << last_fit << "\n";
            return fit;
        }

        dx = x - x0;
        dy = y - y0;

        if (std::abs(dx) <= tol && std::abs(dy) <= tol){
            //std::cout << "dx, dy\n";
            //std::cout << "x: " << x << " dx: " << dx << " y: " << y << " dy: " << dy << "\n";
            return fit;
        }

        // cauchy step was too big
        if (fit > last_fit || !constraint){

            ds *= beta;
        }else{

            ds *= alpha;
            last_fit = fit;
            x0 = x;
            y0 = y;
        }


    }

    if (iter == (max_iter - 1)){
        std::cout << "Solution did not converge quickly enough \n";
        return fit; // returns non minimum value
    }else{

        return fit; // return minimum
    }
}


int main()
{
    const int trials = 10000;

    // Declare Variables
    const double tol = 1e-7;    // tolerance for convergence
    const int max_iter = 1e4;   // maximum number of iterations before quitting without convergence
    const double step = 1e-7;   // step size for our derivative calculations

    std::vector<std::future<double> > mins; // allows parallel calculation of minimum values using async
    double temp; // needed to retrieve async values

    // for stats printing
    double best = 1e6; // arbitrarily large
    double avg = 0;


    // start timing trials
    auto start = Time::now();

    // run all trials
    for (int i = 0; i < trials; i++)
    {
        mins.push_back(std::async(isd, tol, max_iter, step));
    }


    // finish timing trials
    auto end = Time::now();
    secs avg_time = end - start;

    for (auto &e:mins)
    {
        temp = e.get();
        best = (best < temp) ? best : temp;
        avg += temp;
    }

    avg /= trials;

    std::cout << "Global minimum is: 0\n-----------------------------------------\n";
    std::cout << "The best minimum found: " << best << "\nThe average minimum was: " << avg;
    std::cout << "\nThe total computation time was: " << avg_time.count() << "\nThe average time was: " <<
    (avg_time.count()) / trials << "\n\n";

    return 0;
}





















