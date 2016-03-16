#include <iostream>
#include <string>
//#include <Eigen/Core>

#include "Model.h"
#include "Model.cpp"

using namespace std;
//using Eigen::MatrixXd;

void basicModel2(Model m) {
	m.num_resources = 2;
	m.num_subparts = 1;
	m.learns[0] = 0.25;
	m.learns[1] = 0.1;
	m.forgets[0] = 0;
	m.forgets[1] = 0;
	/*
	for (int n = 0; n<m.num_resources; n++) {
	m.As.col(2 * n) << 1 - m.learns[n], m.learns[n];
	m.As.col(2 * n + 1) << m.forgets[n], 1 - m.forgets[n];
	};
	*/
	m.make_as();
	//m.state("Inside constructor:");
	for (int n = 0; n<m.num_subparts; n++) {
		m.guesses[n] = .1;
		m.slips[n] = .03;
	}
	m.pi_0[0] = 0.9;
	m.pi_0[1] = 0.3;
	m.prior = m.pi_0[1];
}

int main()
{
	Model model2 = Model(2, 1);
	basicModel2(model2);
	model2.state("Model 2:");
}