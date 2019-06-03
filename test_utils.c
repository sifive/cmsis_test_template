#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_utils.h"

typedef enum {
  TestDataType_int8_t = 0,
  TestDataType_int16_t,
  TestDataType_int32_t,
  TestDataType_uint8_t,
  TestDataType_uint16_t,
  TestDataType_uint32_t,
  TestDataType_float32_t
} TestDataType;

typedef enum {
  SCALAR = 0,
  ARRAY,
} ArrayType;

typedef struct {
  void *mDataPtr;
  const char *mDataName;
  TestDataType mDataType;
  ArrayType mArrayType;
  uint32_t mArraySize;
} TestData;

const uint32_t TEST_DATA_LIMIT = 64;
static TestData gTestData[TEST_DATA_LIMIT];
static uint32_t gTestDataCount = 0;

#define REGISTER_FUNCTION_IMPL(type)                                           \
  void register_##type(const char *name, type **pData) {                       \
    TestData *test_data = &gTestData[gTestDataCount++];                        \
    assert(gTestDataCount < TEST_DATA_LIMIT);                                  \
                                                                               \
    *pData = malloc(sizeof(type));                                    \
    test_data->mDataPtr = *pData;                                              \
    test_data->mDataName = name;                                               \
    test_data->mDataType = TestDataType_##type;                                \
    test_data->mArrayType = SCALAR;                                            \
  }

REGISTER_FUNCTION_IMPL(int8_t)
REGISTER_FUNCTION_IMPL(int16_t)
REGISTER_FUNCTION_IMPL(int32_t)
REGISTER_FUNCTION_IMPL(uint8_t)
REGISTER_FUNCTION_IMPL(uint16_t)
REGISTER_FUNCTION_IMPL(uint32_t)
REGISTER_FUNCTION_IMPL(float32_t)

#ifdef CMSIS_TEST_GEN_DATA
__attribute__((constructor)) void cmsis_test_init() {
  //printf("i am cmsis_test_init\n");
}

__attribute__((destructor)) void cmsis_test_cleanup() {
  //printf("i am cmsis_test_cleanup\n");
  printf("#include <stdint.h>\n");
  for (uint32_t i = 0; i < gTestDataCount; ++i) {
    printf("int32_t %s = %d;\n", gTestData[i].mDataName, *((int32_t *)gTestData[i].mDataPtr));
  }
}
#endif
