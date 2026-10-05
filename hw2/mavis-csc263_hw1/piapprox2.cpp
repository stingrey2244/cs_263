#include <iostream>
#include <thread>
#include <random>

using namespace std;

int numpoints = 1000000; // Number of points to generate

int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;

void part1()
{
	random_device rd; // Seed
	mt19937 gen(rd()); // Random # generator
	uniform_real_distribution<float> distrib(0, 1); // Generator output -> # between 0 and 1
	
	for (int i = 0; i < (numpoints/4); i++) {
		float x, y;
		float xsq, ysq;

		x = distrib(gen);
		y = distrib(gen);

		xsq = x*x;
		ysq = y*y;

		// if x^2 + y^2 <= 1, then the point is inside the unit circle
		if ((xsq + ysq) <= 1) {count1++;}
	}
}

void part2()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> distrib(0, 1);

	for (int i = (numpoints/4); i < (numpoints/2); i++) {
		float x, y;
		float xsq, ysq;

		x = distrib(gen);
		y = distrib(gen);

		xsq = x*x;
		ysq = y*y;

		if ((xsq + ysq) <= 1) {count2++;}
	}
}

void part3()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> distrib(0, 1);

	for (int i = (numpoints/2); i < (numpoints/4)*3; i++) {
		float x, y;
		float xsq, ysq;

		x = distrib(gen);
		y = distrib(gen);

		xsq = x*x;
		ysq = y*y;

		if ((xsq + ysq) <= 1) {count3++;}
	}
}

void part4()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> distrib(0, 1);

	for (int i = (numpoints/4)*3; i < numpoints; i++) {
		float x, y;
		float xsq, ysq;

		x = distrib(gen);
		y = distrib(gen);

		xsq = x*x;
		ysq = y*y;

		if ((xsq + ysq) <= 1) {count4++;}
	}
}

int main()
{
	thread t1(part1);
	thread t2(part2);
	thread t3(part3);
	thread t4(part4);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	int pointsinside = count1 + count2 + count3 + count4;
	float piapprox;

	// points inside / number of points = pi / 4
	piapprox = (static_cast<float>(pointsinside) / numpoints) * 4;

	cout << "Pi approximation: " << piapprox << "\n";

	return 0;
}
