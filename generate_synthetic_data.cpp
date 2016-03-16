#include <iostream>
#include <string>
#include <vector>
//#include <Eigen/Core>

#include "Model.h"

#include "Data.h"
#include "Data.cpp"

using namespace std;

Data generate_synthetic_data(Model m, vector<int> obs_seq_lengths) {
    Data d = Data(m,obs_seq_lengths);
    return d;
}