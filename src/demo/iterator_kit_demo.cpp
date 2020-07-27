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
#include "include/cill/iterator_kit/elastic_querier.h"


int32_t elastic_indexer_demo() {
  std::cout << "=======elastic_indexer_demo=======" << std::endl;
  std::cout << "-------case0-------" << std::endl;
  std::vector<float> case0_var0 = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
  std::vector<int32_t> case0_var1 = {2, 4, 1, 6};
  std::vector<float> case0_var2 = cill::vector_elastic_index<float>(case0_var0, case0_var1);
  cill::print_simple_num_vector<float>(case0_var2);

  std::cout << "-------case1-------" << std::endl;
  std::vector< std::pair<std::string, float> > case2_var0 = {{"a", 0.1}, {"b", 0.2}, {"c", 0.3}, {"d", 0.4}};
  std::vector<int32_t> case1_var1 = {3, 0, 2};
  std::vector< std::pair<std::string, float> > case2_var2 = cill::vector_of_str_k_num_v_pairs_elastic_index<float>(case2_var0, case1_var1);
  cill::print_vector_of_str_k_num_v_pairs<float>(case2_var0);
  cill::print_vector_of_str_k_num_v_pairs<float>(case2_var2);
  return 0;
}


int32_t elastic_querier_demo() {
  std::cout << "=======elastic_querier_demo=======" << std::endl;
  std::cout << "-------case0-------" << std::endl;
  std::vector< std::pair<std::string, float> > case0_var0 = {{"a", 0.1}, {"b", 0.2}, {"c", 0.3}, {"d", 0.4}};
  std::vector< std::pair<std::string, float> > case0_var1;
  std::vector< std::pair<std::string, float> > case0_var2;
  case0_var1 = cill::str_k_num_v_pairs_vec_range_querier<float>(case0_var0, 0.15, 0.35, "inner");
  case0_var2 = cill::str_k_num_v_pairs_vec_range_querier<float>(case0_var0, 0.15, 0.35, "outer");
  cill::print_vector_of_str_k_num_v_pairs<float>(case0_var0);
  cill::print_vector_of_str_k_num_v_pairs<float>(case0_var1);
  cill::print_vector_of_str_k_num_v_pairs<float>(case0_var2);

  std::cout << "-------case1-------" << std::endl;
  std::vector< std::pair<std::string, float> > case1_var0 = {
      {"a", 0.9}, {"b", 1.2}, {"c", -4.3}, {"d", 0.04}, {"e", 0.9}, {"f", 0.04}};
  std::vector< std::pair<std::string, float> > case1_var1;
  std::vector< std::pair<std::string, float> > case1_var2;
  std::vector< std::pair<std::string, float> > case1_var3;
  case1_var1 = cill::str_k_num_v_pairs_vec_top_querier(case1_var0, 3, "descend");
  case1_var2 = cill::str_k_num_v_pairs_vec_top_querier(case1_var0, 3, "ascend");
  case1_var3 = cill::str_k_num_v_pairs_vec_top_querier(case1_var0, 3, "fake");
  cill::print_vector_of_str_k_num_v_pairs<float>(case1_var1);
  cill::print_vector_of_str_k_num_v_pairs<float>(case1_var2);
  cill::print_vector_of_str_k_num_v_pairs<float>(case1_var3);

  return 0;
}


int main(int argc, char *argv[]) {
  cill::microsecond_random_seed();
  elastic_indexer_demo();
  elastic_querier_demo();
  return 0;
}


