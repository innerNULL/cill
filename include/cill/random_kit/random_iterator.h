// 2020-07-23

#ifndef CILL_RANDOM_KIT_RANDOM_ITERATOR_H_
#define CILL_RANDOM_KIT_RANDOM_ITERATOR_H_

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


namespace cill {
namespace random_kit {


template <typename ITEM_TYPE>
inline auto vector_random_choose(const std::vector<ITEM_TYPE>& input, int32_t target_num) -> std::vector<ITEM_TYPE> {
  std::vector<ITEM_TYPE> output;
  if (input.size() < target_num || target_num <= 0 || input.size() == 1) {
    output = input;
  } else {
    std::vector<int32_t> random_choosen_idx = random_uniform_vector<int32_t>(target_num, 0, input.size() - 1, true);
    output = iterator_kit::vector_elastic_index<ITEM_TYPE>(input, random_choosen_idx);
  }
  return output;
}


template <typename VAL_TYPE>
inline auto vector_of_str_k_num_v_pairs_random_choose(const std::vector< std::pair<std::string, VAL_TYPE> >& input, 
    int32_t target_num) -> std::vector< std::pair<std::string, VAL_TYPE> > {
  std::vector< std::pair<std::string, VAL_TYPE> > output;
  if (input.size() < target_num || target_num <= 0 || input.size() == 1) {
    output = input;
  } else {
    std::vector<int32_t> random_choosen_idx = random_uniform_vector<int32_t>(target_num, 0, input.size() - 1, true);
    output = iterator_kit::vector_of_str_k_num_v_pairs_elastic_index<VAL_TYPE>(input, random_choosen_idx); 
  }
  return output;
}


} // namespace random_kit
} // namesapce cill

#endif
