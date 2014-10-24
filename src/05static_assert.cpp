#include <catch.hpp>
#include <sox.h>

template<class RET, class T1, class T2>
        RET add(const T1& val1, const T2& val2)
{
    //Here we use traits to determine the real type of template arguments
    //More traits at http://en.cppreference.com/w/cpp/types
    static_assert(std::is_arithmetic<T1>::value, "Arg1 must be arithmetic");
    static_assert(std::is_arithmetic<T2>::value, "Arg2 must be arithmetic");
    static_assert(std::is_arithmetic<RET>::value, "Return type must be arithmetic");
    return (RET) val1 + val2;
}

TEST_CASE("05 - Static assert")
{
    int val1 = 2;
    double val2 = 2.55;
    //If you try to call add with a non-arithmetic type, static_assert will fail, for example a class or a pointer
    REQUIRE(add<double>(val1, val2) == 4.55);

    //For example, the following code fail at compile time because of static assert
    /*std::string val2_1 = "coucou";
    std::string val2_2 = " toi !";
    REQUIRE(add<std::string>(val2_1, val2_2) == "coucou toi !");*/
}
