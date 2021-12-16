#include<iostream>
#include<thread>
#include<mutex>
#include<list>


using namespace std;

namespace MyLockGuard
{
	std::mutex mtx;
	std::list<int> mylist;

	void AddToList(int data)
	{
		std::lock_guard<std::mutex> lkg(mtx);
		mylist.push_front(data);
		cout << "Adding to list is successful from th_id = " << std::this_thread::get_id() << "\n";
	}
}

using namespace MyLockGuard;

#if 0
int main()
{
	std::thread th1(AddToList, 4);
	std::thread th2(AddToList, 5);

	th1.join();
	th2.join();

	auto it = mylist.begin();
	for (; it != mylist.end(); ++it)
	{
		cout << (*it) << " ";
	}
	
	cout << "\nExiting from main... th_id = " << std::this_thread::get_id() << "\n";
}
#endif // 0