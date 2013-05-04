#include <vector>
#include <string>
#include <net.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

net::net()
{
}

void net::loadFromFile(string fileName)
{
    ifstream fcin(fileName.c_str());
    int layersCount;
    string sbuf;
    int ibuf,l1,v1,l2,v2,connectionsCountBuf;
    double w;

    fcin >> layersCount;
    neurons.resize(layersCount);
    for(int i=0; i<layersCount; ++i)
    {
        fcin >> ibuf;
        neurons[i].resize(ibuf);
        for (int j=0;j<ibuf;++j)
            neurons[i][j].setPosition(i,j);
    }

    fcin >> connectionsCountBuf;
    this->connectionsCount = connectionsCountBuf;
    for (int i=0;i<connectionsCountBuf;++i)
    {
        fcin >> l1 >> v1 >> sbuf >> l2 >> v2 >> sbuf >> w;
        neurons[l2-1][v2-1].addInput(&neurons[l1-1][v1-1],w);
    }
    fcin.close();
}

void net::saveToFile(string fileName){
    ofstream fcout(fileName.c_str());

    fcout << neurons.size() << endl;
    for (int i=0;i<neurons.size();++i)
        fcout << neurons[i].size() << " ";
    fcout << endl;
    fcout << connectionsCount << endl;

    queue<neuron*> qu;
    set<neuron*> metki;
    for (int i=0;i<neurons[neurons.size()-1].size();++i)
        qu.push(&neurons[neurons.size()-1][i]);
    while (!qu.empty()){
        neuron* curr = qu.front(); qu.pop();
        metki.insert(curr);
        for (int i=0;i<curr->inputsCount();i++){
            neuron* conTo = curr->getInputNeuron(i);
            fcout << conTo->getPosition().first+1 <<" "<<conTo->getPosition().second+1 << " -> ";
            fcout << curr->getPosition().first+1 << " "<<curr->getPosition().second+1 << " : " << curr->getWeight(i) << endl;
            if (metki.count(conTo)<=0) qu.push(conTo);
        }
    }

    fcout.close();
}

double net::simulate(){
    for (int i=0;i<neurons[neurons.size()-1].size();++i){
        neurons[neurons.size()-1][i].simulate();
    }
    return neurons[neurons.size()-1][0].getOut();
}

double net::simulateFromExample(example ex){
    if (neurons.size()==0) return 0.;
    if (neurons[0].size()!=ex.getInputsCount()) return 0.;
    for (int i=0;i<neurons[0].size();++i){
        neurons[0][i].setOut(ex.getInpunt(i));
    }
    return this->simulate();
}

double net::train(example ex){
    this->simulateFromExample(ex);
}

void net::setConnectionsCount(int count){
    this->connectionsCount = count;
}

int net::getConnectionsCount(){
    return this->connectionsCount;
}

int net::getLayersCount()
{
    return neurons.size();
}

