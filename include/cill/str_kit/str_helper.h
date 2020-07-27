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


inline bool is_num_str(const std::string input) {
  std::stringstream sin(input);
  double num_holder;
  char char_holder;
  if (!(sin >> num_holder)) { return false; }
  if (sin >> char_holder) { return false; }
  return true;
}


inline auto str_spliter(std::string input, const std::string& delimiter) -> std::vector<std::string> {
  std::vector<std::string> output;

  int32_t location = input.find(delimiter);
  while (location != std::string::npos) {
    if (location != 0) { output.push_back(input.substr(0, location)); }
    input = input.substr(location + delimiter.size());
    location = input.find(delimiter);
  }

  if (input.size() > 0) { output.push_back(input); }
  return output;
}


} // namesapce cill

#endif
