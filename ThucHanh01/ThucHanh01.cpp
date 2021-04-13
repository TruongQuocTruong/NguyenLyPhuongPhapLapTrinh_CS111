// ThucHanh01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string Str1 = "AKQJT98765432";
string Str2 = "NRBC";

bool compare(string adam, string eva) {
    int adam1 = Str1.find(adam[0]);
    int eva1 = Str1.find(eva[0]);

    int adam2 = Str2.find(adam[1]);
    int eva2 = Str2.find(eva[1]);

    if (adam1 == eva1) {
        if (eva2 > adam2) {
            return true;
        }
        else return false;
    }
    else if (adam1 < eva1) {
        return true;
    }
    else return false;
}
int CountK(vector<string> adam, vector<string> eva) {
    int Dem = 0;
    int i = adam.size();
    int Index = eva.size();
    while (i > 0) {
        if (compare(adam[i], eva[Index]) == true) {
            Dem = Dem + 1;
            i = i - 1;
            Index = Index - 1;
        }
        else {
            i = i - 1;
        }
    }
    return Dem;
}
int main()
{
    vector<int> KQ;
    fstream f;
    f.open("C://Users/TRUONG/Desktop/Input.txt", ios::in);
    
    string nS; int nI;
    getline(f, nS);
    nI = stoi(nS);

    string tS; int tI;
    for(int i = 0; i < nI; i++){
        getline(f, tS);
        tI = stoi(tS);

        vector<string> InpAdam;
        for (int j = 0; j < tI; j++) {
            string Inp;
            getline(f, Inp);
            InpAdam.push_back(Inp);
        }
        vector<string> InpEva;
        for (int j = 0; j < tI; j++) {
            string Inp;
            getline(f, Inp);
            InpEva.push_back(Inp);
        }
        int Dem = CountK(InpAdam, InpEva);
        KQ.push_back(Dem);
    }
    f.close();
    for (int i = 0; i < KQ.size(); i++) {
        cout << KQ[i];
    }
}
