// 2020-07-23

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

#include "include/cill/num_kit/random.h"


int main(int argc, char *argv[]) {
  for (int32_t i = 0; i < 20; ++i) {
    auto output = cill::num_kit::random_bin();
    std::cout << output << std::endl;
  }
  return 0;
}


