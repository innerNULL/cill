// 2020-07-23

#ifndef CILL_PRINT_KIT_PRINTER_H_
#define CILL_PRINT_KIT_PRINTER_H_

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
namespace print_kit {


template <typename INPUT_TYPE>
inline int32_t print_simple_num_vector(const std::vector<INPUT_TYPE>& input, const std::string delimiter=",") {
  std::string print_str;
  for (auto& item : input) {
    print_str = print_str + std::to_string(item) + delimiter;
  }
  print_str.pop_back();
  std::cout << print_str << std::endl;
  return 0;
}


} // namespace print_kit
} // namesapce cill

#endif
