/*
FUNCTION findMaxBitonic (Input array, low, high){
    While(low<=high){
        1.	Set mid to (low+high)/2;
        2.	Comparisons
        IF(array [mid]>array[mid-1] &&array[mid]>array[mid+1])
            Return array[mid]; //as this is the maximum
        //in the increasing region of the bitonic array
        IF(array[mid]>array[mid-1] &&array[mid]<array[mid+1])
            low=mid+1; //move lower bound up
        //in the decreasing region of the bitonic array
        ELSE IF(array[mid]<array[mid-1] &&array[mid+1]<array[mid])
            high=mid-1; //move upper bound down
    END WHILE
    IF control comes out of the loop
        //for trivial cases like array size 1 or 2
        return array[array size-1];
END FUNCTION
*/

#include <bits/stdc++.h>
using namespace std;

//printing the array
void print(vector<int> a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}


//function to find the max
int findMaxBitonic(vector<int> a, int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;

		if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) //the maximum
			return a[mid];
		if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1]) //in increasing zone
			low = mid + 1;
		if (a[mid] < a[mid - 1] && a[mid + 1] < a[mid]) //in decreasing zone
			high = mid - 1;
	}
	return a[a.size() - 1];
}

int main() {
	int n, item;

	cout << "enter array size: ";
	scanf("%d", &n);

	vector<int> a;

	cout << "input bitonic array of size: " << n << endl;
	for (int j = 0; j < n; j++) {
		scanf("%d", &item);
		a.push_back(item);
	}
	cout << "your bitonic array is:\n";
	print(a, n);
	cout << "maximum in this bitonic array is:" << findMaxBitonic(a, 0, n - 1) << endl;

	return 0;
}
