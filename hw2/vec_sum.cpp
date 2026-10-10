#include <iostream>
#include <vector>
#include <random>

constexpr size_t SIZE = 15;

void add(int* a, int* b, int* c) {
    for (size_t i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }
}

void fill_random(std::vector<int>& v, std::mt19937& gen,
    std::uniform_int_distribution<int>& dist) {
    for (auto& val : v) {
        val = dist(gen);
    }
}

int main() {
  std::vector<int> a(SIZE), b(SIZE), c(SIZE);
  
  std::mt19937 gen(1871);
  std::uniform_int_distribution<int> dist(-100, 100);

  fill_random(a, gen, dist);
  fill_random(b, gen, dist);

  add(a.data(), b.data(), c.data());
      
  std::cout << "a: ";
  for (int n : a) {
    std::cout << n << " ";
  }     
  std::cout << std::endl;
  std::cout << "b: ";
  for (int n : b) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  std::cout << "(a + b): ";
  for (int n : c) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  return 0;
}
