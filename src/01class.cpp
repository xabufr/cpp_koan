#include <catch.hpp>

TEST_CASE("01 - Classes definition in C++")
{
    class MyClass
    {
    //In Classes, by default, every member is private
        int a;
    public:
        //This is a valid C++ syntax for members initialization
        MyClass(): a(1)
        {
            //You can also put here 'a = 1;'
        }
        void increment()
        {
            incrementBy(1);
        }
        int value()
        {
            return a;
        }
        void incrementBy(int value)
        {
            a+= value;
        }
    };
    //You can't access directly to member 'a'
    //REQUIRE(a == 1);
    MyClass myInstance;
    WHEN("Use a fresh instance")
    {
        THEN("Value is 1")
        {
            REQUIRE(myInstance.value() == 0);
        }
    }
    WHEN("Increment value")
    {
        myInstance.increment();
        THEN("Value is 2")
        {
            REQUIRE(myInstance.value() == 1);
        }
    }
    WHEN("Increment value by 2")
    {
        myInstance.incrementBy(2);
        THEN("Value is 3")
        {
            REQUIRE(myInstance.value() == 2);
        }
    }
}
