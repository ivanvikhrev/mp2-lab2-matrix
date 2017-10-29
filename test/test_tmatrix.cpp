#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 12;
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 1;
	TMatrix<int> m2(m1);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 2;
	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(10);
	EXPECT_EQ(m.GetSize(), 10);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(10);
	m[0][0] = 3;
	EXPECT_EQ(m[0][0], 3);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(10);
	ASSERT_ANY_THROW(m[-1][-1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(10);
	ASSERT_ANY_THROW(m[11][1] = 1);
	ASSERT_ANY_THROW(m[2][10] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m[i][j] = 1;
	m = m;
	EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 1;
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m2[i][j] = 2;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(20);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 1;
	m2 = m1;
	EXPECT_EQ(m2.GetSize(), 10);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(20);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 1;
	m2 = m1;
	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
		}
	
	EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m[i][j] = 1;;
	EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(20);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 1;
	for (int i = 0; i < 20; i++)
		for (int j = 19; j >= i; j--)
			m2[i][j] = 1;
    EXPECT_EQ(true, m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m1[i][j] = 3;
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
			m2[i][j] = 1;
	TMatrix<int> m3(m1 + m2);
	EXPECT_EQ(4, m3[1][1]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(11);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 9; j >= i; j--)
		{   
			m1[i][j] = 1;
			m2[i][j] = 1; 
		}
	TMatrix<int> m3(m1 - m2);
	EXPECT_EQ(m3[1][1], 0);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(11);
	ASSERT_ANY_THROW(m1 - m2);
}

