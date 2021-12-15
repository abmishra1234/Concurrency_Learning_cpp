#include<iostream>
#include<thread>
using namespace std;

namespace thread_detach
{
	// shared variable for managing common update for output
	int sum = 0;
	int mul = 1;
	bool finish = false;
};

using namespace thread_detach;

void thFunction(const int& num01, const int& num02)
{
	// so any thing you will update here 
	// it would be shared back to main thread by two ways
	// 1. shared varible
	// 2. Direct messaging the Main thread
	// So this approach is just shared the approach for shared variable...
	sum = (num01 + num02);
	mul = (num01 * num02);
	finish = true;
}

#if 0

int main()
{
	int a = 5;
	int b = 6;

	thread th(thFunction, a, b);
	th.detach();

	// so now no guarantee of execution of worker thread with detach call...
	// so than the question is how to make sure that you will get notified properly inside the main
	// aboiut the worker thread completion...

	while (finish == false)
	{
		cout << "Putting main thread on sleep\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	cout << "The Sum = " << sum << "\n";
	cout << "The Mul = " << mul << "\n";


	cout << "Finished the Execution...\n";
	return 0;
}

#endif // 0
