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
#include "include/cill/random_kit/random_iterator.h"


int32_t random_demo() {
  int32_t tmp0 = cill::random_kit::uniform_random<int32_t>(5, 10);
  std::cout << tmp0 << "random_demo" << std::endl;

  std::vector<int32_t> random_uniform_vector_demo_0 = cill::random_kit::random_uniform_vector<int32_t>(5, 10, 20, true);
  cill::print_kit::print_simple_num_vector<int32_t>(random_uniform_vector_demo_0);
  return 0;
}


int32_t random_iterator_demo() {
  std::cout << "random_iterator_demo" << std::endl;
  std::cout << "-------case0--------" << std::endl;
  std::vector<float> case0_var0 = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7};
  std::vector<float> case0_var1 = cill::random_kit::vector_random_choose<float>(case0_var0, 5);
  std::vector<float> case0_var2 = cill::random_kit::vector_random_choose<float>(case0_var0, 8);
  std::vector<float> case0_var3 = cill::random_kit::vector_random_choose<float>(case0_var0, 0);
  std::vector<float> case0_var4 = cill::random_kit::vector_random_choose<float>(case0_var0, 10);
  cill::print_kit::print_simple_num_vector<float>(case0_var1);
  cill::print_kit::print_simple_num_vector<float>(case0_var2);
  cill::print_kit::print_simple_num_vector<float>(case0_var3);
  cill::print_kit::print_simple_num_vector<float>(case0_var4);

  std::cout << "-------case1--------" << std::endl;
  std::vector< std::pair<std::string, float> > case1_var0 = {{"a", 0.1}, {"b", 0.2}, {"c", 0.3}, {"d", 0.4}, {"e", 0.5}, {"f", 0.6}, {"g", 0.7}};
  std::vector< std::pair<std::string, float> > case1_var1 = cill::random_kit::vector_of_str_k_num_v_pairs_random_choose<float>(case1_var0, 5);
  std::vector< std::pair<std::string, float> > case1_var2 = cill::random_kit::vector_of_str_k_num_v_pairs_random_choose<float>(case1_var0, 1);
  cill::print_kit::print_vector_of_str_k_num_v_pairs<float>(case1_var0);
  cill::print_kit::print_vector_of_str_k_num_v_pairs<float>(case1_var1);
  cill::print_kit::print_vector_of_str_k_num_v_pairs<float>(case1_var2);

  return 0;
}



int main(int argc, char *argv[]) {
  cill::random_kit::microsecond_random_seed();

  for (int32_t i = 0; i < 20; ++i) {
    auto output = cill::random_kit::random_bin();
    std::cout << output << std::endl;
  }
  random_demo();
  random_iterator_demo();
  return 0;
}


