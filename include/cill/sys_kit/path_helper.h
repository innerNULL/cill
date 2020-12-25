// file: path_helper.h
// datye: 2020-12-18


#ifndef CILL_SYS_KIT_PATH_HELPER_
#define CILL_SYS_KIT_PATH_HELPER_


#include <iostream>
#include "../str_kit/str_helper.h"


namespace cill {


/**
 * @brief Get path seperator according os.
 */
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


auto list_dir(std::vector<std::string>& dest, const std::string target_path, 
      const bool if_full_path=true) -> int32_t {
  dest.clear();

  std::string shell_cmd = "ls " + target_path;
  FILE* fp;
  char buffer[65536];

  fp = popen(shell_cmd.c_str(), "r");
  while (fgets(buffer ,sizeof(buffer), fp) != NULL) {
      std::string tmp_str_(buffer);
      cill::substr_replace(tmp_str_, "\n", "");
      dest.emplace_back(if_full_path ? path_join(target_path, tmp_str_) : tmp_str_);
  }
  //for (auto& item : dest) { std::cout << item << std::endl; }
  return 0;
}


} // namespace cill


#endif
