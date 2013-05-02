#include <vector>
#include <neuron.h>
#include <string>

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
    double simulate();
    void setConnectionsCount(int count);
    int getConnectionsCount();
};
