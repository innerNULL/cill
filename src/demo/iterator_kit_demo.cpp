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
  std::vector<float> var0 = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
  std::vector<int32_t> var1 = {2, 4, 1, 6};
  std::vector<float> var2 = cill::iterator_kit::vector_elastic_index<float>(var0, var1);
  cill::print_kit::print_simple_num_vector<float>(var2);  
  return 0;
}



int main(int argc, char *argv[]) {
  cill::random_kit::microsecond_random_seed();
  elastic_indexer_demo();
  return 0;
}


