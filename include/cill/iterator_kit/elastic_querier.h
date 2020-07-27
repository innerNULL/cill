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


/**
 * @brief
 * The input is a `std::vector` object, each element is a `std::pair` object, which value is 
 * numerical type. This function can get the elements whose value is belong or not belong 
 * to certaion range.
 *
 * @t_praram VAL_TYPE One of basic numerical data types, such as int, float, double, etc.
 * @param input The target object which we hope to query from.
 * @param left_bound Left bound to filter data.
 * @param right_bound Right bouund to filter data.
 * @param mode Data filter mode, if equals "inner", we will keep the `std::pair` which value 
 *     is between `left_bound` and `right_bound`; if equals "outer", we will keep the `std::pair` 
 *     which value is larger than `right_bound` or less than `left_bound`.
 */
template <typename VAL_TYPE>
inline auto str_k_num_v_pairs_vec_range_querier(const std::vector< std::pair<std::string, VAL_TYPE> >& input, 
    const float left_bound, const float right_bound, const std::string mode) -> std::vector< std::pair<std::string, VAL_TYPE> > {
  std::vector< std::pair<std::string, VAL_TYPE> > output;
  for (auto& pair : input) {
    //TODO: Convert to `std::copy_if` style.
    if (mode == "inner") {
      if (pair.second < right_bound && pair.second > left_bound) { output.emplace_back(pair); }
    } else if (mode == "outer") {
      if (pair.second > right_bound || pair.second < left_bound) { output.emplace_back(pair); }
    }
  }
  return output;
}


/**
 * @brief
 * Select top n `std::pair` objects from input according each `std::pair` object's numerical value.
 *
 * @t_param VAL_TYPE Same with `str_k_num_v_pairs_vec_range_querier`.
 * @param input Same with `str_k_num_v_pairs_vec_range_querier`.
 * @param top_n Top n items to keep.
 * @param sort_mode Sorting mode for `input`, "descend" for descending, "ascend" for ascending.
 */
template <typename VAL_TYPE>
inline auto str_k_num_v_pairs_vec_top_querier(const std::vector< std::pair<std::string, VAL_TYPE> >& input, 
    const int32_t top_n, const std::string sort_mode) -> std::vector< std::pair<std::string, VAL_TYPE> > {
  std::vector< std::pair<std::string, VAL_TYPE> > output;
  std::vector< std::pair<std::string, VAL_TYPE> > output_tmp = input;

  if (top_n > input.size()) { return output; }
  if (sort_mode != "descend" && sort_mode != "ascend") { return output; }

  if (sort_mode == "descend") {
    std::sort(output_tmp.begin(), output_tmp.end(), 
        [](const std::pair<std::string, VAL_TYPE>& a, const std::pair<std::string, VAL_TYPE>& b) -> bool { 
          return a.second > b.second; 
        }
    );
  } else if (sort_mode == "ascend") {
    std::sort(output_tmp.begin(), output_tmp.end(), 
        [](const std::pair<std::string, VAL_TYPE>& a, const std::pair<std::string, VAL_TYPE>& b) -> bool {
          return a.second < b.second;
        }
    );
  }
  output.assign(output_tmp.begin(), output_tmp.begin() + top_n);
  return output;
}


} // namesapce cill

#endif
