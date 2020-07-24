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


int32_t str_helper_demo() {
  std::cout << "=======str_helper_demo=======" << std::endl;
  std::cout << "-------case0-------" << std::endl;
  std::string case0_var0 = "a-b-c-d-e-f-g";
  std::string case0_var1 = "-";
  std::vector<std::string> case0_var2 = cill::str_kit::str_spliter(case0_var0, case0_var1);
  cill::print_kit::print_simple_str_vector(case0_var2);

  std::cout << "-------case1-------" << std::endl;
  std::string case1_var0 = "--,-a-b--c-d-e-f---";
  std::string case1_var1 = "-";
  std::vector<std::string> case1_var2 = cill::str_kit::str_spliter(case1_var0, case1_var1);
  cill::print_kit::print_simple_str_vector(case1_var2);
  return 0;
}


int main(int argc, char *argv[]) {
  cill::random_kit::microsecond_random_seed();
  str_helper_demo();
  return 0;
}


