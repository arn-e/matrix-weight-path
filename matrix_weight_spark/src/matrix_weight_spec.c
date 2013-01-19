#include "../matrix_weight.h"

#include <assert.h>
#include <stdbool.h>


static void test_matrix_weight()
{
	int rows = 3;
	int columns = 3;
	int matrix[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
	
	assert ( calculated_weight(matrix, rows, columns) == 4 
			&& "test_matrix_weight()" );

}

int main(int argc, char const *argv[])
{
	test_matrix_weight();
	return 0;
}
