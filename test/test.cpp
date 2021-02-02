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



int tmp(int a, int b) { return a + b; }


TEST(str_kit_TEST, str_spliter_TEST) {
  std::string case0_var0 = "a-b-c-d-e-f-g";
  std::string case0_var1 = "-";
  std::vector<std::string> case0_var2 = {"a", "b", "c", "d", "e", "f", "g"};
  ASSERT_THAT(cill::str_spliter(case0_var0, case0_var1), testing::ContainerEq(case0_var2));
}
