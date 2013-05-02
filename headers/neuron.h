#include <vector>

using namespace std;

class neuron{

private:
    //private data
    vector < pair<neuron*,double> > inputs;
    double out;
    pair <int,int> position;

    //private functions
    double outFunction(double sum);

public:
    neuron();
    double getOut();
    void addInput(neuron* input,double weight);
    double simulate();

    unsigned int inputsCount();
    void setOut(double value);
    double getWeight(int number);
    void setWeight(int number,double value);
    neuron* getInputNeuron(int number);
    void setInputNeuron(int number,neuron* newNeuron);
    void setPosition(int x,int y);
    pair<int,int> getPosition();

};
