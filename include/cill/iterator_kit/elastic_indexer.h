// 2020-07-23

#ifndef CILL_ITERATOR_KIT_ELASTIC_INDEXER_H_
#define CILL_ITERATOR_KIT_ELASTIC_INDEXER_H_

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

#include <include/cill/random_kit/random.h>
#include <include/cill/random_kit/random_num.h>


namespace cill {
namespace iterator_kit {


template <typename ITEM_TYPE>
inline auto vector_elastic_index(const std::vector<ITEM_TYPE>& input, 
    const std::vector<int32_t>& target_indexs) -> std::vector<ITEM_TYPE> {
  std::vector<ITEM_TYPE> output;
  for (auto& index : target_indexs) {
    output.emplace_back(input[index]);
  }
  return output;
}


} // namespace iterator_kit
} // namesapce cill

#endif
