/*
ID: issticky1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

string name[10];	

int find_index(string input)
{
	for(int i=0;i<10;i++)
	{
		if(input==name[i])
			return i;
	}
}

int main()
{
	ofstream fout ("gift1.out");
	ifstream fin("gift1.in");
	int num,money,give_num;
	//string name[10];
	int result[10] = {0};
	string temp;
	fin >> num;
	for(int i=0;i<num;i++)
	{
		fin >> name[i];
	}

	for(int i=0;i<num;i++)
	{
		fin >> temp;
		fin >> money >> give_num;
		int giver_id = find_index(temp);
		if(money!=0) result[giver_id] += (money%give_num);
		if(money!=0) result[giver_id] -= money;
		for(int j=0;j<give_num;j++)
		{
			fin >> temp;
			int id = find_index(temp);
			if(money!=0) result[id] += (money/give_num);	
		}
	}

	for(int i=0;i<num;i++)
	{
		fout << name[i] << " " << result[i] << endl;
	}

	//system("pause");
	return 0;
}