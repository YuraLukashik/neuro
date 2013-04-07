#include <neuron.h>
#include <vector>
#include <cmath>

#define ifInRange(value,left,right) if ((value)>=(left)&&(value)<=(right))

using namespace std;

neuron::neuron(){
    out = 0.;
}

double neuron::getOut(){
    return out;
}

void neuron::addInput(neuron* input,double weight){
    inputs.push_back(make_pair(input,weight));
}

double neuron::simulate(){
    double sum = 0;
    for (unsigned i=0;i<inputs.size();i++)
        sum += inputs[i].first->getOut() * inputs[i].second;
    out = outFunction(sum);
    return out;
}

unsigned int neuron::inputsCount(){
    return inputs.size();
}

double neuron::getWeight(int number){
    ifInRange(number,0,inputsCount()-1) return inputs[number].second;
    return 0;
}

void neuron::setWeight(int number,double value){
    ifInRange(number,0,inputsCount()-1) inputs[number].second = value;
}

neuron* neuron::getInputNeuron(int number){
    ifInRange(number,0,inputsCount()-1) return inputs[number].first;
    return 0;
}

void neuron::setInputNeuron(int number,neuron* newNewron){
    ifInRange(number,0,inputsCount()-1) inputs[number].first = newNewron;
}

double neuron::outFunction(double sum){
    double res;
    res = 1./(1.+exp(sum));
    return res;
}


