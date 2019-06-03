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
  int32_t result_vector = test_vector();
  if (result_vector == GET_TEST_DATA(int32_t, result_scalar)) {
    printf("pass\n");
  } else {
    printf("failed\n");
  }
#endif

  // test_data = 10;

  return 0;
}
