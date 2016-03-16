#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#include "Model.h"

using namespace std;

class Data {
public:
    int num_resources;
    int num_subparts;
    int num_observations;
    int bigT;
    vector<int> stateseqs;
    vector<int> data;
    vector<int> starts;
    vector<int> lengths;
    vector<int> resources;
    Data(Model, vector<int>);
    void generate_random(int seed=0);
};

#endif