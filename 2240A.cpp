#include <iostream>

using namespace std;

int addOne(int target);
int sumBit(int k, int numOLB, int OLB);

int main(){
	int nLoop = 0;
	cin >> nLoop;

	int n = 0, k = 0;
	for(int i = 0; i < nLoop; i++){
		cin >> n >> k;
		if(k >= n){
			cout << n << endl;
			continue;
		}


		int noLastBit = 1;
		int onlyLastBit = 1;


		int check = 0;
		while(1){
			check = k*noLastBit;
			if(check >= n){
				noLastBit = noLastBit >> 1;
				break;
			}
			else	noLastBit = addOne(noLastBit);
		}
		//cout << noLastBit << endl;

		check = k*noLastBit;
		
		onlyLastBit = noLastBit << 1;
		onlyLastBit = onlyLastBit | 1;
		onlyLastBit -= noLastBit;

		int numOLB = 0;
		int temp = check;
		while(1){
			temp = check + numOLB*onlyLastBit;

			if(temp > n){
				numOLB--;
				break;
			}
			numOLB++;
		}

		//cout << "NLB :" << noLastBit << "\tnumOLB :" << numOLB << endl;

		cout << sumBit(k, numOLB, noLastBit) << endl;
	}

	return 0;
}

int addOne(int target){
	target = (target << 1);
	target = target | 1;

	return target;
}

int sumBit(int k, int numOLB, int NLB){
	int base = 0, result = 0;
	while(NLB > 0){
		base += NLB%2;
		NLB /= 2;
	}

	result = base * k + numOLB;

	return result;
}
