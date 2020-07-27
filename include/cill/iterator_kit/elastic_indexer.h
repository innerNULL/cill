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

#include "cill/random_kit/random.h"
#include "cill/random_kit/random_num.h"


namespace cill {


/**
 * @brief
 * Elastical indexing/slicing a `std::vector` object which elements are among 
 * basic data types such as int, float, string, etc.
 *
 * @t_param ITEM_TYPE One of basic numical data types, such as int, float, double, etc.
 * @param input Target indexing/slicing vector object.
 * @param target_indexs A `std::vector<int32_t>` object which saving target indexing indexs.
 *
 * @note
 * This function is unsafe, which means, for example, if the index in `target_indexs` is 
 * larger than `input.size()`, then memory leak will happen.
 */
template <typename ITEM_TYPE>
inline auto vector_elastic_index(const std::vector<ITEM_TYPE>& input, 
    const std::vector<int32_t>& target_indexs) -> std::vector<ITEM_TYPE> {
  std::vector<ITEM_TYPE> output;
  for (auto& index : target_indexs) { output.emplace_back(input[index]); }
  return output;
}


/**
 * @brief `vector_elastic_index` supports for `std::vector<std::string>`.
 */
inline auto vector_elastic_index(const std::vector<std::string>& input, 
    const std::vector<int32_t>& target_indexs) -> std::vector<std::string> {
  std::vector<std::string> output;
  for (auto& index : target_indexs) { output.emplace_back(input[index]); }
  return output;
}


/**
 * @brief
 * Similier with `vector_elastic_index`, but this time, the `input` parameter 
 * is a `std::vector< std::pair<std::string, VAL_TYPE> >` object, `VAL_TYPE` 
 * is a basic numical data type.
 */
template <typename VAL_TYPE>
inline auto vector_of_str_k_num_v_pairs_elastic_index(
    const std::vector< std::pair<std::string, VAL_TYPE> >& input, 
    const std::vector<int32_t>& target_indexs) -> std::vector< std::pair<std::string, VAL_TYPE> > {
  std::vector< std::pair<std::string, VAL_TYPE> > output;
  for (auto& index : target_indexs) {
    output.emplace_back(input[index]);
    //std::cout << "dbg " << index << ", " << input[index].first << ", " << input[index].second << std::endl;
  }
  return output;
}


} // namesapce cill

#endif
