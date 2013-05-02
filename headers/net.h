#include <vector>
#include <neuron.h>
#include <string>

using namespace std;

class net{

private:
    //private data
    vector <vector <neuron> > neurons;
    //private functions
public:
    net();
    void loadFromFile(string fileName);
};
