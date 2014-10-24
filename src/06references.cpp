#include <catch.hpp>

TEST_CASE("06 - References, Pointers")
{
    int variable = 5;
    //A reference must be initialized with a variable, and it can't be changed
    int &reference = variable;
    int *pointer = nullptr;

    REQUIRE(variable == 5);
    WHEN("Change reference value")
    {
        reference = 6;
        THEN("variable value should change")
        {
            REQUIRE(variable == 6);
        }
    }
    WHEN("Make pointer point to variable")
    {
        //Pointers MUST be initialized, or the program will receive SIGSEV
        pointer = &variable;
        THEN("pointer pointed value should be 5")
        {
            REQUIRE(*pointer == 5);
        }
        THEN("Pointer should be evaluated as true")
        {
            CHECK(pointer);
        }
    }
    WHEN("Pointer is nullptr")
    {
        THEN("Pointer should be evaluated as false")
        {
            CHECK_FALSE(pointer);
        }
    }
}
