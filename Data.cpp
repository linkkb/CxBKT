#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#include "Model.h"
#include "Data.h"

using namespace std;
//using Eigen::MatrixXd;

Data::Data(Model model, vector<int> obs_seq_lengths) {
    /*
    function datastruct = synthetic_data(model, lengths, resources)
    
    num_resources = size(model.learns,3);
    bigT = sum(lengths);
    
    if ~exist('resources','var'), resources = randi(num_resources,1,bigT); end
    if ~isfield(model,'As')
        model.As = [1-model.learns, model.forgets; model.learns, 1-model.forgets];
    end
    
    if ~isfield(model,'pi_0'), model.pi_0 = [1-model.prior; model.prior]; end
    
    resources = int16(resources);
    lengths = int32(lengths(:));
    starts = int32([1;cumsum(lengths(1:end-1))+1]);
    
    [stateseqs, data] = synthetic_data_helper(model,starts,lengths,resources);
    data = data + 1; % 1 and 2 instead of 0 and 1kf
    
    data(:,resources ~= 1) = 0; % no data emitted unless resource == 1
    
    datastruct = struct;
    datastruct.stateseqs = stateseqs;
    datastruct.data = data;
    datastruct.starts = starts;
    datastruct.lengths = lengths;
    datastruct.resources = resources;
    */
    num_resources = model.num_resources;
    num_subparts = model.num_subparts;
    num_observations = obs_seq_lengths.size();
    bigT = 0;
    for (int i=0; i<num_observations; i++) {
        bigT+= obs_seq_lengths[i];
    }
    vector<int> stateseqs(bigT);
    //stateseqs = new int[bigT];
    vector<int> data(num_subparts*bigT);
    //data = new int[4*bigT];
    vector<int> starts(num_observations);
    //starts = new int[num_observations];
    vector<int> lengths(num_observations);
    //lengths = new int[num_observations];
    vector<int> resources(bigT);
    //resources = new int[bigT];
}

void Data::generate_random(int seed) {
    
}