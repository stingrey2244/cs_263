#include <iostream>
#include <thread>

using namespace std;

int myArray[10] = {10, 2, 13, 45, 5, 6, 17, 8, 99, -1};

int firstmin = myArray[0]; 
int secondmin = myArray[5];
int finalmin = myArray[0]; 

void checksome()
{
	for (int i = 0; i < 5; i++) {
		if (myArray[i] < firstmin) { firstmin = myArray[i];}
	}
}

void checkmore()
{
	for (int i = 5; i < 10; i++) {
		if (myArray[i] < secondmin) { secondmin = myArray[i];}
	}
}

int main(){
	thread t(checksome);
	thread t2(checkmore);

	t.join();
	t2.join();

	if (firstmin < secondmin){finalmin = firstmin;}
	else finalmin = secondmin;

	cout << "Array min: " << finalmin << "\n";
	return 0;
}
