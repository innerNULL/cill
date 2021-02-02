// file: multi_lang_helper.h
// date: 2021-02-02

#ifndef CILL_STR_KIT_MULTI_LANG_HELPER_H_
#define CILL_STR_KIT_MULTI_LANG_HELPER_H_

#include <algorithm>    
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>
#include <map>


namespace cill {

/**
 * @brief Judge if there any Chinese char in string
 *
 * @param str Input c-style string.
 */
bool if_include_cn(const char* input) {
  char tmp;
  while (true) {
    tmp = *(input++);
    if (tmp == 0) { break; }
    if (tmp & 0x80) {
      if (*input & 0x80) {
        return true;
      }
    }
  }
  return false;
}


bool if_include_cn(const std::string& input) { return if_include_cn(input.c_str()); }


} // namesapce cill

#endif
