#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 5
#define SIZE (N * N)

int read_input(int matrix[N][N]);
void print_error(int error_num);  
void print_matrix(int matrix[N][N]);
int is_magic_square(int matrix[N][N]);

int main(){
  int matrix[N][N]; /*Initialize the matrix*/
  
  printf("Please enter %d integers for the magic square, seperated by whitespaces: \n", SIZE);
  
  /*Raise an error if:
  - Less inputs then N
  - More inputs then N
  - Not all inputs are Integers
   */
  if(!read_input(matrix)){
      printf("Action failed.\n");
      return 0;
    }
    /*Print matrix for the user*/
    print_matrix(matrix);
    
    /*Tell the user if the matrix is "magic square" or not*/
    if(is_magic_square(matrix))
      printf("This is a magic square!\n");
    else
      printf("This is NOT a magic square!\n");
      
    return 0;
}

int read_input(int matrix[N][N]){
/*variables decleration*/
  int count = 0;
  char c;
  int num;
  int row, col;
  
  while(count < SIZE){
    int result = scanf("%d%c", &num,&c); /*Get the integer and the char after it*/
    if(result == EOF) break;
    /* Check for non integer chars after last int input*/
    if(result != 2 || (c != ' '&& c != '\n' && c != '\t')) {
      print_error(2);
      return 0;
    }
    
    /*Calculate row and column numbers for num*/
    row = count / N;
    col = count % N;
    
    matrix[row][col] = num;
    count++;
  }
  
  /* Not enough values in input*/
  if(count < SIZE) {
    print_error(0);
    return 0;
  }
  
  /*Too many values in input - we received an input after the loop has ended here*/
  if(scanf("%d", &num) == 1) {
    print_error(1);
    return 0;
  }
  
  return 1;
}

/*print the correct error message based on error code*/
void print_error(int error_num){
  switch(error_num){
    case 0:
      printf("Error: Not enough integers for a %dx%d magic square\n", N, N);
      break;
    case 1:
      printf("Error: Too many values received for a %dx%d magic square\n", N, N);
      break;
    case 2:
      printf("Error: Incorrect type of input\n");
      break;
    default:
      printf("Unexpected error\n"); 
  }
}

void print_matrix(int matrix[N][N]){
int i, j;
  printf("\nMatrix:\n");
  for(i = 0;i < N; i++){
    for(j = 0;j < N; j++){
      printf("%4d", matrix[i][j]); /* the 4 is for the gap between the numbers*/
    }
    printf("\n");
  }
}

int is_magic_square(int matrix[N][N]){
/*variables assignment*/
  int i, j;
  int target_sum = 0;
  int diag1 = 0, diag2 = 0;
  
  /*Get the sum of the first row*/
  for(i = 0; i < N;i++)
    target_sum += matrix[0][i];
    
/* Compare the sum of the rest of the rows columns and diagnols to the first row
  If 1 of them don't match its not a magic square*/
  
  /*Compare rows*/
  for(i = 0;i < N;i++){
    int row_sum = 0;
    for(j = 0; j < N; j++)
      row_sum += matrix[i][j];
    if(row_sum != target_sum)
      return 0;
  }
  
  /*Compare columns*/
  for(i=0;i < N;i++){
    int col_sum = 0;
    for(j = 0; j < N;j++)
      col_sum += matrix[j][i];
    if(col_sum != target_sum)
      return 0;
  }
  
  /*Compare diagnols*/
  for(i = 0; i < N; i++){
    diag1 += matrix[i][i];
    diag2 += matrix[i][N - i - 1];
  }
  if(diag1 != target_sum || diag2 != target_sum)
    return 0;
  
  return 1;
}
  
