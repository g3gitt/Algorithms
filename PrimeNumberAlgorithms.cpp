#include <iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

int  EuclidsAlgorithm(int m, int n) {
	if (n == 0)
		return m;
	EuclidsAlgorithm(n, m % n);
}

int  consecutiveDecreasing(int m, int n) {
	int t = min(m, n);
	if (t == 0)return max(m, n);
	while (t > 0) {
		if (m % t == 0 && n % t == 0) {
			break;
		}
		t--;
	}
	return t;

}

vector<int> SieveOfEratosthenes(int k) {
	vector<int>arr(k+1);
	//int num = 0;
	for (int i = 0; i <= k; i++) {
		arr[i] = i;
	}
	
	for (int i = 2; i < sqrt(k); i++) {
		if (arr[i] != 0) {
			int j = i * i;
			while (j < arr.size()) {
				arr[j] = 0;
				j = j + i;
			}
		}
	}
	vector<int>ans;
	for (int i = 2; i < arr.size(); i++) {
		if (arr[i] != 0) {
			ans.push_back(arr[i]);
		}
	}
	return ans;
}

int LockedDoors(int n) {
	vector<int>res(n, 0);
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j < res.size()) {
			res[j] = 1 ^ res[j];
			j = j + i;
		}
	}
	int open = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == 1) {
			open++;
		}
	}
	return open;
}

int main()
{
	time_t start, end;
	

	ios_base::sync_with_stdio(false);

	

	int n;
	cout << "Enter n"<<endl;
	cin >> n;
	int m;
	cout << "Enter m"<<endl;
	cin >> m;

	time(&start);

	//Euclids Algorithm to find the Highest Common Factor or Greatest Common Divisor of a number
	int Euclids= EuclidsAlgorithm(m, n);
	cout << "The Euclids Method: "<< Euclids << endl;
	
	//Same problem but different method
	int consecutive = consecutiveDecreasing(m, n);
	cout <<"The Consecutive Decreasing Method : " << consecutive << endl;

	//Sieve Of Eratosthenes - To list out all prime numbers in a given range
	int k;
	cout << "Enter range of elements to generate Prime Numbers : " << endl;
	cin >> k;
	vector<int> SieveOfEratostheness = SieveOfEratosthenes(k);
	for(int i=0;i<SieveOfEratostheness.size();i++)
	cout << SieveOfEratostheness[i]<<" ";
	cout << endl;

	// Execution of Locked Doors problem where there are 'n' doors in a hallway all closed.
	// you make 'n' passes by each door and the 'i'-th door toggles.
	int doors;
	cout << "Enter number of doors in the hallway: ";
	cin >> doors;
	int open = LockedDoors(doors);
	cout << "Open Doors : " << open << endl;
	cout << "Closed doors : " << doors - open << endl;
	time(&end);


	//Time Complexity
	double time_taken = double(end - start);
	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(5);
	cout << " sec " << endl;

	return 0;
}					