#include<iostream>
#include<thread>
using namespace std;

// shared variable for managing common update for output
int sum = 0;


void thSumFunction(const int& num01, const int& num02)
{
	sum = (num01+num02);
}


int main()
{
	cout << "Welcome to the MT with CPP class in dec 2021\n";
	cout << "First Include Thread header\n";
	int a = 5, b = 6;
	thread th(thSumFunction, a, b);
	th.join();
	cout << "So output value : sum = " << sum << "\n";
	cout << "exiting from main\n";
}