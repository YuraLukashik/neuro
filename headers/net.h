#ifndef NET_H_INCLUDED
#define NET_H_INCLUDED

#include <vector>
#include <neuron.h>
#include <string>
#include <example.h>

using namespace std;

class net{

private:
    //private data
    vector <vector <neuron> > neurons;
    int connectionsCount;
    //private functions
public:
    net();
    void loadFromFile(string fileName);
    void saveToFile(string fileName);
    int getLayersCount();
    void simulate();
    void setConnectionsCount(int count);
    int getConnectionsCount();
    void simulateFromExample(example& ex);
    double train(example& ex,double alpha);
    void prepareNeurons();
    void shakeWeights();
    vector<double> getOuts();
};
#endif
