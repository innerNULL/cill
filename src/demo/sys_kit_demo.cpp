// file: sys_kit_demo.cpp
// date: 2020-12-18

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

#include "include/cill/print_kit/printer.h"
#include "include/cill/random_kit/random.h"
#include "include/cill/random_kit/random_num.h"
#include "include/cill/iterator_kit/elastic_indexer.h"
#include "include/cill/iterator_kit/elastic_querier.h"
#include "include/cill/sys_kit/path_helper.h"


auto path_helper_demo() -> int32_t {
  printf("Curr sys's path seperator is '%s'. \n", cill::get_path_delimiter().c_str());

  printf("testing `path_join` function\n");
  printf("%s%s", cill::path_join("/user/fake/", "/fake1/fake2").c_str(), "\n");
  
  std::vector<std::string> dir_files;
  cill::list_dir(dir_files, "./", true);
  for (auto& item : dir_files) { std::cout << item << std::endl; }
  return 0;
}


int main(int argc, char *argv[]) {
  path_helper_demo();
  return 0;
}


