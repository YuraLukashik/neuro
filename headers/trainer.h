#include <net.h>
#include <example.h>
#include <vector>
#include <string>

using namespace std;

class trainer{

private:
    //private data
    vector <example> container;
    int limit;
    double error;
    //private functions
public:
    trainer();
    void addExample(example ex);
    void setIterationsLimit(int limit);
    void setAllowableError(double error);
    void clearTrainData();
    string startLearning(net& network);
};
