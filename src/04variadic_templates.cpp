#include <catch.hpp>

//Theses functions uses Variadic Template, introduced in C++11
//It is only an example, not a code to use in production.
//More usefull cases can be found in other contexts

//This is the final function used only when 2 values remain
template<class RET, class T1, class T2>
RET sumRecurse(T1 val1, T2 val2)
{
    return val1 + val2;
}
//Unpack at least 3 arguments, add the two first, and recurse sum other
template<class RET, class T1, class T2, class... T3>
RET sumRecurse(T1 val1, T2 val2, T3... remaing)
{
    return sumRecurse<RET>(val1 + val2, remaing...);
}

template<class RET, class... T>
RET sum(T... values)
{
    //Let the compiler use the correct implementation of sumRecurse
    return sumRecurse<RET>(values...);
}

TEST_CASE("04 - Variadic Templates")
{
    //Please note we must specify the return type
    //Is it correct ?
    REQUIRE(sum<int>(0.5, 1, 2, 3, 1, 2.5, 2.5) == 12.5);
}
