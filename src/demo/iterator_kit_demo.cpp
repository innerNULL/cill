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
#include "include/cill/iterator_kit/elastic_indexer.h"


int32_t elastic_indexer_demo() {
  std::vector<float> case0_var0 = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
  std::vector<int32_t> case0_var1 = {2, 4, 1, 6};
  std::vector<float> case0_var2 = cill::iterator_kit::vector_elastic_index<float>(case0_var0, case0_var1);
  cill::print_kit::print_simple_num_vector<float>(case0_var2);

  std::vector< std::pair<std::string, float> > case2_var0 = {{"a", 0.1}, {"b", 0.2}, {"c", 0.3}, {"d", 0.4}};
  std::vector<int32_t> case1_var1 = {3, 0, 2};
  std::vector< std::pair<std::string, float> > case2_var2 = cill::iterator_kit::vector_of_str_k_num_v_pairs_elastic_index<float>(case2_var0, case1_var1);
  cill::print_kit::print_vector_of_str_k_num_v_pairs<float>(case2_var0);
  cill::print_kit::print_vector_of_str_k_num_v_pairs<float>(case2_var2);
  return 0;
}



int main(int argc, char *argv[]) {
  cill::random_kit::microsecond_random_seed();
  elastic_indexer_demo();
  return 0;
}


