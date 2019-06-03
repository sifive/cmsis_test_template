#ifndef CMSIS_TEST_UTIL_H
#define CMSIS_TEST_UTIL_H

#include <stdint.h>

typedef float float32_t;

#ifdef CMSIS_TEST_GEN_DATA

#define REGISTER_FUNCTION_DECLEAR(type)                                        \
  void register_##type(const char *name, type **pData);

REGISTER_FUNCTION_DECLEAR(int8_t)
REGISTER_FUNCTION_DECLEAR(int16_t)
REGISTER_FUNCTION_DECLEAR(int32_t)
REGISTER_FUNCTION_DECLEAR(uint8_t)
REGISTER_FUNCTION_DECLEAR(uint16_t)
REGISTER_FUNCTION_DECLEAR(uint32_t)
REGISTER_FUNCTION_DECLEAR(float32_t)

#define REGISTER_TEST_DATA(type, name)                                         \
  type *pTestData_##name;                                                      \
  register_##type(#name, &pTestData_##name);

#define GET_TEST_DATA(type, name) *(pTestData_##name)

#else

#define REGISTER_TEST_DATA(type, name) extern type name;
#define GET_TEST_DATA(type, name) name

#endif // CMSIS_TEST_GEN_DATA

#endif // CMSIS_TEST_UTIL_H
