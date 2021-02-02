// file: test.cpp
// date: 2021-02-01


#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "include/cill/print_kit/printer.h"
#include "include/cill/random_kit/random.h"
#include "include/cill/random_kit/random_num.h"
#include "include/cill/iterator_kit/elastic_indexer.h"
#include "include/cill/str_kit/str_helper.h"
#include "include/cill/str_kit/str_parser.h"




TEST(str_kit_TEST, str_spliter_TEST) {
  // case 0
  std::string case0_var0 = "a-b-c-d-e-f-g";
  std::string case0_var1 = "-";
  std::vector<std::string> case0_target = {"a", "b", "c", "d", "e", "f", "g"};
  ASSERT_THAT(cill::str_spliter(case0_var0, case0_var1), testing::ContainerEq(case0_target));

  // case 1
  std::string case1_var0 = "--,-a-b--c-d-e-f---";
  std::string case1_var1 = "-";
  std::vector<std::string> case1_target = {",", "a", "b", "c", "d", "e", "f"};
  ASSERT_THAT(cill::str_spliter(case1_var0, case1_var1), testing::ContainerEq(case1_target));

  // case 2
  std::string case2_var0 = "abbcbbebb";
  std::string case2_var1 = "bb";
  std::vector<std::string> case2_target = {"a", "c", "e"};
  ASSERT_THAT(cill::str_spliter(case2_var0, case2_var1), testing::ContainerEq(case2_target));

  // case 3
  std::string case3_var0 = "aabbccbbeebb";
  std::string case3_var1 = "bb";
  std::vector<std::string> case3_target = {"aa", "cc", "ee"};
  ASSERT_THAT(cill::str_spliter(case3_var0, case3_var1), testing::ContainerEq(case3_target));

  // case 4
  std::string case4_var0 = "we,will.go'to!end...of~the world";
  std::string case4_var1 = ",,'!...~ ";
  std::vector<std::string> case4_target = {"we", "will", "go", "to", "end", "of", "the", "world"};
  ASSERT_THAT(cill::str_spliter(case4_var0, case4_var1), testing::ContainerEq(case4_target));
}
