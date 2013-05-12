#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

class example{

private:
    //private data
    vector <double> inputs;
    vector <double> outputs;
    //private functions
public:
    example();
    example(string fileName);
    int getInputsCount();
    int getOuputsCount();
    double getInpunt(int number);
    double getOutput(int number);
    bool loadFromFile(string fileName);
};
#endif
