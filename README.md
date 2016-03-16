# CxBKT

This is C++ port of the xBKT software from the Computational Approach to Human Learning labratory at UC Berkeley. Its purpose is to take in observations of student correct or incorrect responses after viewing resources in a given order, and determine the Bayesian probability that the resource caused them to learn the correct answer.

The CAHL xBKT is written in Matlab, a proprietary software requiring expensive licenses. However, most of the heavy computation is done in C++ helper functions. In order to make the program more accessible, this project has been made to make a Matlab-free xBKT in C++.

You can find the original xBKT here - https://github.com/CAHLR/xBKT

Current progress:
☑ Model class
☑ Model initialization
☑ Model field getters/setters + utilities
☑ Generate random models (generate/random_model_uni.m)
☑ Data class
☒ Data initialization
☐ Data field getters/setters + utilities
☐ Extract / Translate C++ code from mex in (generate/synthetic_data_helper.cpp)
☐ Generate synthetic data from models/observation lengths (generate/synthetic_data.m)
☐ Import data from external files
☐ Call EM_Step code through E_step
☐ Extract / Translate C++ code from mex in (fit/E_step.cpp)
☐ Complete M_step
☐ Successful completion of all hand specified tests (test/hand_specified_model[1-3].m)
☐ Successful tests creating fit models from imported data + outputting to file
☐ Implement prediction options
☐ Implement x-fold verification
☐ Command-line interface for the program
