/*
ID: isstick1
PROB: milk2
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class interval
{
public:
	int low,up;
};

vector<interval> intervals;

bool cmp(interval i1,interval i2)
{
	if(i1.low < i2.low) 
		return true;
	else 
		return false;
}

int main()
{
	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");
	
	int num,lower_bound,upper_bound;
	fin >> num;
	for(int i=0;i<num;i++)
	{
		fin >> lower_bound >> upper_bound;
		interval inv;
		inv.low = lower_bound;
		inv.up = upper_bound;
		intervals.push_back(inv);
	}

	sort(intervals.begin(),intervals.end(),cmp);

	int current_low,current_up;
	current_low = intervals[0].low;
	current_up = intervals[0].up;

	int longest_milked = current_up-current_low;
	int longest_not_milked = 0;

	for(int i=1;i<intervals.size();++i)
	{
		if(intervals[i].low>current_up)
		{
			if(intervals[i].low-current_up>longest_not_milked)
				longest_not_milked = intervals[i].low-current_up;

			current_low = intervals[i].low;
			current_up = intervals[i].up;
			if(current_up-current_low>longest_milked)
				longest_milked = current_up-current_low;
		}
		else
		{
			if(intervals[i].low<current_low)
				current_low = intervals[i].low;
			if(intervals[i].up>current_up)
				current_up = intervals[i].up;
			if(current_up-current_low>longest_milked)
				longest_milked = current_up-current_low;
		}
	}

	fout << longest_milked << " " << longest_not_milked << endl;

	//system("pause");
	return 0;
}