#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	int size;
	size = rand() % 100000 + 1;
	TVector<int> v1(size);
	for (int i = 0; i < size; i++)
		v1[i] = rand() % 1000 ;
	TVector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{   
	TVector<int> v1(10);
	for (int i = 0; i < 10; i++)
		v1[i] = i;
	TVector<int> v2(v1);
	int index;
	index = rand() % 10;
	v2[index] = 100;
	EXPECT_NE(v1, v2);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);
  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[6]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(10);
	for (int i = 0; i < 10 ; i++)
		v[i] = rand() % 1000;
	v = v;
	EXPECT_EQ(v, v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(10);
	TVector<int> v2(10);
	for (int i = 0; i < 10; i++)
		v2[i] = i;
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(1);
	TVector<int> v2(10);
	v1 = v2;
	EXPECT_EQ(v1.GetSize(), 10);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(10);
	for (int i = 0; i <10; i++)
		v1[i] = rand() % 1000;
	TVector<int> v2(12);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(10), v2(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i]= v2[i] = i;
	}

	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(10);
	for (int i = 0; i <10; i++)
		v[i] = rand() % 1000;
	EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(10);
	TVector<int> v2(11);
	EXPECT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(10), v2(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i;
		v2[i] = i + 10;
	}
	v1 = v1 + 10;
	EXPECT_EQ(v1, v2);
}


TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(10), v2(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i;
		v2[i] = i - 10;
	}
		v1 = v1 - 10;
	EXPECT_EQ(v1, v2);

}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(10),v2(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i;
		v2[i] = 2 * i;
	}

		v1 = v1 * 2;
	EXPECT_EQ(v1,v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(10);
	TVector<int> v2(10);
	TVector<int> v3(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i;
		v2[i] = i;
		v3[i] = 2*i;
	}

	EXPECT_EQ(v3, v1+v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(10);
	TVector<int> v2(11);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(10);
	TVector<int> v2(10);
	TVector<int> v3(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i;
		v2[i] = i+1;
		v3[i] = -1;
	}
	EXPECT_EQ(v1-v2, v3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(10);
	TVector<int> v2(11);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3);
	TVector<int> v2(3);
	for (int i = 0; i < 3; i++)
	{
		v1[i] = i;
		v2[i] = i;
	}
	v1 = v1 * v2;
	EXPECT_EQ(v1, 5);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(10);
	TVector<int> v2(11);
	ASSERT_ANY_THROW(v1 * v2);
}

