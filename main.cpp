#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

vector<string> characteristics[100];
int nanimals;
string temp;
int kchar;
string charname;


int compare(int x, int y){
	vector<string> v1 = characteristics[x];
	vector<string> v2 = characteristics[y];
	
	int counter = 0;

	for(int a = 0; a < v1.size(); a++){
		for(int b = 0; b < v2.size(); b++){
			if (v1[a] == v2[b]){
			counter++;
			}
		}
	}
return counter++;
}

int main(){

	ifstream fin;
	ofstream fout;
	
	fin.open("guess.in");
	fout.open("guess.out");
	
	fin >> nanimals;
	for (int q = 0; q < nanimals; q++){
		fin >> temp >> kchar;
		for (int k = 0; k < kchar; k++){
			fin >> charname;
			characteristics[q].push_back(charname);
		}
	}
	
	int maxcount = 0;
	int tempcount = 0;
	
	for(int c = 0; c < nanimals; c++){
		for(int d = c + 1; d < nanimals; d++){
			tempcount = compare(c,d);
			if(tempcount > maxcount){
				maxcount = tempcount;
			}
		}
	}
	
	fout << maxcount + 1; 

}