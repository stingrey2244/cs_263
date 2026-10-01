#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <mutex>

int inside_count = 0;
std::mutex mtx;

void circle(int iterations, double min_x, double max_x, double min_y, double max_y) {
  std::random_device rd; //come back to this
  std::mt19937 gen(rd());

  std::uniform_real_distribution<double> dis_x(min_x, max_x);
  std::uniform_real_distribution<double> dis_y(min_y, max_y);
  
  int sum = 0;
  
  for (int i = 0; i < iterations; i++) {
    double x = dis_x(gen);
    double y = dis_y(gen);
    
    if ((x * x) + (y * y) <= 1.0) {
      sum++;
    }
  }

  mtx.lock();
  inside_count += sum;
  mtx.unlock();
}

int main(){
  std::vector<std::thread> threads;
  const int TOTAL_ITERATIONS = 10'000'000;
  const int NUM_THREADS = 4;
  const int ITERATIONS_PER_THREAD = TOTAL_ITERATIONS / NUM_THREADS;

  std::thread t1(circle, ITERATIONS_PER_THREAD, 0.0, 0.5, 0.0, 0.5);
  std::thread t2(circle, ITERATIONS_PER_THREAD, 0.5, 1.0, 0.0, 0.5);
  std::thread t3(circle, ITERATIONS_PER_THREAD, 0.0, 0.5, 0.5, 1.0);
  std::thread t4(circle, ITERATIONS_PER_THREAD, 0.5, 1.0, 0.5, 1.0);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  
  double pi_estimate = 4.0 * (static_cast<double>(inside_count)/TOTAL_ITERATIONS);

  std::cout << "PI estimate is: " << pi_estimate << std::endl;
}
