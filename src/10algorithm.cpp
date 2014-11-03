#include <catch.hpp>

TEST_CASE("10 - Algorithms")
{
    //In C++, many algorithms are implemented with Templates,
    //Most of them takes iterators to delimit their range of action
    //Sort, remove, find, etc...

    std::vector<int> array = {10, 20, 30, 40, 50, -1, -2, -3, -4, -5};
    WHEN("Find value 50")
    {
        auto it = std::find(array.begin(), array.end(), 50);
        THEN("Position is 4")
        {
            REQUIRE(std::distance(array.begin(), it) == 4);
        }
        THEN("Value is 50")
        {
            REQUIRE(*it == 50);
        }
    }
    WHEN("Remove 50")
    {
        std::remove(array.begin(), array.end(), 50);
        THEN("Begin to end don't contains 50")
        {
            for(auto value : array)
            {
                REQUIRE(value != 50);
            }
        }
    }
    WHEN("Count 50")
    {
        int count = std::count(array.begin(), array.end(), 50);
        THEN("Occurances is 1")
        {
            REQUIRE(count == 1);
        }
    }
    WHEN("Sort")
    {
        std::sort(array.begin(), array.end());
        THEN("Array is really sorted")
        {
            auto current = array.front();
            for(auto value : array)
            {
                REQUIRE(current <= value);
                current = value;
            }
        }
    }
    WHEN("Swap")
    {
        int a = 5, b = 10;
        std::swap(a,b);
        THEN("Values are swapped")
        {
            REQUIRE(a == 10);
            REQUIRE(b == 5);
        }
    }
    WHEN("Use algorithms with C++11 Lambdas")
    {
        //This is a Lambda function
        //We will see the complete syntax in the next chapter
        std::sort(array.begin(), array.end(), [](int a, int b)->bool{
            return b < a;
        });
        THEN("Array is really DESC sorted")
        {
            auto current = array.front();
            for(auto value : array)
            {
                REQUIRE(current >= value);
                current = value;
            }
        }
    }
}
