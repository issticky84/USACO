/*
ID: isstick1
PROB: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Type{COMMON_YEAR,LEAP_YEAR};

int year_type(int input)
{
	//if(input/400==0) return LEAP_YEAR;
	//else if(input/100==0) return COMMON_YEAR;
	//else if(input/4==0) return LEAP_YEAR;
	//else return COMMON_YEAR;
	if( (input%400==0) || ( (input%4==0) && (input%100!=0) ) ) return LEAP_YEAR;
	else return COMMON_YEAR;
}

int main()
{
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	int year[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int count_week[7]={0};//Monday~Sunday 
	int month;
	int day = 1;
	int week = 0;//Monday
	int type;
	int num;
	fin >> num;
	for(int i=1900;i<=1900+num-1;i++)
	{
		int number = 0;
		month = 1;
		//cout << "start " << month << " " << day << " " << week << endl;
		type = year_type(i);
		if(type==COMMON_YEAR) year[1] = 28;
		else if(type==LEAP_YEAR) year[1] = 29;
		//cout << "type " << type << endl;
		while(1)
		{
			if(number==12)
			{
				while(1)
				{
					if(day>year[month-1])
					{	
						day = 1;
						break;
					}
					day++;
					week++;
					week%=7;
				}
				break;
			}

				while(1)
				{
					if(day>year[month-1])
					{
						day = 1;
						month++;
						//week++;
						//week%=7;
					}
					if(day==13)
					{
						number++;
						count_week[week]++;
						//cout << week << " ";
						week++;
						week%=7;
						day++;
						break;
					}
					day++;
					week++;
					week%=7;
				}

		}
		
	}
	fout << count_week[5] << " " << count_week[6] << " ";
	for(int i=0;i<5;i++)
	{
		fout << count_week[i];
		if(i!=4) fout << " ";
	}
	fout << endl;


	//system("pause");
	return 0;
}