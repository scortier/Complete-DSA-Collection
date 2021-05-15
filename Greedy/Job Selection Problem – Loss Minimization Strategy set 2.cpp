/*
As the day increases the losses too increase. So the trick would be to ensure that the goods are not kept idle after production. Further, since we are required to produce at least one job per day, we should perform low volume jobs, and then perform the high volume jobs. This strategy works due to two factors.

High Volume goods are not kept idle after production.
As the volume decreases the loss per day too decreases, so for low volume goods the losses become negligible after a few days.
So in order to obtain the optimum solution we produce the larger volume goods later on. For the first day select the good with the least volume and produce it. Remove the produced good from the list of goods. For the next day repeat the same. Keep repeating while there are goods left to be produced.

*/
#include <bits/stdc++.h>
using namespace std;

void optimum_sequence_jobs(vector<int>& V, double P)
{
	int j = 1, N = V.size() - 1;
	double result = 0;

	// Create a min-heap (priority queue)
	priority_queue<int, vector<int>, greater<int> > Queue;

	// Add all goods to the Queue
	for (int i = 1; i <= N; i++)
		Queue.push(V[i]);

	// Pop Goods from Queue as long as it is not empty
	while (!Queue.empty()) {

		// Print the good
		cout << Queue.top() << " ";

		// Add the Queue to the vector
		// so that total voulme can be calculated
		V[j++] = Queue.top();
		Queue.pop();
	}

	// Calclulating volume of goods left when all
	// are produced. Move from right to left of
	// sequence multiplying each volume by
	// increasing powers of 1 - P starting from 0
	for (int i = N; i >= 1; i--)
		result += pow((1 - P), N - i) * V[i];

	// Print result
	cout << endl << result << endl;
}

// Driver code
int main()
{
	// For implementation simplicity days are numbered
	// from 1 to N. Hence 1 based indexing is used
	vector<int> V{ -1, 3, 5, 4, 1, 2, 7, 6, 8, 9, 10 };

	// 10% loss per day
	double P = 0.10;

	optimum_sequence_jobs(V, P);

	return 0;
}
