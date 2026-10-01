#include <iostream>
#include <vector>
#include <random>
#include <thread>

constexpr size_t SIZE = 10'000'000;

void fill_random(std::vector<float>& v, std::mt19937& gen,
    std::uniform_real_distribution<float>& dist) {
    for (auto& val : v) {
        val = dist(gen);
    }
}

void sum(const std::vector<float>& v, std::vector<float>& s, int num_threads, int thread_num){
  int curr_sum = 0;
  int range = v.size()/num_threads;
  for (int i = 0; i < range; i++){
    curr_sum += v[range*thread_num + i];
  }
  s[thread_num] = curr_sum;
}

int main(){
  std::mt19937 gen(31415);
  std::uniform_real_distribution<float> dist(-100.0f, 100.0f);
  std::vector<float> a(SIZE);
  int cores = std::thread::hardware_concurrency();
  std::vector<float> s(cores);
  
  fill_random(a, gen, dist);

  std::vector<std::thread> threads;

  for (int i = 0; i < cores; i++){
    threads.push_back(std::thread(sum, std::cref(a), std::ref(s), cores, i));
  }

  for (int i = 0; i < threads.size(); i++){
    threads[i].join();
  }
    
  int final_sum = 0;
  for(int i = 0; i < s.size(); i++){
    final_sum += s[i];
  }

  std::cout << "Size of vector is: " << SIZE << std::endl;
  std::cout << "Num of threads is: " << cores << std::endl;
  std::cout << "Final sum is: " << final_sum << std::endl;
    
}
