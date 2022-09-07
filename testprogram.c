#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "operations.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_add(void) {
    int sum = add(1, 2);
    CU_ASSERT_EQUAL(sum, 3);
}

void test_sub(void) {
    int diff = sub(3, 2);
    CU_ASSERT_EQUAL(diff, 1);
}

int main (void)// Main function
{
    CU_pSuite pSuite1 = NULL;

    // Initialize CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add suite1 to registry
    pSuite1 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);
    if (NULL == pSuite1) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // add test_add and test_sub to suite1
    if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing add operation ……..\n\n", test_add)) ||
        (NULL == CU_add_test(pSuite1, "\n\n……… Testing sub operation ……..\n\n", test_sub))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();// OUTPUT to the screen

    CU_cleanup_registry();//Cleaning the Registry
    return CU_get_error();
}
