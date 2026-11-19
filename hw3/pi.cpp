#include <iostream>
#include <random>
#include <omp.h>

int main(){

  const int TOTAL_ITERATIONS = 100'000'000;
  const int NUM_THREADS = 4;
  const int ITERATIONS_PER_THREAD = TOTAL_ITERATIONS / NUM_THREADS;
  double inside_count = 0;
  omp_set_num_threads(4);

  #pragma omp parallel
  {
    std::random_device rd; //come back to this                                                                                                  
    std::mt19937 gen(rd() * omp_get_thread_num());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    int local_sum = 0;

    #pragma omp for
    for (int i = 0; i < ITERATIONS_PER_THREAD; i++) {
      double x = dis(gen);
      double y = dis(gen);

      if ((x * x) + (y * y) <= 1.0) {
        local_sum++;
      }
    }

    #pragma omp critical
    {
      inside_count += local_sum;
    }
  }
    
  double pi_estimate = 4.0 * (static_cast<double>(inside_count)/ITERATIONS_PER_THREAD);

  std::cout << "PI estimate is: " << pi_estimate << std::endl;
}
