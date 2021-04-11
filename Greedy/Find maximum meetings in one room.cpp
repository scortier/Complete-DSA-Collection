/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

struct meeting {
	int start;
	int end;
	int pos;
};

bool comp(struct meeting m1, meeting m2)
{
	return (m1.end < m2.end);
}

void mxMeeting(int s[], int f[], int n)
{
	struct meeting meet[n];

	for (int i = 0; i < n; i++)
	{
		//starting time of meeting i.
		meet[i].start = s[i];

		//finishing time of meeting i
		meet[i].end = f[i];

		//original posn/index of meeting
		meet[i].pos = i + 1;

	}
//selected if meeting according to their finish time.
	sort(meet, meet + n, comp);

//vector for starting selected meeting
	vector<int>m;

	// Initially select first meeting.
	m.push_back(meet[0].pos);

	// time_limit to check whether new
	// meeting can be conducted or not.
	int time_limit = meet[0].end;

	// Check for all meeting whether it
	// can be selected or not.
	for (int i = 1; i < n; i++) {
		if (meet[i].start >= time_limit)
		{
			// Push selected meeting to vector
			m.push_back(meet[i].pos);

			// Update time limit.
			time_limit = meet[i].end;
		}
	}

	// Print final selected meetings.
	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << " ";
	}
}

int main()
{
	// Starting time
	int s[] = { 1, 3, 0, 5, 8, 5 };

	// Finish time
	int f[] = { 2, 4, 6, 7, 9, 9 };

	// Number of meetings.
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	maxMeeting(s, f, n);

	return 0;
}