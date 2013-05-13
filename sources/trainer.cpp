#include <trainer.h>
#include <algorithm>
#include <iostream>

using namespace std;

trainer::trainer(){
    this->limit = 1000;
    this->error = 0.1;
    this->alpha = 0.5;
}

void trainer::addExample(example& ex){
    container.push_back(ex);
}

void trainer::setIterationsLimit(int limit){
    this->limit = limit;
}

void trainer::setAllowableError(double error){
    this->error = error;
}

void trainer::clearTrainData(){
    this->container.resize(0);
}

void trainer::setAlpha(double alpha){
    this->alpha = alpha;
}

string trainer::startLearning(net& network){
    vector <int> seq;
    for (int i=0;i<container.size();++i)
        seq.push_back(i);
    int iterations = 0;
    double currError = error+1;
    while (iterations<limit&&currError>error){
        currError = 0;
        random_shuffle(seq.begin(),seq.end());
        for (int i=0;i<container.size();++i){
            currError += network.train(container[seq[i]],this->alpha);
        }
        iterations++;
        if (iterations%100==0) cout << iterations << endl;
    }
    return " ";
}
