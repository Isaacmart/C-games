#include <stdio.h> 
#include <string.h>


void FindIntersection(char * strArr[], int arrLength) {
  
  char str0[strlen(strArr[0]) + 1]; /* str0[] */
  strcpy(str0, strArr[0]);
  char str1[strlen(strArr[1]) + 1]; /* str1[] */
  strcpy(str1, strArr[1]);

  char *token0, *series0[10], *token1, *series1[10];      
  int index = 0, count = 0, number = 0, add = 0;
  
  token0 = strtok(str0, ", ");

  while ( token0 != NULL ) {
    series0[index++] = token0;
    token0 = strtok(NULL, ", ");
    count++;
  }

  token1 = strtok(str1, ", ");

  while ( token1 != NULL) {
      series1[number++] = token1;
      token1 = strtok(NULL, ", ");
      add++;

  }

  for ( int i = 0; i < count; i++ ) {

    for ( int a = 0; a < add; a++ ) {

      if ( strcmp(series0[i], series1[a]) == 0 ) {

        if ( ( i < (count - 1) ) && ( a < (add) ) ) {

          printf("%s,", series0[i]);
        }
        else {

          printf("%s", series0[i]);
        }

      }
    }
  }
}

int main(void) { 
   
  // keep this function call here
  char * A[] = {"2, 5, 7, 10, 11, 12", "2, 7, 8, 9, 10, 11, 15"};
  int arrLength = sizeof(A) / sizeof(*A);
  FindIntersection(A, arrLength);
  return 0;
    
}