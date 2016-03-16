#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

using namespace std;

class Model {
public:
	int num_resources;
	int num_subparts;
	double* learns;
	double* forgets;
	//MatrixXd As;
	double* As;
	double* guesses;
	double* slips;
	//MatrixXd emissions;
	double* emissions;
	double* pi_0;
	double prior;
	Model(int, int);
	void make_as();
	double as_get(int, int, int);
	void as_put(int, int, int, double);
	void generate_random(int seed=0);
	void print_as();
	void print_learns();
	void print_forgets();
	void state(string);
};

#endif