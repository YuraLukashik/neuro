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
    void loadFromFile(string fileName);
};
