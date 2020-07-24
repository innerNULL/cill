// 2020-07-23

#ifndef CILL_ITERATOR_KIT_ELASTIC_QUERIER_H_
#define CILL_ITERATOR_KIT_ELASTIC_QUERIER_H_

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

#include "cill/random_kit/random.h"
#include "cill/random_kit/random_num.h"


namespace cill {
namespace iterator_kit {


template <typename VAL_TYPE>
inline auto str_k_num_v_pairs_vec_range_querier(const std::vector< std::pair<std::string, VAL_TYPE> >& input, 
    const float left_bound, const float right_bound, const std::string mode) -> std::vector< std::pair<std::string, VAL_TYPE> > {
  std::vector< std::pair<std::string, VAL_TYPE> > output;
  for (auto& pair : input) {
    if (mode == "inner") {
      if (pair.second < right_bound && pair.second > left_bound) { output.emplace_back(pair); }
    } else if (mode == "outer") {
      if (pair.second > right_bound || pair.second < left_bound) { output.emplace_back(pair); }
    }
  }
  return output;
}


} // namespace iterator_kit
} // namesapce cill

#endif
