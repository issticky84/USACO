/*
ID: isstick1
PROB: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool compare(char** a,char** b,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(a[i][j]!=b[i][j])
				return false;
		}
	}
	return true;
}

char** transform1(char** pattern,int size)
{
	char** temp;
	temp = new char*[size];
	for(int i=0;i<size;i++) temp[i] = new char[size];

	int k = size-1;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			temp[j][k] = pattern[i][j];
		}
		k--;
	}	

	return temp;
}

char** transform2(char** pattern,int size)
{
	char** temp;
	temp = new char*[size];
	for(int i=0;i<size;i++) temp[i] = new char[size];

	int k = size - 1;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			temp[k-i][k-j] = pattern[i][j];
		}
	}

	return temp;
}

char** transform3(char** pattern,int size)
{
	char** temp;
	temp = new char*[size];
	for(int i=0;i<size;i++) temp[i] = new char[size];

	int k = size - 1;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			temp[k-j][i] = pattern[i][j];
		}
	}

	return temp;
}

char** transform4(char** pattern,int size)
{
	char** temp;
	temp = new char*[size];
	for(int i=0;i<size;i++) temp[i] = new char[size];

	int k = size - 1;
	if(size%2==0)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				temp[i][k-j] = pattern[i][j];
			}
		}
	}
	else
	{
		k = size - 1;
		int same = (size-1)/2;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(j==same)
				{
					temp[i][j] = pattern[i][j];				
				}
				temp[i][k-j] = pattern[i][j];
			}
		}
	}
	return temp;
}

int main()
{
	ofstream fout ("transform.out");
	ifstream fin ("transform.in");
	int size;
    //char pattern[10][10];
	//char transform[10][10];
	//char temp[10][10];
	char **temp;
	char** pattern;
	char** transform;
	fin >> size;
	pattern = new char*[size];
	for(int i=0;i<size;i++) pattern[i] = new char[size];
	transform = new char*[size];
	for(int i=0;i<size;i++) transform[i] = new char[size];

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			fin >> pattern[i][j];
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			fin >> transform[i][j];

	//transforma 1
	temp = transform1(pattern,size);
	if(compare(temp,transform,size)==true)
	{
		fout << "1" << endl;
		return 0;
	}

	//transform 2
	temp = transform2(pattern,size);
	if(compare(temp,transform,size)==true)
	{
		fout << "2" << endl;
		return 0;
	}

	//transform 3
	temp = transform3(pattern,size);
	if(compare(temp,transform,size)==true)
	{
		fout << "3" << endl;
		return 0;
	}

	//tranform 4
	temp = transform4(pattern,size);
	if(compare(temp,transform,size)==true)
	{
		fout << "4" << endl;
		return 0;
	}

	//transform 5
	temp = transform4(pattern,size);
	temp = transform1(temp,size);
	if(compare(temp,transform,size)==true)
	{
		fout << "5" << endl;
		return 0;
	}

	temp = transform4(pattern,size);
	temp = transform2(temp,size);
	if(compare(temp,transform,size)==true)
	{
		fout << "5" << endl;
		return 0;
	}

	temp = transform4(pattern,size);
	temp = transform3(temp,size);
	if(compare(temp,transform,size)==true)
	{
		fout << "5" << endl;
		return 0;
	}

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			temp[i][j] = pattern[i][j];
		} 
	}
	if(compare(temp,transform,size)==true)
	{
		fout << "6" << endl;
		return 0;
	}

	fout << "7" << endl;

	//for(int i=0;i<size;i++)
	//{
	//	for(int j=0;j<size;j++)
	//	{
	//		cout << temp[i][j] << " ";
	//	} 
	//	cout << endl;
	//}

	//system("pause");
	return 0;
}