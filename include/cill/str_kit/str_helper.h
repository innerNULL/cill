// 2020-07-24

#ifndef CILL_STR_KIT_STR_HELPER_H_
#define CILL_STR_KIT_STR_HELPER_H_

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
namespace str_kit {


inline auto str_spliter(std::string input, const std::string& delimiter) -> std::vector<std::string> {
  std::vector<std::string> output;
  int32_t location;

  while ((location = input.find(delimiter))) {
    if (location == std::string::npos) { break; }
    if (location != 0) { output.push_back(input.substr(0, location)); }
    input = input.substr(location + delimiter.size());
  }

  if (input.size() > 0) { output.push_back(input); }
  return output;
}


} // namespace str_kit
} // namesapce cill

#endif
