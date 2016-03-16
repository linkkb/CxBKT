#include <iostream>
#include <string>
#include "Model.h"

using namespace std;

Model::Model(int resources, int subparts) {
	num_resources = resources;
	num_subparts = subparts;
	learns = new double[resources];
	forgets = new double[resources];
	//As = MatrixXd(2, 2 * resources);
	As = new double[4 * resources];
	guesses = new double[subparts];
	slips = new double[subparts];
	//emissions = MatrixXd(2, 2 * subparts);
	emissions = new double[4 * subparts];
	pi_0 = new double[2];
	//conflicting pi_0's from random_model.m and random_model_uni.m
}

//sets the values of As based on the values of learns and forgets
void Model::make_as() {
	for (int n = 0; n < num_resources; n++) {
		as_put(0,0,n, 1-learns[n]);
		as_put(1,0,n, learns[n]);
		as_put(0,1,n, forgets[n]);
		as_put(1,1,n, 1-forgets[n]);
	}
}

//gets As values as if it were a zero-indexed Matlab matrix
double Model::as_get(int x, int y, int z) {
	return(As[x + 2*y + 4*z]);
}

//assigns As values as if using zero-indexed Matlab matrix
void Model::as_put(int x, int y, int z, double val) {
	As[x + 2*y + 4*z] = val;
}

//prints As as if it were a Matlab matrix
void Model::print_as() { 
	for (int i = 0; i < 4 * num_resources; i += 4) {
		cout << As[i] << "," << As[i+2] << endl;
		cout << As[i+1] << "," << As[i+3] << endl;
	}
}

//generates a random model as in generate.random_model_uni.m
void Model::generate_random(int seed) {
    if (seed!=0) {
        srand((unsigned int) seed);
    } else {
        srand(time(NULL));
    }
    prior = (double) rand()/RAND_MAX;
    for (int i=0; i<num_resources; i++) {
        learns[i] = ((double) rand()/RAND_MAX)*.4;
        forgets[i] = 0;
    }
    make_as();
    for(int i=0; i<num_subparts; i++) {
        guesses[i] = (rand()/RAND_MAX)*.4;
        slips[i] = (rand()/RAND_MAX)*.3;
    }
    pi_0[0] = 1-prior;
    pi_0[1] = prior;
}


void Model::print_learns() {
	for (int i=0; i < num_resources; i++) {
		cout << learns[i] << ", ";
	}
	cout << endl;
}

void Model::print_forgets() {
	for (int i=0; i < num_resources; i++) {
		cout << forgets[i] << ", ";
	}
	cout << endl;
}

void Model::state(string location) {
	cout << location << endl;
	cout << "Learns: " << endl;
	print_learns();
	cout << "Forgets: " << endl;
	print_forgets();
	cout << "As:" << endl;
	print_as();
}