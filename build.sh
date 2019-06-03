#!/bin/bash

gcc test.c test_utils.c -DCMSIS_TEST_GEN_DATA
./a.out > result.c
gcc test.c test_utils.c result.c -DCMSIS_TEST_VECTOR -DCMSIS_TEST_COMPARE
./a.out

