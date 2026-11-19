#include <iostream>
#include <vector>
#include <random>
#include <omp.h>
#include <climits>

constexpr size_t SIZE = 20;

void fill_random(std::vector<int>& v, std::mt19937& gen,
    std::uniform_int_distribution<int>& dist) {

  for (auto& val : v) {
	val = dist(gen);
    }
}

int min(const std::vector<int>& v){
  int global_min = INT_MAX;
#pragma omp parallel
  {
    int thread_num = omp_get_thread_num();
    int num_threads = omp_get_num_threads();
    int chunk_size = v.size()/num_threads;
    int start = thread_num * chunk_size;
    int end = (thread_num == num_threads-1) ? v.size() : start + chunk_size;

    int local_min = INT_MAX;
    for (int i = start; i < end; i++){
      int curr = v[i];
      if (curr < local_min){
	local_min = curr;
      }
    }
#pragma omp critical
    {
      if (local_min < global_min) {
	global_min = local_min;
      }
    }
  }
    return global_min;
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

  omp_set_num_threads(4);
  
  int min_val = min(a);
  int max_val = max(a);

  std::cout << "min value is: " << min_val << std::endl;
  std::cout << "max value is: " << max_val << std::endl;
}
