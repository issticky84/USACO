/*
ID: issticky1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");

	string comet,group;
	int product1,product2;
	fin >> comet >> group;
	product1=1,product2=1;
	for(int i=0;i<comet.size();++i)
	{
		int character = comet[i] - '@';
		product1 *= character;
	}
	for(int i=0;i<group.size();++i)
	{
		int character = group[i] - '@';
		product2 *= character;
	}
	product1%=47;
	product2%=47;

	if(product1==product2)
		fout << "GO" << endl;
	else 
		fout << "STAY" << endl;
	

	return 0;
}