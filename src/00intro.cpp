#include <catch.hpp>

/*
Welcome to this C++ KOAN
Because C++ compilers do many static checks, I can't make some tests fails without make the entire compilation process fail.
In this case, I will put some comments to let you try by yourself the language behaviour

You can choose the test to run by modifying the variable "currentTestUnit" in the main.cpp
 */

TEST_CASE("00 - Intro")
{
    //This is a simple test
    REQUIRE(1 == 1);

    //This is a failing test, make it pass by modifying one value
    REQUIRE(false == true);
}
