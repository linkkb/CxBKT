// xBKT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define NUM_SUBPARTS 4
#define NUM_RESOURCES 2

struct Model { //these will need to become vectors

	double prior;
	double learns[NUM_RESOURCES];
	double forgets[NUM_RESOURCES];
	double guesses[NUM_SUBPARTS];
	double slips[NUM_SUBPARTS];
	double as[2][2][NUM_RESOURCES];
	double emissions[2][2][NUM_SUBPARTS];
	double pi_0[2];
};

struct TrueModel { //also need to be vectors
	int as[2][2][NUM_RESOURCES];
	int learns[NUM_RESOURCES];
	int forgets[NUM_RESOURCES];
	int pi_0[2];
	int prior;
	int guesses[NUM_SUBPARTS];
	int slips[NUM_SUBPARTS];
	int resources[50*100]
};

struct DataStruct {
	//as defined in generate.synthetic_data
	//look into how to implement <cstdint> as data lengths are specified there.
	int stateseqs[5000]; //vectorize
	int data[4][5000]; //vectorize
	int starts[50]; //vectorize
	int lengths[50]; //vectorize
	int resources;
};



DataStruct generate_synthetic_data(TrueModel model, int lengths[], int resources[])
{
	int resources;
	int starts[2]; //vectorize
	int stateseqs[5000]; //vectorize
	int data[4][5000]; //vectorize
	(data, statesques) = synthetic_data_helper(model, starts, lengths, resources); //translate to C
	//Note to self: learn to parse mxFunctions, and analyze syntheticdatahelper.
	DataStruct datastruct;
	//Then we fill in the fields of DataStruct
	return datastruct;
}

//wow that's a lot of inputs - good thing we only use two, right?
Model generate_random_model(int num_resources, int num_subparts, int trans_prior = NULL, 
	int given_notknow_prior = NULL, int given_know_prior = NULL, int pi_0_prior = NULL)
{
	//a lot of stuff happens here. First, checking to see if variables exist, and if not, defining them.
	//then a call to util.dirrnd, which does like 2 lines of matlab stuff to it. (probably 20 in c)
	//then you fill in the struct with the modified data.
}

model M_step(int trans_softcount[][][], int emission_softcounts[][][], int init_softcounts[][])
{
	//lots of matlab functions happen here
	//but it mostly seems to be formatting and element-by-element operations on arrays
	//look into ensuring these stay optimized! Don't want to cost users efficiency.
}

pair<Model model, int log_likelihoods[]> EM_fit(Model model, DataStruct data, long tol = NULL, int maxiter = NULL)
{
	//define inputs that don't exist
	//use util.data to make sure the data is valid
	int num_subparts = size(data.data, 1); //translate from matlab
	int num_resources = length(model.learns); //translate from matlab

	int trans_softcounts[2][2][num_resources];
	int emission_softcounts[2][2][num_subparts];
	int init_softcounts[2][1];
	int log_likelihoods[maxiter][1];
	for (i = 1 : maxiter)
	{
		log_likelihoods[i] = E_step(data, model, trans_softcounts, emission_softcounts, init_softcounts);
		if (i > 1 && abs(log_likelihoods(i) - log_likelihoods(i - 1)) < tol)
		{
			break;
		}
		model = M_step(trans_softcounts, emission_softcounts, init_softcounts);
	}
	log_likelihoods = log_likelihoodes(1:i) // translate from matlab
}

void hand_specified_model_1()
{
	cout << "Running test.\n";
	int num_subparts = 4;
	int num_resources = 2;
	int num_fit_initializations = 25;
	int obs_seq_lengths[50];
	fill_n(obs_seq_lengths, 50, 100);
	//Fill in truemodel
	TrueModel truemodel;
	//generate data
	DataStruct data = generate_synthetic_data(truemodel, obs_seq_lengths);

	//fit a model to the data (this is matlab code that hasn't actually been rewritten)

	long best_likelihood = -1;
	for (i = 1 : num_fit_initializations)
	{
		// util.print_dot(i, num_fit_initializations); //This literally just prints stuff
		Model fitmodel = generate_random_model(num_resources, num_subparts);
		//fitmodel = truemodel; //NOTE: include this line to initialize at the truth
		[fitmodel, log_likelihoods] = EM_fit(fitmodel, data);
		if (log_likelihoods(end) > best_likelihood)
		{
			best_likelihood = log_likelihoods(end);
			best_model = fitmodel;
		}
	}
	
}

int main()
{
	string text;
	cout << "Welcome to xBKT. Hit enter to begin test.\n";
	getline(cin, text);
	cout << "Beginning test.\n";
	hand_specified_model_1();
	cout << "Test over.\n";
	getchar();
	return 0;
}
