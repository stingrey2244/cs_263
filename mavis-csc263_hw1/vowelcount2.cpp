#include <iostream>
#include <thread>

using namespace std;

string myString = "The quick brown fox jumps over the lazy dog.";

int firstcount = 0;
int secondcount = 0;
int total = 0;

void countsome()
{
	for(int i = 0; i < (myString.length()/2); i++) {
		char clower = tolower(myString[i]);
		if (clower == 'a' || clower == 'e' || clower == 'i' || clower == 'o' || clower == 'u') {
			firstcount += 1;
		}
	}
}

void countmore()
{
	for(int i = (myString.length()/2); i < myString.length(); i++) {
		char clower = tolower(myString[i]);
		if (clower == 'a' || clower == 'e' || clower == 'i' || clower == 'o' || clower == 'u') {
			secondcount += 1;
		}
	}
}

int main()
{
	thread t(countsome);
	thread t2(countmore);

	t.join();
	t2.join();

	total = firstcount + secondcount;

	cout << "Vowel count: " << total << "\n";
	return 0;
}
