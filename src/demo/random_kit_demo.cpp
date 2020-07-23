// 2020-07-23

#include <algorithm>  
#include <random>    
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <chrono>
#include <cassert>
#include <locale>
#include <codecvt>
#include <any>
#include <utility>
#include <set>
#include <math.h> 

#include "include/cill/print_kit/printer.h"
#include "include/cill/random_kit/random.h"
#include "include/cill/random_kit/random_num.h"



int32_t random_demo() {
  int32_t tmp0 = cill::random_kit::uniform_random<int32_t>(5, 10);
  std::cout << tmp0 << "random_demo" << std::endl;

  std::vector<int32_t> random_uniform_vector_demo_0 = cill::random_kit::random_uniform_vector<int32_t>(5, 10, 20, true);
  cill::print_kit::print_simple_num_vector(random_uniform_vector_demo_0);
  return 0;
}



int main(int argc, char *argv[]) {
  cill::random_kit::microsecond_random_seed();

  for (int32_t i = 0; i < 20; ++i) {
    auto output = cill::random_kit::random_bin();
    std::cout << output << std::endl;
  }
  random_demo();
  return 0;
}


