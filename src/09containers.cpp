#include <catch.hpp>
#include <map>

TEST_CASE("09 - Containers")
{
    WHEN("Experiment std::vector")
    {
        //A vector is an array, with a variable size
        //It is backed by array.
        //There are many over implementations of collections in C++, like List, Set, Deque, Stack
        std::vector<int> myVector;
        WHEN("Vector is initialized")
        {
            THEN("It is empty")
            {
                REQUIRE(myVector.size() == 0);
            }
        }
        WHEN("Add 10")
        {
            myVector.push_back(10);
            THEN("Size is 1")
            {
                REQUIRE(myVector.size() == 1);
            }
            THEN("First element is 10")
            {
                REQUIRE(myVector[0] == 10);
            }
        }
        WHEN("Copy from a list")
        {
            myVector = {10, 20, 30, 40, 50};
            THEN("Vector size is 5")
            {
                REQUIRE(myVector.size() == 5);
            }
            WHEN("Loop over myVector to make a copy")
            {
                std::vector<int> myCopyVector;
                //Note auto keyword: the type of 'element' is resolved by compiler at compile time (here 'int')
                //Please also note that this is a very inefficient copy, in a real program we would use the copy constructor
                for(auto element : myVector)
                {
                    myCopyVector.push_back(element);
                }
                THEN("Vector are the sames")
                {
                    REQUIRE(myCopyVector == myVector);
                }
            }
        }
    }
    WHEN("Experiment Map")
    {
        std::map<std::string, int> myValues;
        WHEN("Put a value")
        {
            myValues["coucou"] = 2;
            THEN("Can retreive it")
            {
                REQUIRE(myValues["coucou"] == 2);
            }
            THEN("Map is not empty")
            {
                REQUIRE(myValues.size() == 1);
            }
            THEN("Can retreive an iterator pointing to the value")
            {
                auto it = myValues.find("coucou");
                REQUIRE(it->second == 2);
            }
            THEN("Can iterate over this simple value")
            {
                int size = 0;
                //Here type of entry is pair<std::string, int>
                //Do you see the why auto keyword is usefull ?
                for(auto entry: myValues) {
                    ++size;
                    REQUIRE(entry.first == "coucou");
                    REQUIRE(entry.second == 2);
                }
                REQUIRE(size == 1);
            }
        }
    }
}
