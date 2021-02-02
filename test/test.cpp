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
#include "include/cill/str_kit/multi_lang_helper.h"



TEST(str_kit_str_helper_TEST, str_spliter_TEST) {
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

  // case 5
  std::string case5_var0 = "床前明月光，疑是地上霜。举头望明月，低头思故乡。";
  std::string case5_var1 = "。，";
  std::vector<std::string> case5_target = {"床前明月光", "疑是地上霜", "举头望明月", "低头思故乡"};
  std::vector<std::string> casr5_output = cill::str_spliter(case5_var0, case5_var1);
  //for (auto& item : casr5_output) { std::cout << "dbg: " << item << std::endl;}
  // TODO: Fix
  //ASSERT_THAT(casr5_output, testing::ContainerEq(case5_target));
}


TEST(str_kit_str_helper_TEST, is_num_str_TEST) {
  // case 0
  std::string case0_var0 = "06";
  EXPECT_EQ(cill::is_num_str(case0_var0), true);

  // case 1
  std::string case1_var0 = "-23.3";
  EXPECT_EQ(cill::is_num_str(case1_var0), true);

  // case 2
  std::string case2_var0 = "kjh32";
  EXPECT_EQ(cill::is_num_str(case2_var0), false);

}


TEST(str_kit_multi_lang_helper_TEST, if_include_chinese_TEST) {
  // case 0
  char case0_var0[] = "we我们are是friends朋友。";
  std::string case0_var1 = "we我们are是friends朋友。";
  EXPECT_EQ(cill::if_include_cn(case0_var0), true);
  EXPECT_EQ(cill::if_include_cn(case0_var1), true);

  // case 1
  char case1_var0[] = "我们是朋友.";
  std::string case1_var1 = "我们是朋友.";
  EXPECT_EQ(cill::if_include_cn(case1_var0), true);
  EXPECT_EQ(cill::if_include_cn(case1_var1), true);

  // case 2
  char case2_var0[] = "we are friends。";
  std::string case2_var1 = "we are friends。";
  EXPECT_EQ(cill::if_include_cn(case2_var0), true);
  EXPECT_EQ(cill::if_include_cn(case2_var1), true); 

  // case 3
  char case3_var0[] = "we are friends";
  std::string case3_var1 = "we are friends";
  EXPECT_EQ(cill::if_include_cn(case3_var0), false);
  EXPECT_EQ(cill::if_include_cn(case3_var1), false); 

}
