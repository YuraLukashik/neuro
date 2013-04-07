#include <iostream>
#include <neuron.h>

using namespace std;

int main()
{
    neuron n1;
    neuron n2;
    n2.addInput(&n1,0);

    cout << "Hello world!" << endl;
    return 0;
}
