#include<iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void getInput(int size, string name[], int marks[]);
void getRank(int size, string name[], int marks[]);
void getGrade(int size, int marks[], char grade[]);
void display(int size, string name[], int marks[], char grade[]);

int main()
{
	int size;
	cout << "how many students? ";
	double sum=0;
	cin >> size;
	
	string name[size];
	int marks[size];
	char grade[size];
	getInput(size, name, marks);
	getRank(size, name, marks);
	getGrade(size, marks, grade);
	display(size, name, marks, grade);

	
	return 0;
	
}

void getInput(int size, string name[], int marks[])
{
	
	cout << "enter the student's name and the score\n\n";
	
	for (int i=0; i<size; i++)
		{
			cout << "enter the marks for student #" << i+1 << " : " ;
			cin >> marks[i];
				while (marks[i] < 0)
				{
					cout << "invalid number. enter again: ";
					cin >> marks[i];
				}
			cout << "name: ";
			cin >> name[i];
			cout << endl << endl;
					
		}
}

void getRank(int size, string name[], int marks[])
{	//size array = size ie: 7
	//bubble sort
	int temp;
	string temp2;
	for (int i=0; i<size; ++i)
	{
		for(int j=0; j<(size-1); ++j)
			if(marks[j+1]> marks[j])
			{
				temp=marks[j+1];
				temp2=name[j+1];
				marks[j+1]=marks[j];
				name[j+1]=name[j];
				marks[j]=temp;
				name[j]=temp2;
			}
			
	}
		
	
}


void getGrade(int size, int marks[], char grade[])
{
	for (int i=0; i<size; i++)
	{
		//CANNOT USE SWITCH STATEMENT BECAUSE SWITCH STATEMENT ONLY ACCEPTS 
		//char, byte, short, int, Character, Byte, Short, Integer, String, or an enum type, ELSE a compile-time error occurs.
		/**
		switch(marks)
		{
			case (marks[i]>=80 && marks[i]<=100): 
				cout << 'A' ;
			break;
			case (marks[i]>=70 && marks[i]<=79): 
				cout << 'B' ;
			break;
			case (marks[i]>=60 && marks[i]<=69): 
				cout << 'C' ;
			break;
			case (marks[i]>=50 && marks[i]<=59): 
				cout << 'D';
			break;
			case (marks[i]>=0 && marks[i]<=49): 
				cout << 'F';
			break;
			default:
				return 0;
		
	 	} **/
	 	
	 	
		if (marks[i]>=80 && marks[i]<=100)
		{
			grade[i] = 'A';
		} 
		else if(marks[i]>=70 && marks[i]<=79)
		{
			grade[i] = 'B';
		} 
		else if(marks[i]>=60 && marks[i]<=69)
		{
			grade[i] = 'C';
		} 
		else if(marks[i]>=50 && marks[i]<=59)
		{
			grade[i] = 'D';
		} 
		else 
		{
			grade[i] = 'F';
		} 		
		
	} 
	
 
}

void display(int size, string name[], int marks[], char grade[])
{
	cout << "Rank\t" << "Name\t" << "Score\t" <<"Grade\t" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	for(int i=0;i<size;++i)
	{
		cout << i+1 << "\t" << name[i] << "\t" << marks[i] << "\t"  << grade[i] << endl;
	}
}
