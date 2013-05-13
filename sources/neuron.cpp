#include <neuron.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

#define ifInRange(value,left,right) if ((value)>=(left)&&(value)<=(right))

using namespace std;

neuron::neuron(){
    out = 0.;
    calculated = false;
}

double neuron::getOut(){
    return out;
}

void neuron::addInput(neuron* input,double weight){
    inputs.push_back(make_pair(input,weight));
    input->addOutput(this,weight);
}

void neuron::addOutput(neuron* output,double weight){
        outputs.push_back(make_pair(output,weight));
}

double neuron::simulate(){
    if (inputs.size()==0||calculated==true) return out;
    calculated = true;
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
    res = 1./(1.+exp(-sum));
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
}

void neuron::setSigma(double val){
    sigma = val;
}


void neuron::correctWeights(bool recalc,double alpha){
    if (recalc){
        double sum = 0;
        for (int i=0;i<outputs.size();++i)
            sum += outputs[i].first->getSigma()*outputs[i].second;
        this->sigma = this->out*(1-this->out)*sum;
    }
    for (int i=0;i<inputs.size();i++){
        inputs[i].second = inputs[i].second + alpha*sigma*inputs[i].first->getOut();
    }
}

void neuron::shakeWeights(bool recursively){
    if (calculated) return;
    calculated = true;
    for (int i=0;i<inputs.size();++i){
        if (recursively) inputs[i].first->shakeWeights(true);
        inputs[i].second = rand()%100-50;
    }
}

void neuron::setCalculated(bool calculated){
    this->calculated = calculated;
}

double neuron::getSigma(){
    return sigma;
}
