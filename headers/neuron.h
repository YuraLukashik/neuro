#include <vector>

using namespace std;

class neuron{
private:
    //private data
    vector < pair<neuron*,double> > inputs;
    double out;
    pair <int,int> position;

    //data for training
    //vector<double> deltas;
    double sigma;
    vector <pair<double,double> > childSigmas;
    bool calculated;

    //private functions
    double outFunction(double sum);

public:
    neuron();
    double getOut();
    void setOut(double value);
    void addInput(neuron* input,double weight);
    double simulate();

    unsigned int inputsCount();
    double getWeight(int number);
    void setWeight(int number,double value);
    neuron* getInputNeuron(int number);
    void setInputNeuron(int number,neuron* newNeuron);
    void setPosition(int x,int y);
    pair<int,int> getPosition();
    void clearTrainingData();
    void correctWeights(bool recalc,double alpha);
    void setSigma(double val);
    void addChildSigma(pair<double,double> sigma);
    void shakeWeights(bool recursively);
    void setCalculated(bool calculated);
};
