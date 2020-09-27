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
#include "include/cill/str_kit/str_helper.h"
#include "include/cill/str_kit/str_parser.h"


int32_t str_helper_demo() {
  std::cout << "=======str_helper_demo=======" << std::endl;
  std::cout << "-------case0-------" << std::endl;
  std::string case0_var0 = "a-b-c-d-e-f-g";
  std::string case0_var1 = "-";
  std::vector<std::string> case0_var2 = cill::str_spliter(case0_var0, case0_var1);
  cill::print_simple_str_vector(case0_var2);

  std::cout << "-------case1-------" << std::endl;
  std::string case1_var0 = "--,-a-b--c-d-e-f---";
  std::string case1_var1 = "-";
  std::vector<std::string> case1_var2 = cill::str_spliter(case1_var0, case1_var1);
  cill::print_simple_str_vector(case1_var2);

  std::cout << "-------case2-------" << std::endl;
  std::string case2_var0 = "06";
  std::string case2_var1 = "-23.3";
  std::string case2_var2 = "kjh32";
  std::cout << cill::is_num_str(case2_var0) << ", " << cill::is_num_str(case2_var1) 
      << ", " << cill::is_num_str(case2_var2) << std::endl;

  std::cout << "-------case3-------" << std::endl;
  std::string case3_target_str = "/?asdgfkjhak/?sdkjfh";
  cill::substr_replace(case3_target_str, "/?", "");
  std::cout << case3_target_str << std::endl;

  std::cout << "-------case4-------" << std::endl;
  std::string case4_vec_str = "1,2,3,4,5,6";
  std::vector<float> case4_num_vec;
  cill::str2num_vec<float>(case4_num_vec, case4_vec_str, ",");
  cill::print_simple_num_vector<float>(case4_num_vec);

  return 0;
}


int32_t str_parser_demo() {
  std::cout << "=======str_parser_demo=======" << std::endl;
  std::cout << "-------case0-------" << std::endl;
  std::string case0_var0 = "a,1,2,3;b,4,5,6;c,7,8,9;d,0,1,2";
  std::vector< std::pair<std::string, float> > case0_var1;
  case0_var1 = cill::str_str_k_num_v_group_parser<float>(case0_var0, 0, 2, ";", ",");
  cill::print_vector_of_str_k_num_v_pairs<float>(case0_var1);

  std::cout << "-------case1-------" << std::endl;
  std::string case1_var0 = "a#h#2#3s|b#i#5#6|c#j#8#0.9|d#k#1#";
  std::vector< std::pair<std::string, float> > case1_var1;
  case1_var1 = cill::str_str_k_num_v_group_parser<float>(case1_var0, 0, 3, "|", "#");
  cill::print_vector_of_str_k_num_v_pairs<float>(case1_var1);

  std::cout << "-------case2-------" << std::endl;
  std::string case2_source_str = "top_n=3&query_vec=1,2,3,4,5&min_score=0.5";
  std::unordered_map<std::string, std::string> case2_parsing_result;
  cill::str_k_str_v_groups_str_parser(case2_parsing_result, case2_source_str, "&", "=");
  for (auto& item : case2_parsing_result) { std::cout << item.first << ": " << item.second << std::endl; }

  return 0;
}


int main(int argc, char *argv[]) {
  cill::microsecond_random_seed();
  str_helper_demo();
  str_parser_demo();
  return 0;
}


