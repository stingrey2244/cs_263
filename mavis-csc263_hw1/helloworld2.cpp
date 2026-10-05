#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void hello(int num)
{
	cout << "Hello from thread " << num << "!\n";
}

int main()
{
	int numthreads = 10;
	vector<std::thread> threads;

	for (int i = 1; i <= numthreads; i++){
		threads.emplace_back(hello, i);
	}

	for (auto& t : threads){
		t.join();
	}

	return 0;
}
