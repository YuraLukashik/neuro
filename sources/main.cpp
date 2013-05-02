#include <iostream>
#include <net.h>

using namespace std;

int main()
{
    net q;
    q.loadFromFile("data/simple.nw");
    q.saveToFile("data/simpleCopy.nw");
    return 0;
}
