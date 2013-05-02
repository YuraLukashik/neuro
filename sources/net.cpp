#include <vector>
#include <string>
#include <net.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

net::net(){
}

void net::loadFromFile(string fileName){
    ifstream fcin(fileName.c_str());
    int layersCount;
    string s;

    fcin.close();
}
