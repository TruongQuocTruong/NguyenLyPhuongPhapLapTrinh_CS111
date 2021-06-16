// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    fstream f;
    f.open("AIRCREW.IN.txt", ios::in);
	/// Lấy số lượng phi công từ file
	string strN;  
	int N;
	getline(f, strN);   
	N = stoi(strN);

	/// Lấy từng phần tử
	string line;
	vector<int> main;
	vector<int> extra;
	string strTemp;
	int intTemp;
	while (!f.eof())       
	{
		getline(f, line); 
		int index = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ') {
				strTemp = line.substr(index, i - index);
				intTemp = stoi(strTemp);
				main.push_back(intTemp);
				index = i + 1;
				////////////////
				strTemp = line.substr(index, line.length() - index);
				intTemp = stoi(strTemp);
				extra.push_back(intTemp);
			}
		}

	}
	f.close();
	////////// Xử lý
	int SumSalary = 0;

	while ( main.size() > 0 ) {
		int i = 0;
		SumSalary += extra[i];
		int index = i+1;
		int Temp1 = main[index] - extra[index];
		for (int j = index + 1; j < main.size(); j++) {
			if (main[j] - extra[j] < Temp1) {
				index = j;
			} 
		}
		SumSalary += main[index];
		main.erase(main.begin() + index);
		main.erase(main.begin() + i);
		extra.erase(extra.begin() + index);
		extra.erase(extra.begin() + i);
	}
	cout << SumSalary;
	fstream f1;
	f1.open("AIRCREW.OUT.txt", ios::out); 

	string data = to_string(SumSalary); 
	f1 << data;                           

	f1.close();
	return(0);
}


