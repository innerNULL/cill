// file: path_helper.h
// datye: 2020-12-18


#ifndef CILL_SYS_KIT_PATH_HELPER_
#define CILL_SYS_KIT_PATH_HELPER_


#include "../str_kit/str_helper.h"


namespace cill {


auto get_path_delimiter() -> std::string {
#ifdef _WIN_32
  return "\\";
#else
  return "/";
#endif
}


auto path_join(const std::string& path_0, const std::string& path_1) -> std::string {
  std::string output;
  std::string sys_path_sep = get_path_delimiter();

  output = path_0 + path_1;
  substr_replace(output, sys_path_sep + sys_path_sep, sys_path_sep);
  return output;
}


} // namespace cill


#endif
