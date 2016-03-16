#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "Model.h"
#include "Model.cpp"

using namespace std;

// comments with double slash, original matlab in /* */
// Now available as a Model instance method

Model generate_random_model_uni(int num_resources, int num_subparts, int seed=0) {
    
    //allow for the seeding of the random model
    if (seed!=0) {
        srand((unsigned int) seed);
    } else {
        srand(time(NULL));
    }
    
    /*
    modelstruct = struct;
    modelstruct.prior = rand;
    */
    
    //Create a new Model object
    Model rand_model = Model(num_resources, num_subparts);
    
    //Set the prior to a random probability
    rand_model.prior = (double) rand()/RAND_MAX;
    
    /*
    As(2,1,:) = rand(1,num_resources)*.40;
    As(2,2,:) = 1-As(2,1,:);
    As(1,2,:) = 0;
    As(1,1,:) = 1;
    modelstruct.learns = As(2,1,:);
    modelstruct.forgets = As(1,2,:);
    */
    
    //initialize forgets to 0, and get random probabilities < .4 for learns
    for (int i=0; i<num_resources; i++) {
        rand_model.learns[i] = ((double) rand()/RAND_MAX)*.4;
        rand_model.forgets[i] = 0;
    }
    
    //then set the values of Model.As based on learns and forgets
    rand_model.make_as();
    
    /*
    given_notknow(2,:,:) = rand(1,num_subparts)*.40;
    modelstruct.guesses = given_notknow(2,:,:);
    given_know(1,:,:) = rand(1,num_subparts)*.30;
    modelstruct.slips = given_know(1,:,:);
    */
    
    //get random values for guesses and slips for each subpart
    for(int i=0; i<num_subparts; i++) {
        rand_model.guesses[i] = (rand()/RAND_MAX)*.4;
        rand_model.slips[i] = (rand()/RAND_MAX)*.3;
    }

    /* modelstruct.As = As; */
    //already done in line 38
    
    /* modelstruct.pi_0 = modelstruct.prior; */
    
    //discrepancy - pi_0 is a double[2] in random_model.m & hand_specified_models,
    // but is a single double == prior in random_model_uni.m
    rand_model.pi_0[0] = 1-rand_model.prior;
    rand_model.pi_0[1] = rand_model.prior;
    
    return rand_model;
}

int main() {
    Model rand_model = generate_random_model_uni(2,4,25);
    rand_model.state("test model");
}