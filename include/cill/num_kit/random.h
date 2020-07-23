// 2020-07-23

#ifndef CILL_NUM_KIT_RANDOM_H_
#define CILL_NUM_KIT_RANDOM_H_

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


namespace cill {
namespace num_kit {


inline auto random_bin() -> int32_t {
  int32_t random_output = rand() % 10;
  return (random_output < 5) ? 0 : 1;
}


} //namespace num_kit
} // namesapce cill

#endif
