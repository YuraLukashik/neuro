#include <example.h>
#include <fstream>
#include <iostream>
#define ifInRange(value,left,right) if ((value)>=(left)&&(value)<=(right))

using namespace std;

example::example(){
}

example::example(string& fileName){
    this->loadFromFile(fileName);
}

int example::getInputsCount(){
    return inputs.size();
}

int example::getOuputsCount(){
    return outputs.size();
}

double example::getInpunt(int number){
    ifInRange(number,0,inputs.size()-1) return inputs[number];
    return 0.;
}

double example::getOutput(int number){
    ifInRange(number,0,outputs.size()-1) return outputs[number];
    return 0.;
}

bool example::loadFromFile(string& fileName){
    try{
    ifstream fcin(fileName.c_str());
    if (!fcin) return false;
    int inpCount,outCount;
    fcin >> inpCount >> outCount;
    inputs.resize(inpCount);
    outputs.resize(outCount);
    for (int i=0;i<inpCount;++i)
        fcin >> inputs[i];
    for (int i=0;i<outCount;++i)
        fcin >> outputs[i];
    fcin.close();
    }
    catch(...){
        cout << "File is incorrect";
    }
}
