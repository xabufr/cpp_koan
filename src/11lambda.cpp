#include <catch.hpp>

TEST_CASE("11 - Lambdas")
{
    WHEN("Use copy capture")
    {
        int a = 5;
        //The [=] means the lambda capture all body parameters from parent scope by copy
        auto lambda = [=](int b)->int {
            return a + b;
        };

        THEN("With 5 return 10")
        {
            REQUIRE(lambda(5) == 10);
        }
        WHEN("Change a value")
        {
            a = 0;
            THEN("With 5 return ?")
            {
                REQUIRE(lambda(5) == 10);
            }
        }
    }
    WHEN("Use reference capture")
    {
        WHEN("Make some read-only operations on captured parameters")
        {
            int a = 5;
            //&a mean the lambda retreive the value of a by reference
            auto lambda = [&a](int b)->int {
                return a + b;
            };

            THEN("With 5 return 10")
            {
                REQUIRE(lambda(5) == 10);
            }
            WHEN("Change a value")
            {
                a = 0;
                THEN("With 5 return ?")
                {
                    REQUIRE(lambda(5) == 5);
                }
            }
        }
        WHEN("Try to modify captured variables")
        {
            int a = 0;
            auto lambda = [&a]{
                ++a;
            };
            WHEN("Call lambda")
            {
                lambda();
                THEN("a is modified")
                {
                    REQUIRE(a == 1);
                }
            }
        }
    }
}
