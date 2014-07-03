/*
ID: isstick1
PROB: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ofstream fout ("beads.out");
	ifstream fin ("beads.in");
	int num;
	int length[350]={0};
	string necklace;
	string buff1,buff2;
	fin >> num >> necklace;
	string necklace_temp = necklace + necklace + necklace;

	int t = 0;
	for(int i=num;i<num+num;i++)
	{
		int k = i;
		buff1.clear();
		if(necklace_temp[k] == 'w')
		{   
			buff1.push_back(necklace_temp[k]);
			length[t]++;
			while(1)
			{
				k++;
				if(k>=num*3) break;

				if(necklace_temp[k] == 'w')
				{  
					buff1.push_back(necklace_temp[k]);
					length[t]++;				
				}
				else
					break;
			}
		}

		buff1.push_back(necklace_temp[k]);
		length[t]++;
		int start = k;

		while(1)
		{
			k++; 
			if(k>=num*3) break;
			if(length[t]>=num) break;
			
			if(necklace_temp[k] == necklace_temp[start])
			{
				buff1.push_back(necklace_temp[k]);
				length[t]++;
			}
			else if(necklace_temp[k] == 'w')
			{
				buff1.push_back(necklace_temp[k]);
				length[t]++;
			}
			else
				break;
		}

		t++;

		//for(int i=0;i<buff1.size();i++)
		//	cout << buff1[i] << " ";
		//cout << endl;		
	}

	t = 0;
	for(int i=num-1;i<num-1+num;i++)
	{
		if(length[t]>=num) break;

		int k = i;
		buff2.clear();
		if(necklace_temp[k] == 'w')
		{
			buff2.push_back(necklace_temp[k]);
			length[t]++;
			while(1)
			{
				k--;
				if(k<0) break;
				if(necklace_temp[k] == 'w')
				{
					buff2.push_back(necklace_temp[k]);
					length[t]++;				
				}
				else
					break;
			}
		}

		buff2.push_back(necklace_temp[k]);
		length[t]++;
		int start = k;

		while(1)
		{
			k--;
			if(k<0) break;
			if(length[t]>=num) break;

			if(necklace_temp[k] == necklace_temp[start])
			{
				buff2.push_back(necklace_temp[k]);
				length[t]++;
			}
			else if(necklace_temp[k] == 'w')
			{
				buff2.push_back(necklace_temp[k]);
				length[t]++;
			}
			else
				break;
		}

		t++;

		//for(int i=0;i<buff2.size();i++)
		//	cout << buff2[i] << " ";
		//cout << endl;		
	}

	int max = -100000;
	for(int i=0;i<num;i++)
	{
		if(length[i]>=max)
			max = length[i];
	}

	if(max>=num) max = num;

	fout << max << endl;

	//system("pause");
	return 0;
}