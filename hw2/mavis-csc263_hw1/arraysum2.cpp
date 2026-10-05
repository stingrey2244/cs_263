#include <iostream>
#include <thread>
#include <random>

using namespace std;

// int myArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

const int array_size = 10'000'000;
int myArray[array_size];

int firstsum = 0;
int secondsum = 0;
int sum = 0;

void addsome()
{
	for (int i = 0; i < (array_size/2); i++) {
		// cout << firstsum << " + " << myArray[i] << "\n";
		firstsum += myArray[i];
	}
}

void addmore()
{
	for (int i = (array_size/2); i < array_size; i++) {
		// cout << secondsum << " + " << myArray[i] << "\n";
		secondsum += myArray[i];
	}
}

int main(){
	unsigned int seed = 1871;
	mt19937 gen(seed);
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < array_size; i++) {
    		myArray[i] = dist(gen);
    	}

	thread t(addsome);
	thread t2(addmore);

	t.join();
	t2.join();

	sum = firstsum + secondsum;
	
	cout << "Array sum: " << sum << "\n";
	return 0;
}
