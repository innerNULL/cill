// 2020-07-24

#ifndef CILL_STR_KIT_STR_HELPER_H_
#define CILL_STR_KIT_STR_HELPER_H_

#include <algorithm>    
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>
#include <map>


namespace cill {


inline bool is_num_str(const std::string input) {
  std::stringstream sin(input);
  double num_holder;
  char char_holder;
  if (!(sin >> num_holder)) { return false; }
  if (sin >> char_holder) { return false; }
  return true;
}


inline auto str_spliter_v0(std::string input, const std::string& delimiter) -> std::vector<std::string> {
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


inline auto str_spliter(std::string input, const std::string& delimiter) -> std::vector<std::string> {
  std::vector<std::string> output;
  size_t begin = 0;
  size_t end = 0;

  begin = input.find_first_not_of(delimiter, end);
  while (begin != std::string::npos) {
    end = input.find_first_of(delimiter, begin + 1);
    output.emplace_back(input.substr(begin, end - begin));

    begin = input.find_first_not_of(delimiter, end); 
  }
  return output;
}


inline auto regexpr_spliter(
    std::string input, const std::string& reg_exp) -> std::vector<std::string> {
  std::vector<std::string> output;
  std::regex splitter_reg_expr(reg_exp);
  // TODO: Ref to https://stackoverflow.com/questions/49201654/splitting-a-string-with-multiple-delimiters-in-c/49201823
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
    target_str.replace(pos, replacing_substr_size, using_substr);
    pos += using_substr_size;
  }
  return 0;
}


/**
 * @brief
 * Convert a string form numerical vector, e.g., "1,2,3,4,5", into a numerical `std::vector`.
 *
 * @param dest Destination to saving extracted numerical vector.
 * @param source_str Source string from which we extract the numerical vector.
 * @param Each element's splitter in `source_str`.
 */
template <typename NUM_TYPE>
inline int32_t str2num_vec(std::vector<NUM_TYPE>& dest, const std::string source_str, const std::string delimiter) {
  dest.clear();
  std::vector<std::string> str_elements = str_spliter(source_str, delimiter);
  for (auto& item : str_elements) { dest.emplace_back((NUM_TYPE)std::stof(item)); }
  return 0;
}


} // namesapce cill

#endif
