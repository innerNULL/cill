// 2020-07-23

#ifndef CILL_RANDOM_KIT_RANDOM_H_
#define CILL_RANDOM_KIT_RANDOM_H_

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
#include <time.h>
#include <sys/timeb.h>


namespace cill {
namespace random_kit {


inline int32_t microsecond_random_seed() {
  struct timeb time_seed;
  ftime(&time_seed);
  srand(time_seed.time * 1000 + time_seed.millitm);
  return 0;
}


} //namespace num_kit
} // namesapce cill

#endif
