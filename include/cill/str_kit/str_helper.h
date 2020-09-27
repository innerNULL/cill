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


/**
 * @brief
 * Replace all substrings in string with another substring.
 *
 * @prarm target_str Target string which certain sub-string will be replaced.
 * @param replacing_substr The sub-string which holp to be replaced with `using_substr`.
 * @param using_substr Using this to replace all `replacing_substr` exist in `target_str`.
 */
inline int32_t substr_replace(std::string& target_str, 
    const std::string replacing_substr, const std::string using_substr) {
  std::string::size_type pos = 0;
  std::string::size_type replacing_substr_size = replacing_substr.size();
  std::string::size_type using_substr_size = using_substr.size();

  while ( (pos = target_str.find(replacing_substr, pos)) != std::string::npos ) {
    //std::cout << "dbg " << pos  << " " << replacing_substr_size << " " << using_substr_size << std::endl;
    target_str.replace(pos, replacing_substr_size, using_substr);
    pos += using_substr_size;
  }
  return 0;
}


} // namesapce cill

#endif
