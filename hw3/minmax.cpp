#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <future>
#include <climits>

constexpr size_t SIZE = 20;

void fill_random(std::vector<int>& v, std::mt19937& gen,
    std::uniform_int_distribution<int>& dist) {

  for (auto& val : v) {
	val = dist(gen);
    }
}

int min(const std::vector<int>& v){
  int curr_min = INT_MAX;
  for (int i = 0; i < v.size(); i++){
    int curr = v[i];
    if (curr < curr_min){
      curr_min = curr;
    }
  }
  return curr_min;
}

int max(const std::vector<int>& v){
  int curr_max = INT_MIN;
  for (int i = 0; i < v.size(); i++){
    int curr = v[i];
    if (curr > curr_max){
      curr_max = curr;
    }
  }
  return curr_max;
}

int main(){
  std::mt19937 gen(314159);
  std::uniform_int_distribution<int> dist(-100, 100);
  std::vector<int> a(SIZE);
  fill_random(a, gen, dist); // fill vector a of size SIZE with random ints -100 to 100

  std::cout << "vector: ";
  for (int n : a) {
      std::cout << n << " ";
  }
  std::cout << "\n";

  std::future<int> future_min = std::async (min, a);
  std::future<int> future_max = std::async (max, a);


  int min = future_min.get();
  int max = future_max.get();

  std::cout << "min value is: " << min << std::endl;
  std::cout << "max value is: " << max << std::endl;
}
