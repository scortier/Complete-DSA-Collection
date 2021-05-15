/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
job i take ti time to get completed and li loss

case 1 - consider same time to finish all the jobs and diff losses.
Since all jobs take same time to finish we should first select jobs which have large Loss (Li). We should select jobs which have the highest losses and finish them as early as possible.
Thus this is a greedy algorithm. Sort the jobs in descending order based on Li only.

case 2 - conider same penalty and diff completion time
Since all jobs have the same penalty we will do those jobs first which will take less amount of time to finish. This will minimize the total delay, and hence also the total loss incurred.
This is also a greedy algorithm. Sort the jobs in ascending order based on Ti. Or we can also sort in descending order of 1/Ti.


From the above cases, we can easily see that we should sort the jobs not on the basis of Li or Ti alone. Instead, we should sort the jobs according to the ratio Li/Ti, in descending order.



*/
#include<bits/stdc++.h>
using namespace std;
#define pair<int,pair<int,int>> job;
//perfect ratio nikalne k liye dimag lao

bool comp(job a, job b)
{
	int a_Li, a_Ti, b_Li, b_Ti;
	a_Li = a.second.first;
	a_Ti = a.second.second;
	b_Li = b.second.first;
	b_Ti = b.second.second;

//to compare c/d with a/b compare cb and ad
	return (a_Li * b_Ti) > (b_Li * a_Ti);
}



int32_t main()
{
	vector<job>list;
	sort(list.begin(), list.end(), comp);

	return 0;
}