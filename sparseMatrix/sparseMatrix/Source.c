#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
#define A 4
#define B 4
#define C 4

typedef struct {
	int row;
	int col;
	int value;
}element;

//referenced by 4th week's notes

void transpose(element array[], element temp[])
{
	int n, currentb;
	n = array[0].value;
	temp[0].row = array[0].col;
	temp[0].col = array[0].row;
	temp[0].value = n;
	//transpose compact array
	if (n > 0)
	{
		currentb = 1;
		for (int i = 0; i < array[0].col; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (array[j].col == i)
				{
					temp[currentb].row = array[j].col;
					temp[currentb].col = array[j].row;
					temp[currentb].value = array[j].value;
					currentb++;
				}
			}
		}
	}
	//printed temporary array
	for (int i = 0; i <= n; i++)
	{
		printf("%d\t%d\t%d\n", temp[i].row, temp[i].col, temp[i].value);
	}

}
void multiply(element array1[], element array2[])
{
	element result[MAX_SIZE];
	result[0].row = array1[0].row;
	result[0].col = array2[0].row;
	int count = 1;

	//Multiply the values ​​of those with equal number of columns. wrote row values ​​sequentially as rows and columns
	for (int i = 1; i <= array1[0].value; i++)
	{
		for (int j = 1; j <= array2[0].value; j++)
		{
			if (array1[i].col == array2[j].col)
			{
				result[count].row = array1[i].row;
				result[count].col = array2[j].row;
				result[count].value = array1[i].value * array2[j].value;
				count++;
			}
		}
	}
	result[0].value = count - 1;

	printf("Multiplied matrix:\n");
	printf("Row\tColumn\tValue\n");

	for (int i = 0; i < count; i++)
	{
		printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
	}
	printf("\n");

	int count2 = 1;
	element result2[MAX_SIZE];
	result2[0].row = result[0].row;
	result2[0].col = result[0].col;

	//sums values ​​with the same number of rows and columns
	for (int i = 1; i <= result[0].value; i++)
	{
		for (int j = i + 1; j <= result[0].value; j++)
		{
			if (result[i].row == result[j].row && result[i].col == result[j].col)
			{
				result2[count2].value = result[i].value + result[j].value;
				result2[count2].row = result[i].row;
				result2[count2].col = result[j].col;
				count2++;
			}
		}
	}


	printf("Values of the same rows and columns:\n");
	result2[0].value = count2 - 1;
	for (int i = 1; i <= count2 - 1; i++)
	{
		printf("%d\t%d\t%d\n", result2[i].row, result2[i].col, result2[i].value);
	}
}

int main()
{
	int sparseMatrix1[A][B] = { {0,10,0,5},{0,2,4,0},{0,0,0,0},{3,0,0,7} };
	int sparseMatrix2[B][C] = { {1,0,0,2},{0,0,3,0},{0,8,0,0},{5,0,10,0} };
	int count1 = 1;
	int count2 = 1;
	element compact_matrix_1[MAX_SIZE];
	element compact_matrix_2[MAX_SIZE];

	if (B != C)
	{
		printf("These two matrices cannot be multilied!\n");
		printf("B and C have to be equal!\n");
	}
	else if (B == C)
	{
		printf("Entered %d x %d matrix:\n", A, B);
		for (int i = 0; i < A; i++)
		{
			for (int j = 0; j < B; j++)
			{
				printf("%d\t", sparseMatrix1[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		printf("Entered %d x %d matrix:\n", B, C);
		for (int i = 0; i < B; i++)
		{
			for (int j = 0; j < C; j++)
			{
				printf("%d\t", sparseMatrix2[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("---------------------\n");

		compact_matrix_1[0].row = A;
		compact_matrix_1[0].col = B;

		//reduced it to one dimensional array
		for (int i = 0; i < A; i++)
		{
			for (int j = 0; j < B; j++)
			{
				if (sparseMatrix1[i][j] != 0)
				{
					compact_matrix_1[count1].row = i;
					compact_matrix_1[count1].col = j;
					compact_matrix_1[count1].value = sparseMatrix1[i][j];
					count1++;
				}
			}
		}
		compact_matrix_1[0].value = count1 - 1;

		printf("Compact matrix 1:\n");
		printf("Row\tColumn\tValue\n");

		for (int i = 0; i < count1; i++)
		{
			printf("%d\t%d\t%d\n", compact_matrix_1[i].row, compact_matrix_1[i].col, compact_matrix_1[i].value);
		}
		printf("\n");

		compact_matrix_2[0].row = B;
		compact_matrix_2[0].col = C;

		//reduced it to one dimensional array
		for (int i = 0; i < B; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (sparseMatrix2[i][j] != 0)
				{
					compact_matrix_2[count2].row = i;
					compact_matrix_2[count2].col = j;
					compact_matrix_2[count2].value = sparseMatrix2[i][j];
					count2++;
				}
			}
		}
		compact_matrix_2[0].value = count2 - 1;

		printf("Compact matrix 2:\n");
		printf("Row\tColumn\tValue\n");

		for (int i = 0; i < count2; i++)
		{
			printf("%d\t%d\t%d\n", compact_matrix_2[i].row, compact_matrix_2[i].col, compact_matrix_2[i].value);
		}
		printf("\n");

		printf("Transposed compact matrix 2:\n");
		printf("Row\tColumn\tValue\n");

		element transposed[MAX_SIZE];
		transpose(compact_matrix_2, transposed);

		printf("\n");
		multiply(compact_matrix_1, transposed);


	}
	return 0;
}