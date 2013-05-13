#include <iostream>
#include <example.h>
#include <net.h>
#include <algorithm>
#include <cmath>
#include <trainer.h>
#include <sstream>

using namespace std;

void printVector(vector<double> v){
    for (int i=0;i<v.size();++i){
        cout << "out" << (i+1) <<" = " << v[i] << endl;
    }
}

int main(int argc,char** args)
{
    string s,fileName;
    example ex;
    net network;
    trainer tr;
    cout << endl << "neuro>";
    while (cin>>s){
        if (s=="exit") break; else
        if (s=="load"){
            cin >> fileName;
            network.loadFromFile(fileName);
        } else
        if (s=="save"){
            cin >> fileName;
            network.saveToFile(fileName);
        } else
        if (s=="simulate"){
            cin >> fileName;
            ex.loadFromFile(fileName);
            network.simulateFromExample(ex);
            printVector(network.getOuts());
        } else
        if (s=="shake"){
            network.shakeWeights();
        }
        if (s=="add"){
            cin >> fileName;
            if (ex.loadFromFile(fileName)){
                tr.addExample(ex);
            }
        }else
        if (s=="addRange"){
            int left,right;
            cin >> left >> right;
            cin >> fileName;
            int iter = 0;
            while (left<=right){
                stringstream sstm;
                sstm << left << fileName;
                cout << sstm.str();
                s = sstm.str();
                if (ex.loadFromFile(s)){
                    tr.addExample(ex);
                    cout  << " was loaded"<<endl;
                }
                else
                    cout  << " wasn't loaded"<<endl;
                left++;
                iter++;
                if (iter>10000) break;
            }
        }else
        if (s=="clear"){
            tr.clearTrainData();
        }else
        if (s=="train"){
            int limit;
            double error;
            double alpha;
            cin >> limit >> error >> alpha;
            tr.setAllowableError(error);
            tr.setIterationsLimit(limit);
            tr.setAlpha(alpha);
            tr.startLearning(network);
        }
    cout << endl << "neuro>";
    }
    return 0;
}
