#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct{
	int value;
	int index;
} package;

int _2238A(){
	int result = 0;
	int input = 0;

	//INPUT
	int n = 0, sortCost = 0;
	cin >> n >> sortCost;

	vector<vector<package>> arr(2, vector<package>(n) );

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < n; j++){
			cin >> input;
			arr[i][j] = {input, j};
		}

	/*
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			cout << "{" << arr[i][j].value << "," << arr[i][j].index << "} ";
		}
		cout << endl;
	}
	*/

	for(int i = 0; i < 2; i++)
	sort(arr[i].begin(), arr[i].end(), [](const package& a, const package& b){
		return a.value < b.value;
	});

	for(int i = 0; i < n; i++){
		if(arr[0][i].value >= arr[1][i].value){
			if(arr[0][i].index != arr[1][i].index && sortCost >= 0){
				result += sortCost;
				sortCost *= -1;
			}
		}
		else return -1;

		result += arr[0][i].value - arr[1][i].value;
		//cout << arr[0][i].value << " - " << arr[1][i].value << " = " << result << endl;
	}

	return result;
}

int main(){
	int nLoop = 0;
	cin >> nLoop;

	for(int i = 0; i < nLoop; i++){
		cout << _2238A() << endl;
	}

	return 0;
}
