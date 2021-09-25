#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int M = 3;
const int N = 3;

void comp_pick_square(char arr[M][N]){
    int b, e;
    b = rand() % 3;
    e = rand() % 3;
    if(arr[b][e] == 0) {
        arr[b][e] = 1;
    }
    else{
        comp_pick_square(arr);
    }
}

void user_pick_square(char arr[M][N]){
    int b, e;
    b = rand() % 3;
    e = rand() % 3;
    if(arr[b][e] == 0) {
        arr[b][e] = 2;
    }
    else{
        user_pick_square(arr);
    }
}

int check_winner(char array[M][N]) {
    int winner;
    if ( (array[0][0] == array[0][1]) && (array[0][1] == array[0][2]) && (array[0][2] != 0) ) {
        winner = 1;
        printf("%s\n", "1 won");
    }
    else if ( (array[0][0] == array[1][0]) && (array[1][0] == array[2][0]) && (array[2][0] != 0) ) {
        winner = 1;
        printf("%s\n", "2 won");
    }
    else if ( (array[0][0] == array[1][1]) && (array[1][1] == array[2][2]) && (array[2][2] != 0) ) {
        winner = 1;
        printf("%s\n", "3 won");
    }
    else if ( (array[0][1] == array[1][1]) && (array[1][1] == array[2][1]) && (array[2][1] != 0) ) {
        winner = 1;
        printf("%s\n", "4 won");
    }
    else if ( (array[0][2] == array[1][2]) && (array[1][2] == array[2][2]) && (array[2][2] != 0) ) {
        winner = 1;
        printf("%s\n", "5 won");
    }
    else if ( (array[0][2] == array[1][1]) && (array[1][1] == array[2][0]) && (array[2][0] != 0) ) {
        winner = 1;
        printf("%s\n", "6 won");
    }
    else if ( (array[1][0] == array[1][1]) && (array[1][1] == array[1][2]) && (array[1][2] != 0)) {
        winner = 1;
        printf("%s\n", "7 won");
    }
    else if ( (array[2][0] == array[2][1]) && (array[2][1] == array[2][2]) && (array[2][2] != 0)) {
        winner = 1;
        printf("%s\n", "8 won");
    }
    else {
        winner = 0;
        printf("%s\n", "continue");
    }
    return winner;

}

void to_string(char array[M][N]){
    int i,j;
    for( i = 0; i < 3; i++  ) {
        for ( j = 0; j < 3; j++ ) {
            if(array[i][j] == 0){
                printf("| %c ", ' ');
            }
            else if(array[i][j] == 2){
                printf("| %c ", 'O');
            }
            else{
                printf("| %c ", 'X');
            }
        }
        printf("|\n");
        printf("-------------\n");
    }
}

int main(void){

    srand(time(0));
    char array[3][3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int k, h;
    k = 1;
    h = 2;
    int win = 0;

    check_winner(array);
    while(check_winner(array) == 0){
        user_pick_square(array);
        comp_pick_square(array);
        check_winner(array); 
        win++;
    }
    comp_pick_square(array);
    check_winner(array);
    to_string(array);
}
