#include <iostream>
#include <thread>

using namespace std;

int myArray[10] = {10, 2, 13, 45, 5, 6, 17, 8, 99, -1};

int firstmax = myArray[0]; 
int secondmax = myArray[5];
int finalmax = myArray[0]; 

void checksome()
{
	for (int i = 0; i < 5; i++) {
		if (myArray[i] > firstmax) { firstmax = myArray[i];}
	}
}

void checkmore()
{
	for (int i = 5; i < 10; i++) {
		if (myArray[i] > secondmax) { secondmax = myArray[i];}
	}
}

int main(){
	thread t(checksome);
	thread t2(checkmore);

	t.join();
	t2.join();

	if (firstmax > secondmax){finalmax = firstmax;}
	else finalmax = secondmax;

	cout << "Array max: " << finalmax << "\n";
	return 0;
}
