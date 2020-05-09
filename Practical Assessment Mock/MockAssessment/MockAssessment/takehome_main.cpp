#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;


int median(int N, int M, int minV, int maxV) {

	int medV, minDistance;

	srand((unsigned)NULL);
	
	if (N < 1 || M < 1) {
		std::cout << "Invalid Dimensions" << std::endl;
		exit(-1);
	}
	if (maxV <= minV) {
		std::cout << "Invalid Range" << std::endl;
		exit(-1);
	}
	// 1
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[M];
	// 2
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			arr[n][m] = minV + rand() % (maxV - minV + 1);
	// 3
	minDistance = INT_MAX;
	medV = arr[0][0];
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			int distance =((arr[n][m] - minV) * (arr[n][m] - minV)) + ((arr[n][m] - maxV) * (arr[n][m] - maxV));
			int value = arr[n][m];
			if (distance < minDistance) {
				minDistance = distance;
				medV = arr[n][m];
			}
		}
	}

	// 4
	for (int n = 0; n < N; n++)
		delete[] arr[n];
	delete[] arr;
	
	// 5
	return medV;
}

bool isPure(std::string word) {
	string::iterator itr = word.begin();
	while (itr != word.end() && (isupper(*itr) || islower(*itr)))
		itr++;
	return (!word.empty() && itr == word.end());
}

void longest_pure_word(char* fname) {
	// 1
	std::ifstream file(fname);
	if (!file) {
		cout << "No file found" << endl;
		return;
	}
	// 2
	string word, longest_word;
	int len = 0;
	while (file >> word) {		
		if (isPure(word)) {
			if (word.size() > len) {
				len = word.size();
				longest_word = word;
			}
		}
	}
	
	file.close();
	// 4
	std::cout << "The longest pure word is: " << longest_word << std::endl;
	std::cout << "Length = " << len << std::endl;
	// 5
	// The longest pure word found in corpus.txt is telecommunications, with length = 18.


}

void testGraph(){
	Graph graph("graph.txt");
	int source = 0;
	cout << "Select a source." << endl;
	cin >> source;
	graph.get_max_weight_dest(source);
}

int find(string* Table, int TableSize, string key)
{
	// calculate the hash index of the matching key in the Table 
	unsigned int index = 0;
	for (int i = 0; i < key.size(); i++)
		index = index * 37 + key[i];
	index %= TableSize;
	// use linear probing to revise the index if there is a collision, to locate 
	// the matching key or the first empty slot for its storage
	while (!Table[index].empty() && Table[index] != key) {
		index = (index + 1) % TableSize;
	}

	// return the index found 
	return index;
}

int main(){
	cout << median(1000, 1000, 0, 25) << endl;
	longest_pure_word((char*)"corpus.txt");
	cout << endl;
	testGraph();

	string* Table = new string[17];
	cout << "hash index = " << find(Table, 17, "belfast") << endl;
	delete[] Table;

}

