/*
https://aonecode.com/getArticle/211
https://www.geeksforgeeks.org/design-a-hit-counter/
https://leetcode.com/discuss/interview-question/178662/Design-a-Hit-Counter/



It includes a couple of topics like basic data structures design, various optimization, concurrency and distributed counter.

It should support the following two operations: hit and getHits.

hit(timestamp) – Shows a hit at the given timestamp.



getHits(timestamp) – Returns the number of hits received in the past 5 minutes (300 seconds) (from currentTimestamp).

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (i.e. the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.
*/

/*Brute Force Approach
M-1
We can use vector to store all the hits
*/
vector<int>v;

//Record a hit
void hit(int curr_timestamp)
v.push_back(curr_timestamp);

int getHits(int curr_timestamp)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > curr_timestamp - 300) // 300sec i.e 5mins
			break;
	}
	return v.size() - 1;
}

/*
M-2
Space optimized solution
We can use a queue to store the hits and delete the entries in queue which are of no use. It will save our space.
We are deleting the extra elements from queue.

*/

queue<int>q;

void hit(int curr_timestamp)
q.push(curr_timestamp);

//return the no of hits in past 5min
int getHits(itn curr_timestamp)
{
	while (!q.empty() and curr_timestamp - q.front() >= 300)
	{
		q.pop();
	}
	return q.size();
}


/*
M-3
3. Most optimized solution :

What if the data comes in unordered and several hits carry the same timestamp.

Since the queue approach wouldn’t work without ordered data, this time go with arrays to store the hit count in each unit of time.

If we are tracking hits in the past 5 mins in seconds granularity which is 300 seconds, create 2 arrays of size 300.
int[] hits = new int[300];

TimeStamp[] times = new TimeStamp[300]; // timestamp of the last counted hit
Given an incoming, mod its timestamp by 300 to see where it locates in the hits array.

int idx = timestamp % 300; => hits[idx] keeps the hit count took place in this second

But before we increase the hit count at idx by 1, the timestamp really belongs to the second that hits[idx] is tracking.
timestamp[i] stores the timestamp of the last counted hit.
If timestamp[i] > timestamp, this hit should be discarded since it did not happened in the past 5 minute.
If timestamp[i] == timestamp, then hits[i] increase by 1.
If timestamp[i] currentTime – 300.

*/

class HitCounter {
public:
	/** Initialize your data structure here. */
	HitCounter() {
		times.resize(300);
		hits.resize(300);
	}

	/** Record a hit.
	@timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		int idx = timestamp % 300;
		if (times[idx] != timestamp) {
			times[idx] = timestamp;
			hits[idx] = 1;
		} else {
			++hits[idx];
		}
	}

	/** Return the number of hits in the past 5 minutes.
	@timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		int res = 0;
		for (int i = 0; i < 300; ++i) {
			if (timestamp - times[i] < 300) {
				res += hits[i];
			}
		}
		return res;
	}

private:
	vector<int> times, hits;
};