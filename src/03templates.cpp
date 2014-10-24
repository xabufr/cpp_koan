#include <catch.hpp>

//This is a templated class
//Another valid syntax is `template<class T>`
//C++ template, unlike other languages like Java, is totally DuckTyped, checked at compilation time
template<class T> class Wrapper
{
    T value;
public:
    void set(const T& value)
    {
        this->value = value;
    }
    T get() const
    {
        return value;
    }
};

TEST_CASE("03 - Templates")
{
    WHEN("Set 1 in a int wrapper")
    {
        Wrapper<int> intWrapper;
        intWrapper.set(1);
        THEN("Value is 1")
        {
            REQUIRE(intWrapper.get() == 0);
        }
    }

    WHEN("Set 'coucou' in a string wrapper")
    {
        Wrapper<std::string> stringWrapper;
        stringWrapper.set("coucou");
        THEN("Value is coucou")
        {
            REQUIRE(stringWrapper.get() == "not coucou");
        }
    }
}
