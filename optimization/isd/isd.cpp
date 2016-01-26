/*******************************************************************************
* Incremental Steepest Descent Algorithm
*
* Grant Williams
*
* Version 1.0.0
* December 26, 2015
*
* Implementation of the incremental steepest descent algorithm
*
* To Compile Please use icc -std=c++11 if using intel or g++ -std=c++11 if using GCC.
*
*
*    ______ ____      ____ _____ _____    _____    _____  
*  .' ___  |_  _|    |_  _|_   _|_   _|  |_   _|  |_   _| 
* / .'   \_| \ \  /\  / /   | |   | |      | |      | |   
* | |   ____  \ \/  \/ /    | |   | |   _  | |   _  | |   
* \ `.___]  |  \  /\  /    _| |_ _| |__/ |_| |__/ |_| |_  
*  `._____.'    \/  \/    |_____|________|________|_____|                                                        
*
*
*
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>


double get_rand(double HI, double LO){

    double r3 = LO + static_cast <double> (rand()) / (RAND_MAX / (HI - LO));

    return r3;
}

double f1(double x, double y) {

    // Beale's Function
    // minimum is 0 at (3,0.5)
    // boundaries are [-4.5, 4.5] for x & y
    return (1.5 - x + x * y) * (1.5 - x + x * y) + (2.25 - x + x * y * y) * (2.25 - x + x * y * y) + (2.625 - x + x * y * y * y) * (2.625 - x + x * y * y * y);
}

double x_partial(double x, double y) {

    double x_prime = (f1(x + 0.000001,y) - f1(x - 0.000001, y)) / 0.000002;
    return x_prime;
}

double y_partial(double x, double y) {

    double y_prime = (f1(x, y + 0.000001) - f1(x, y - 0.000001)) / 0.000002;
    return y_prime;
}

void seed_rand(){
    // seed random number
    srand (static_cast <unsigned> (time(0)));
}

double isd(){
    // Declare Variables
    double tol = 0.0000001; // tolerance for convergence
    int iter = 0;
    int max_iter = 100000; // maximum number of iterations


    // coefficients for gradient
    double const alpha = 1.1; // expansion
    double const beta = 0.5; // contraction
    double ds = 0.5; // gradient variable
    double x, y, grad, gradx, grady, coeff;
    double dx, dy;
    double last_fit, fit;

    // boundaries for variables
    double low = -4.5;
    double high = 4.5;

    // get initial guess
    double x0 = get_rand(low, high);
    double y0 = get_rand(low, high);


    bool constraint = true;

    /* begin actual ISD algorithm */



    last_fit = f1(x0,y0); // get initial fitness
    fit = last_fit;

    //begin main loop
    for (iter = 0; iter < max_iter; iter++){

        gradx = -1 * x_partial(x0, y0);
        grady = -1 * y_partial(x0, y0);
        grad = std::sqrt(gradx * gradx + grady * grady);

        if (grad == 0){
            //std::cout << "grad == 0 \n";
            return fit;
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

    if (iter == (max_iter -1)){
        std::cout << "Solution did not converge quickly enough \n";
    }else{
        //std::cout << "Gen: " << iter << " Min: " << fit << " x: " << x << " y: " << y << "\n";
        return fit;
    }

    return fit; // return our best value i guess

}


int main()
{

    //create seed for random numbers
    seed_rand();
    const int trials = 10000;
    std::vector<double> mins;

    // for stats printing
    double best = 100000;
    double avg;
    double avg_time;

    // start timing trials
    std::clock_t start;
    start = std::clock();

    // run all trials
    for (int i = 0; i < trials; i++){
        mins.push_back(isd());
    }

    // finish timing trials
    avg_time = ( std::clock() - start) / (double) CLOCKS_PER_SEC;

    // figure stats on our runs
    for (int j = 0; j < trials; j++){
        best = best < mins[j] ? best : mins[j];
        avg += mins[j];
    }

    avg /= trials;

    std::cout << "The best minimum was: " << best << "\nThe average minimum was: " << avg;
    std::cout << "\nThe total computation time was: " << avg_time << "\nThe average time was: " << avg_time / trials << "\n\n";

    return 0;
}
























