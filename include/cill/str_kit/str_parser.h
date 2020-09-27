// 2020-07-24

#ifndef CILL_STR_KIT_STR_PARSER_H_
#define CILL_STR_KIT_STR_PARSER_H_

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

#include "../str_kit/str_helper.h"


namespace cill {


template <typename VAL_TYPE>
inline auto str_str_k_num_v_group_parser(const std::string& input, 
    const int32_t key_index, const int32_t val_index, 
    const std::string& kv_group_delimiter, const std::string kv_delimiter) -> std::vector< std::pair<std::string, VAL_TYPE> > {
  // Internal vars
  std::vector< std::pair<std::string, VAL_TYPE> > output;
  std::vector<std::string> splitted_groups = str_spliter(input, kv_group_delimiter);
  std::vector<std::string> splitted_kvs;

  for (auto& group : splitted_groups) {
    splitted_kvs = str_spliter(group, kv_delimiter);
    if (splitted_kvs.size() <= key_index || splitted_kvs.size() <= val_index) { continue; }
    if (!is_num_str(splitted_kvs[val_index])) { continue; }
    output.emplace_back(
        std::pair<std::string, VAL_TYPE>(splitted_kvs[key_index], (VAL_TYPE)std::stof(splitted_kvs[val_index])));
  }
  return output;
}


/**
 * @brief
 * Parsing a string in format such as "key0 ${kv_delimiter} val0 ${kv_group_delimiter} key1 ... " 
 * into as `unordered_map`.
 *
 * @param dest The destination which will save parsing result.
 * @param input Original input string which waiting parsing.
 * @param kv_group_delimiter The delimiter sign which seperate different kv pairs into several groups.
 * @param kv_delimiter The delimiter sign which seperate each kv-group's key and value.
 */
inline int32_t str_k_str_v_groups_str_parser(std::unordered_map<std::string, std::string>& dest, 
    const std::string& input, const std::string& kv_group_delimiter, const std::string kv_delimiter) {
  // Internal vars
  std::vector<std::string> kv_groups = str_spliter(input, kv_group_delimiter);
  std::vector<std::string> kv_pair;
 
  for (auto& group : kv_groups) {
    kv_pair = str_spliter(group, kv_delimiter);
    dest.insert(std::pair<std::string, std::string>(kv_pair[0], kv_pair[1]));
  }
  return 0;
}


} // namesapce cill


#endif
