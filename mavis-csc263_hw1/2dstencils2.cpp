#include <iostream>
#include <thread>

using namespace std;

float oldArray[5][5] = {
	{1, 2, 3, 4, 5},
	{6, 7, 8, 9, 10},
	{11, 12, 13, 14, 15},
	{16, 17, 18, 19, 20},
	{21, 22, 23, 24, 25}
};

int numx = 5;
int numy = 5;
float cx = 0.1;
float cy = 0.1;

float newArray[5][5];

void first()
{
	for (int x = 1; x < numx - 1; x++) {
		float center = oldArray[x][1];
		float left = oldArray[x-1][1];
		float right = oldArray[x+1][1];
		float upper = oldArray[x][0];
		float lower = oldArray[x][2];

		float newpoint = center +
				 cx*(right + left - 2*center) +
				 cy*(upper + lower -2*center);
		newArray[x][1] = newpoint;
	}
}

void second()
{
	for (int x = 1; x < numx - 1; x++) {
		float center = oldArray[x][2];
		float left = oldArray[x-1][2];
		float right = oldArray[x+1][2];
		float upper = oldArray[x][1];
		float lower = oldArray[x][3];

		float newpoint = center +
		                 cx*(right + left - 2*center) +
		                 cy*(upper + lower -2*center);
		newArray[x][2] = newpoint;
	}
}

void third()
{
	for (int x = 1; x < numx - 1; x++) {
		float center = oldArray[x][3];
		float left = oldArray[x-1][3];
		float right = oldArray[x+1][3];
		float upper = oldArray[x][2];
		float lower = oldArray[x][4];

		float newpoint = center +
		                 cx*(right + left - 2*center) +
		                 cy*(upper + lower -2*center);
		newArray[x][3] = newpoint;
	}
}

int main() {
	for (int count = 0; count < 100; count++)
	{
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				newArray[i][j] = oldArray[i][j];
			}
		}
		
		thread t1(first);
		thread t2(second);
		thread t3(third);

		t1.join();
		t2.join();
		t3.join();

		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				oldArray[i][j] = newArray[i][j];
			}
		}
	}

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			cout << oldArray[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
