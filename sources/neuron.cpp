#include <neuron.h>
#include <vector>
#include <cmath>
#include <iostream>

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
    if (inputs.size()==0) return out;
    double sum = 0;
    for (unsigned i=0;i<inputs.size();i++)
        sum += inputs[i].first->simulate() * inputs[i].second;
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
    res = 1./(1.+exp(-sum))-0.5;
    return res;
}

void neuron::setOut(double value){
    this->out = value;
}

void neuron::setPosition(int x,int y){
    this->position.first = x;
    this->position.second = y;
}

pair<int,int> neuron::getPosition(){
    return this->position;
}

void neuron::clearTrainingData(){
    sigma = 0;
    delta = 0;
    childSigmas.resize(0);
}

void neuron::correctWeights(){
    for (int i=0;i<inputs.size();i++){
        inputs[i].second = inputs[i].second + 0.5*1*sigma*inputs[i].first->getOut();
    }
}
