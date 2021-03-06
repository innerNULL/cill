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


/**
 * @brief Prints `std::vector<std::string>` with certain delimiter.
 *
 * @param input Target printing `std::vector<std::string>` object.
 * @param delimiter Using delimiter to join each elements.
 */
inline int32_t print_simple_str_vector(const std::vector<std::string>& input, const std::string delimiter=",") {
  std::string print_str;
  for (auto& item : input) {
    print_str = print_str + item + delimiter;
  }
  print_str.pop_back();
  std::cout << print_str << std::endl;
  return 0;
}


/**
 * @brief
 * Similiar with `print_simple_str_vector`, but support for numerical element type of input vector.
 * 
 * @t_param INPUT_TYPE Basical numerical data types, such as int, float, double, etc.
 */
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


/**
 * @brief
 * Printing each key-value pairs in a `std::vector< std::pair<std::string, VAL_TYPE> >` object, with certain 
 * delimiter-using rule.
 *
 * @t_param VAL_TYPE The data type of key-value pair's value, it should be certain basical numerical data type.
 * @param input Target printing object.
 * @param kv_delimiter Delimiter for key and value for each kv-pair.
 * @param kv_pair_delimiter Delimiter for each kv-pairs.
 */
template <typename VAL_TYPE>
inline int32_t print_vector_of_str_k_num_v_pairs(const std::vector< std::pair<std::string, VAL_TYPE> >& input, 
    const std::string kv_delimiter=":", const std::string kv_pair_delimiter=",") {
  std::string print_str;
  for (auto& kv_pair : input) {
    print_str = print_str + kv_pair.first + kv_delimiter + std::to_string(kv_pair.second) + kv_pair_delimiter;
  }
  print_str.pop_back();
  std::cout << print_str << std::endl;
  return 0;
}


} // namesapce cill

#endif
