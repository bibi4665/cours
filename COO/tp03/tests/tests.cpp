#include <gtest/gtest.h>
#include "../include/Vector.h"

TEST(VectorTest, Constructeur)

{
    ASSERT_EQ(Vector(0), 0u);
    ASSERT_EQ(Vector(1), 1u);
} 