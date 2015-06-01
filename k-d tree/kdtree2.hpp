//constructor
kdtree2(kdtree2_array& data_in, bool rearrange_in = true, int dim_in = -1);

//destructor
~kdtree2();

//set to true to always sort
bool sort_results;
void n_nearest(vector<float>& qv, int nn, kdtree2_result_vector& result);

//search for n nearest to a given query vector 'qv'
void n_nearest_around_point(int idxin, int correltime, int nn, kdtree2_result_vector& result);
