#include <stdio.h>
#include <jni.h>

int path_score(int rows, int columns, int collection[rows][columns], int value, int row_level)
{
  int lowest_score = 0;
  int sum = 0;

  for (int i = 0; i < columns; i ++){
    sum = (value + collection[row_level][i]);
    if (!lowest_score) { lowest_score = sum; }
    if (sum < lowest_score) { lowest_score = sum; }
  }

  if (row_level < rows - 1){
    row_level ++;
    lowest_score = path_score(rows, columns, collection, lowest_score, row_level);
  }

  return lowest_score;
}

int shortest_path(int rows, int columns, int collection[rows][columns])
{
  int shortest_path = 0;

  for (int i = 0; i < columns; i ++){
    int weight = path_score(rows, columns, collection, collection[0][i],1);
    if (!shortest_path) { shortest_path = weight; }
    if (weight < shortest_path){ shortest_path = weight; }
  }
  
  return shortest_path;
}

void populate_matrix(int rows, int columns, int collection[rows][columns], int values[])
{
  int inc = 0;
  for (int i = 0; i < rows; i ++){
    for (int j = 0; j < columns; j ++){
      collection[i][j] = values[inc];
      inc ++;
    }
  }
}

int calculated_weight(int values[], int rows, int columns)
{
  int collection[rows][columns];

  populate_matrix(rows, columns, collection, values);
  int result = shortest_path(rows, columns, collection);  

  return result;
}

JNIEXPORT jint JNICALL Java_ShortWeight_matrixWeight
  (JNIEnv * env, jobject jobj, jintArray matrix_values, jint rows, jint columns)
{
  jint *matrix_ptr;
  jint i, sum = 0;

  matrix_ptr = (*env)->GetIntArrayElements(env, matrix_values, NULL);
  int matrix_weight = calculated_weight(matrix_ptr, rows, columns);
  (*env)->ReleaseIntArrayElements(env, matrix_values, matrix_ptr, 0);

  return matrix_weight;
}
