#include <catch.hpp>

TEST_CASE("02 - Polymorphism")
{
    class BaseClass
    {
    public:
        int getValue() const
        {
            return 1;
        }
        virtual int getValueBis() const
        {
            return 2;
        }
    };
    class ChildClass: public BaseClass
    {
    public:
        int getValue() const
        {
            return 10;
        }
        virtual int getValueBis() const override
        {
            return 20;
        }
    };
    BaseClass base;
    ChildClass child;
    WHEN("Base class test behaviour")
    {
        THEN("Value should be 1")
        {
            REQUIRE(base.getValue() == 1);
        }
        THEN("ValueBis should be 2")
        {
            REQUIRE(base.getValueBis() == 2);
        }
    }
    WHEN("Child class test behaviour")
    {
        THEN("Value should be 1")
        {
            REQUIRE(child.getValue() == 10);
        }
        THEN("ValueBis should be 2")
        {
            REQUIRE(child.getValueBis() == 20);
        }
    }
    //This is a Reference, we will see this syntax later.
    //The only thing you must understand is that this reference can refer to any type that inherit from BaseClass
    const BaseClass &realTypeMasked = child;
    WHEN("With polymorphism(realTypeMasked) class test behaviour")
    {
        //To correct these tests, please read carefully classes definition.
        //Did you note the virtual keyword ?
        THEN("What is the value returned by getValue ?")
        {
            REQUIRE(realTypeMasked.getValue() == 0);
        }
        THEN("What is the value of valueBis ?")
        {
            REQUIRE(realTypeMasked.getValueBis() == 0);
        }
    }
}
