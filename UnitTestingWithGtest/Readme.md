----------
ASSERT is fatal
EXPECT  is not fatal(doesn't abort current function)

examples:
ASSERT_TRUE(condition);
ASSERT_FALSE(COND);

ASSERT_EQ(2+2,4);
ASSERT_NE(2+2,4);
ASSERT_LT(2+2,4);

String assertions:
ASSERT_STREQ(A,B);

ASSERT_STRNE(A,B);

ASSERT_STRCASEEQ(A,B);
ASSERT_STRCASENE(A,B);

ASSERT_THROW(statement, exception_type);
ASSERT_ANY_THROW(statement);
ASSERT_NO_THROW(statement);



Predicate asserts:
ASSERT_PRED1(IsEven, a);
ASSERT_PRED2(IsEven, a,b);

To add more info:
ASSERT_EQ(x,y) << " x is not equal to y";


To link using cmake

    
find_package(GTest CONFIG REQUIRED)
target_link_libraries(main PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
    

CMD
--gtest_list_tests

---    
--gtest_filter
to run only specified tests.
     * xyzTest
     * xyx*, *zTest, *yz*
    * xyzTest?
---
- | to run all but not this test
---
Separated by :
x.*: ab*-xy.old

--gtest_also_run_disabled_tests

--gtest_repeat=count

--gtest_shuffle
--gtest_random_seed=number
--gtest_color
 On/Off/Auto
--gtest_print_time

--gtest_output=xml
can specify file and directory:


For Simple debugging on test fail
Do not use in CI server
--gtest_break_on_failure

For servers with limitted test support
--gtest_throw_on_failure 

- Do not report exceptions as errors.
- Allow them to crash the program.
--gtest_catch_exceptions
=1 or =0


--gtest_filter=Encode*
Starting with Encode but not ending with String
--gtest_filter=Encode*-*String
