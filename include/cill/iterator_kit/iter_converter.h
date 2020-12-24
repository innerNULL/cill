
// date: 2020-12-24


#ifndef CILL_ITERATOR_KIT_ITER_CONVERTER_H_
#define CILL_ITERATOR_KIT_ITER_CONVERTER_H_


#include <string>
#include <vector>


namespace cill {


/**
 * @brief Convert 1-dim `std::vector` instance based on basic cpp numerical 
 *     data type sush `int`, `float`, to a single string representation 
 *     with certain `delimiter` as seperator.
 *
 * @t_param ELEMT_TYPE Represents element type of target vector, could only 
 *     be one of basic cpp data types.
 *
 * @param target_vec Target `std::vector` waitting to be represented in string.
 * @param delimiter Delimiter used to seperate each element of vector in final
 *     string.
 */
template<typename ELEMT_TYPE=float>
auto num_1dvector2string(const std::vector<ELEMT_TYPE> target_vec, 
    const std::string& delimiter=",", const int64_t max_elemt_num=1024) -> std::string {
  std::string output = ""; 
  for (int32_t i=0; i < target_vec.size() && i < max_elemt_num; ++i)
    output = output + std::to_string(target_vec[i]) + delimiter;
  if (max_elemt_num < target_vec.size()) {
    output = output + "...";
  } else {
    output.pop_back();  
  }
  return output;
}


} // namespace cill


#endif
