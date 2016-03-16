#include <iostream>
#include <string>
#include <vector>
//#include <Eigen/Core>

#include "Model.h"
#include "Model.cpp"

#include "Data.h"

#include "generate_synthetic_data.cpp"
//#include "generate_random_model_uni.cpp"

using namespace std;
//using Eigen::MatrixXd;

void basicModel1(Model m) {
	m.num_resources = 2;
	m.num_subparts = 4;
	m.learns[0] = 0.25;
	m.learns[1] = 0.1;
	m.forgets[0] = 0.1;
	m.forgets[1] = 0.1;
	/*
	for (int n = 0; n<m.num_resources; n++) {
		m.As.col(2 * n) << 1 - m.learns[n], m.learns[n];
		m.As.col(2 * n + 1) << m.forgets[n], 1 - m.forgets[n];
	};
	*/
	m.make_as();
	//m.state("Inside constructor:");
	for (int n = 0; n<m.num_subparts; n++) {
		m.guesses[n] = .05;
		m.slips[n] = .25;
	}
	m.pi_0[0] = 0.9;
	m.pi_0[1] = 0.1;
	m.prior = m.pi_0[1];
}

int main()
{
	Model model1 = Model(2, 4);
	basicModel1(model1);
	if (model1.as_get(0,0,0)==.75) {
		cout << "\033[1;32m" << "model constructed successfully" << "\033[0m" << endl;
	} else {
		cout << "\033[1;31m" << "problem with As" << "\033[0m" << endl;
	}
	
	vector<int> obs_seq_lengths(50);
	for (int i=0; i<50; i++){
		obs_seq_lengths[i] = 100;
	}
	
	Data d = generate_synthetic_data(model1, obs_seq_lengths);
	
	if (d.num_observations==50) {
		cout << "\033[1;32m" << "accurate number of observations" << "\033[0m"<< endl;
	} else {
		cout << "\033[1;31m" << "inaccurate number of observations" << "\033[0m" << endl;
	}
	
	if (d.bigT==5000) {
		cout << "\033[1;32m" << "sum of observations collected" << "\033[0m"<< endl;
	} else {
		cout << "\033[1;31m" << "inaccurate sum of observations" << "\033[0m" << endl;
	}
	
	if (d.num_resources==2&&d.num_subparts==4) {
		cout << "\033[1;32m" << "number of subparts/resources successfully extracted" << "\033[0m"<< endl;
	} else {
		cout << "\033[1;31m" << "inaccurate subparts/resources" << "\033[0m" << endl;
	}
	
	Model rand_model = Model(2,4);
	rand_model.generate_random(25);
	if(rand_model.as_get(0,1,0)==0) {
		cout << "\033[1;32m" << "random model successfully generated" << "\033[0m"<< endl;
	} else {
		cout << "\033[1;31m" << "problem generating random model" << "\033[0m" << endl;
	}
	
}