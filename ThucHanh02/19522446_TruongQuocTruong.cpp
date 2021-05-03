// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

//hàm xử lý Input

vector<int> ProInput(string a) {
	vector<int> KQ;
	string temp1 = "";
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != ' ') {
			temp1 += a[i];
		}
		else {
			int temp2;
			temp2 = stoi(temp1);
			KQ.push_back(temp2);
			temp1 = "";
		}
		if (i == a.length() - 1) {
			int temp2;
			temp2 = stoi(temp1);
			KQ.push_back(temp2);
		}
	}
	return KQ;
}

int FindMin(vector<int> a) {
	int min = a[0];
	int Index = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < min) {
			min = a[i];
			Index = i;
		}
	}
	return Index+1;
}

int FindLess(vector<int> a, vector<int> b, int check) {
	int Index = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < check and find(b.begin(), b.end(), i+1) == b.end()) {
			Index = i;
		}
	}
	return Index + 1;
}
int CountEle(vector<int> a, int check) {
	int count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == check) {
			count ++;
		}
	}
	return count;
}

int main()
{
	string a;
	getline(cin, a);
	vector<int> vector1;
	vector1 = ProInput(a);
	int N= vector1[0];
	int M = vector1[1];
	int K = vector1[2];

	// Xử lý dòng Input 2
	string b;
	getline(cin, b);
	vector<char> vector2;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] != ' ') {
			vector2.push_back(b[i]);
		}
	}
	// Xử lý dòng Input 3
	string c;
	getline(cin, c);
	vector<int> vector3;
	vector3 = ProInput(c);

	//Xử lý
	srand (time(NULL));
	vector<int> KQ;
	for (int i = 0; i < vector2.size(); i++) {
		if (vector2[i] == 'E') {
			int Index = FindMin(vector3);
			if (CountEle(KQ, Index) < K) {
				KQ.push_back(Index);
			}
			else if (CountEle(KQ, Index) == K) {
				vector3[Index-1] = K;
				int Index = FindMin(vector3);
				KQ.push_back(Index);
			}
		}
		if (vector2[i] == 'W') {
			int Index = FindLess(vector3, KQ, K);
			KQ.push_back(Index);
		}
	}
	for (int i = 0; i < KQ.size(); i++) {
		cout << KQ[i] << " ";
	}
}

