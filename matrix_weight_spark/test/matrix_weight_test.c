/* matrix_weight_test.c - test cases for matrix_weight.c
 * Bug : the tests currently only compile when the JNI linking code is disabled 
 * Comment out lines 7; 63-74 in matrix_weight.c

 * compiler flags :
 * gcc -std=c99 -Wall matrix_weight_test.c ../src/matrix_weight.c && ./a.out */

#include "../src/matrix_weight.h"

#include <assert.h>
#include <stdbool.h>

static void test_matrix_weight()
{
	int rows = 3; int columns = 3;
	int matrix[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
	
	assert ( calculated_weight(matrix, rows, columns) == 4
			&& "test_matrix_weight()" );

	int second_matrix[] = { 6, 2, 4, 3, 5, 11, 9, 6, 5 };

	assert ( calculated_weight(second_matrix, rows, columns) == 10
			&& "test_matrix_weight()" );
}

int main(int argc, char const *argv[])
{
	test_matrix_weight();
	return 0;
}
