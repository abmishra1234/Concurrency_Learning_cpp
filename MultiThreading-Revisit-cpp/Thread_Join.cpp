#include<iostream>
#include<thread>
using namespace std;

// shared variable for managing common update for output
int sum = 0;
int mul = 1;


void thSumFunction(const int& num01, const int& num02)
{
	// so any thing you will update here 
	// it would be shared back to main thread by two ways
	// 1. shared varible
	// 2. Direct messaging the Main thread
	// So this approach is just shared the approach for shared variable...
	sum = (num01 + num02);
	mul = (num01 * num02);
}

#if 0
int main()
{
	cout << "Welcome to the MT with CPP class in dec 2021\n";
	cout << "First Include Thread header\n";
	int a = 5, b = 6;
	thread th(thSumFunction, a, b);
	/*
		Join method is ataching your worker thread with main thread and halting main thread from here until
		worker thread finish and comeback to main thread...

		This is not useful in real thime thread scenario...
		It is just for join understandiuing...
	*/

	th.join();

	cout << "So output value : sum = " << sum << "\n";
	cout << "So output value : mul = " << mul << "\n";

	cout << "exiting from main\n";
}
#endif // 0
