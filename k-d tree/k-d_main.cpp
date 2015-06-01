#include <iostream>
#include <vector>
#include <boost/multi_array.hpp>

using namespace boost;
using namespace std;

#include "kdtree2.hpp"

typedef multi_array<float,2> array2dfloat;

main() {
        kdtree2 *tree; int N,d array2dfloat mydata; kdtree2_result_vector results;

// user sets d, dimensionality of Euclidean space and // N, number of poitns in the set.
        mydata.resize(extents[N][dim]); // get space for a N x dim matrix.

// read in vectors into mydata[i][j] for i=0..N-1, and j=0..d-1 // NOTE: array is in opposite order from Fortran, and is 0-based // not 1-based. This is natural for C++ just as the other was // natural for Fortran. In both cases, vectors are laid out
// contiguously in memory.
// notice, no need to allocate size of results, as that will be // handled automatically by the STL. results has most properties // of vector<kdtree2_result>.

        tree = new kdtree2(mydata,true); // create the tree, ask to rearrange tree->sort_results = true; // sort all results.
        tree->n_nearest_around_point(100,50,20,results);
// ask for 20 nearest neighbors around point 100, with correlation window // 50, push onto ’results’.
}
