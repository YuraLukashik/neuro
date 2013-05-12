#include <trainer.h>

using namespace std;

trainer::trainer(){
}

void trainer::addExample(example ex){
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

string trainer::startLearning(net& network){
    int iterations = 0;
    double currError = error+1;
    while (iterations<limit&&currError>error){
        currError = 0;
        for (int i=0;i<container.size();++i){
            currError += network.train(container[i]);
        }
        iterations++;
    }
    return " ";
}
