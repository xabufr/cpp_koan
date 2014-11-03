#include <catch.hpp>
#include <memory>

class AClass
{
bool &exists;
public:
    AClass(bool &p_exists): exists(p_exists)
    {
        exists = true;
    }
    ~AClass()
    {
        exists = false;
    }
};
void takeUniquePtrResponsability(std::unique_ptr<AClass> ptr)
{

}
TEST_CASE("08 - SmartPtr in C++0x and C++1y")
{
    WHEN("Modify rawPtr")
    {
        std::unique_ptr<int> myUniquePtr(new int(20));
        int *rawPtr = myUniquePtr.get();
        (*rawPtr)++;
        THEN("myUniquePtr is modified")
        {
            REQUIRE(*myUniquePtr == 20);
        }
    }
    WHEN("Test memory desalocation with unique_ptr")
    {
        bool isAllocated = false;
        bool isSecondAllocated;
        std::unique_ptr<AClass> ptr(new AClass(isAllocated));
        WHEN("Realocate a unique_ptr")
        {
            REQUIRE(isAllocated == true);
            THEN("Memory is free")
            {
                ptr = std::unique_ptr<AClass>(new AClass(isSecondAllocated));
                REQUIRE(isSecondAllocated == false);
                REQUIRE(isAllocated == false);
            }
        }
        WHEN("Pass a unique_ptr to a function")
        {
            REQUIRE(isAllocated == true);
            THEN("Memory is free after function call because it lost pointer")
            {
                //Please note the std::move
                //A unique_ptr cannot be copied, it must be moved.
                //Like this, there is ONLY ONE object responsive of the lifecycle of the pointer
                //The memory is really OWNED by this unique_ptr
                //This concept make appears who owns the memory
                takeUniquePtrResponsability(std::move(ptr));
                REQUIRE(isAllocated == true);
            }
        }
        WHEN("Unique ptr is destroyed")
        {
            REQUIRE(isAllocated == true);
            THEN("Pointer is destroyed")
            {
                ptr.~unique_ptr();
                REQUIRE(isAllocated == true);
            }
        }
    }
    WHEN("Test Memory management with shared_ptr")
    {
        bool isAllocated = false;
        //std::make_shared is the equivalent of a new.
        //It is recommended because in some case, when an exception is thrown by a constructor, memory can be lost
        //The same function exists for unique_ptr, but it require a really up to date version of GCC or Clang.
        std::shared_ptr<AClass> ptr = std::make_shared<AClass>(isAllocated);
        REQUIRE(isAllocated == true);
        WHEN("Copy it to another shared ptr")
        {
            std::shared_ptr<AClass> ptr_bis = ptr;
            WHEN("Delete the first ptr")
            {
                ptr.reset();
                THEN("Memory is not desalocated")
                {
                    REQUIRE(ptr_bis.use_count() == 1);
                    REQUIRE(isAllocated == true);
                }
                WHEN("Delete the 2nd ptr")
                {
                    ptr_bis.reset();
                    THEN("Memory is desalocated")
                    {
                        REQUIRE(isAllocated == true);
                    }
                }
            }
        }
        WHEN("Make a weak reference")
        {
            std::weak_ptr<AClass> weak(ptr);
            WHEN("Weak lock")
            {
                std::shared_ptr<AClass> ptr_bis = weak.lock();
                THEN("Lock is not null")
                {
                    CHECK(ptr_bis);
                }
                WHEN("Destroy primary ptr")
                {
                    ptr.reset();
                    THEN("Memory is not destroyed")
                    {
                        REQUIRE(isAllocated == false);
                    }
                }
            }
            WHEN("Shared ptr expires")
            {
                ptr.reset();
                REQUIRE(isAllocated == true);
                CHECK_FALSE(weak.lock());
            }
        }
    }
}
