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
            cout << "fileName = ";
            cin >> fileName;
            network.loadFromFile(fileName);
        } else
        if (s=="save"){
            cout << "fileName = ";
            cin >> fileName;
            network.saveToFile(fileName);
        } else
        if (s=="simulate"){
            cout << "fileName = ";
            cin >> fileName;
            ex.loadFromFile(fileName);
            network.simulateFromExample(ex);
            printVector(network.getOuts());
        } else
        if (s=="shake"){
            network.shakeWeights();
        }
        if (s=="add"){
            cout << "fileName = ";
            cin >> fileName;
            if (ex.loadFromFile(fileName)){
                tr.addExample(ex);
            }
        }else
        if (s=="addRange"){
            int left,right;
            cout << "from ";
            cin >> left ;
            cout << "to";
            cin >> right;
            cout << "extension=";
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
            cout << "max number of iterations = "; cin >> limit;
            cout << "allowable error = "; cin >> error;
            cout << "learning coeficient = "; cin >> alpha;
            tr.setAllowableError(error);
            tr.setIterationsLimit(limit);
            tr.setAlpha(alpha);
            tr.startLearning(network);
        }else
        if (s=="help"){
            cout << "commands:" <<endl<< "load"<<endl<<"save"<<endl<<"exit"<<endl<<"simulate"<<endl<<"shake"<<endl;
            cout << "add"<<endl<<"addRange"<<endl<<"clear"<<endl<<"train"<<endl<<"help";
        }
    cout << endl << "neuro>";
    }
    return 0;
}
