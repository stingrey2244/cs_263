#include <iostream>
#include <thread>

using namespace std;

string myString = "Happy new year!";


void somecaps()
{
	for (int i = 0; i < (myString.length()/2); i++) {
		char c = myString[i];

		if (c >= 'a' && c <= 'z'){
			c -= 32;
			myString[i] = c;
		}
	}
}

void morecaps()
{
	for (int i = myString.length()/2; i < myString.length(); i++) {
		char c = myString[i];

		if (c >= 'a' && c <= 'z'){
			c -= 32;
			myString[i] = c;
		}
	}
}

int main() {
	thread t(somecaps);
	thread t2(morecaps);

	t.join();
	t2.join();

	cout << myString << "\n";
	return 0;
}
