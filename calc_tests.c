#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>
#include <cmocka.h>
#include <math.h>

#include "calc_tests.h"
#include "calc.h"

double __real_pow(double x, double y);

double __wrap_pow(double a, double b)
{
    return mock_type(double);
}

static void add_test_success(void **state) {
    (void) state; /* unused */
    
    double expected, actual;
    double a = 3.00;
    double b = 4.53;

    expected = a + b;
    actual = add(a, b);

    assert_true(expected == actual);
}

static void pow_test_success(void **state)
{
    (void) state; // unused

    double expected, actual;
    double x = 1;
    double y = 2;

    expected = __real_pow(x + y, x + y);

    will_return(__wrap_pow, 27);
    
    actual = pow_of_sum(x, y);

    assert_true(expected == actual);
}

int main(void) {
    const struct CMUnitTest tests[] = {
    cmocka_unit_test(add_test_success),
    cmocka_unit_test(pow_test_success),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
