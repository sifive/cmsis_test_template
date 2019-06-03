#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "test_utils.h"

int32_t test_scalar(void) { return 10; }

int32_t test_vector(void) { return 10; }

int main(int argc, char **argv) {
  REGISTER_TEST_DATA(int32_t, result_scalar);

#ifdef CMSIS_TEST_GEN_DATA
  GET_TEST_DATA(int32_t, result_scalar) = test_scalar();
#else

#ifdef CMSIS_TEST_VECTOR
  int32_t result_user = test_vector();
#else
  int32_t result_user = test_scalar();
#endif  //CMSIS_TEST_VECTOR

#ifdef CMSIS_TEST_COMPARE
  if (result_user == GET_TEST_DATA(int32_t, result_scalar)) {
    printf("pass\n");
  } else {
    printf("failed\n");
  }
#endif  // CMSIS_TEST_COMPARE
#endif  // CMSIS_TEST_GEN_DATA
  return 0;
}
