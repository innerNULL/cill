// 2020-07-23

#ifndef CILL_RANDOM_KIT_RANDOM_NUM_H_
#define CILL_RANDOM_KIT_RANDOM_NUM_H_

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


namespace cill {
namespace random_kit {


inline auto random_bin() -> int32_t {
  int32_t random_output = rand() % 10;
  return (random_output < 5) ? 0 : 1;
}


template <typename INPUT_TYPE>
inline auto uniform_random(const INPUT_TYPE& lower_bound, const INPUT_TYPE& up_bound) -> INPUT_TYPE {
  INPUT_TYPE adj_up_bound = up_bound + INPUT_TYPE(1);
  INPUT_TYPE random_result = (INPUT_TYPE)((double)rand() / ((double)RAND_MAX / (adj_up_bound - lower_bound)) + lower_bound);
  return random_result;
}


template <typename INPUT_TYPE>
inline auto random_uniform_vector(const int32_t target_size, 
    const INPUT_TYPE lower_bound, const INPUT_TYPE up_bound, const bool if_uniq=true) -> std::vector<INPUT_TYPE> {
  std::vector<INPUT_TYPE> random_result;
  INPUT_TYPE tmp_single_random_result;

  while (true) {
    if (random_result.size() >= target_size) { break; }

    tmp_single_random_result = uniform_random<INPUT_TYPE>(lower_bound, up_bound);
    if (if_uniq) {
      auto iter = std::find(random_result.begin(), random_result.end(), tmp_single_random_result);
      if (iter == random_result.end()) {
        random_result.emplace_back(tmp_single_random_result);
      }
    } else {
      random_result.emplace_back(tmp_single_random_result);
    }
  }
  return random_result;
}



} // namespace random_kit
} // namesapce cill

#endif
