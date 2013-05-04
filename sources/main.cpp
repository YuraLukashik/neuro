#include <iostream>
#include <net.h>

using namespace std;

int main()
{
    net q;
    q.loadFromFile("data/simple.nw");
    example ex("data/example1.ex");
    cout << q.simulateFromExample(ex);
    return 0;
}
