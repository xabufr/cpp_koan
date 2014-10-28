#include <catch.hpp>
#include <exception>
#include <iostream>

class Movable
{
bool m_isOwner;
bool m_copyied;
bool m_isAssigned;
public:
    Movable(): m_isOwner(false), m_copyied(false), m_isAssigned(false)
    {
    }
    Movable(const Movable& other)
    {
        m_copyied = false;
        m_isAssigned = false;
        m_isOwner = other.isOwner();
    }
    Movable(Movable &&other)
    {
        m_copyied = false;
        m_isAssigned = false;
        if(other.isOwner())
        {
            other.m_isOwner = false;
            m_isOwner = true;
        }
        else
        {
            throw std::exception();
        }
    }
    Movable& operator=(const Movable& other)
    {
        m_isOwner = other.isOwner();
        m_isAssigned = true;
        return *this;
    }
    bool isOwner() const
    {
        return m_isOwner;
    }
    void owner()
    {
        m_isOwner = true;
    }
    bool copyied() const
    {
        return m_copyied;
    }
    bool isAssigned() const
    {
        return m_isAssigned;
    }
};
TEST_CASE("07 - Move Semantic")
{
    Movable myMovable;
    WHEN("Movable is created")
    {
        THEN("Movable is correctly initialized")
        {
            CHECK_FALSE(myMovable.isOwner());
            CHECK_FALSE(myMovable.copyied());
        }
        myMovable.owner();
        CHECK(myMovable.isOwner());
        WHEN("Move")
        {
            Movable moved(std::move(myMovable));
            THEN("Original is not Owner")
            {
                CHECK_FALSE(myMovable.isOwner());
                CHECK(moved.isOwner());
            }
            THEN("Moved instance is only moved, not copyied")
            {
                CHECK_FALSE(myMovable.copyied());
                CHECK_FALSE(moved.copyied());
                CHECK_FALSE(moved.isAssigned());
            }
        }

    }
}
