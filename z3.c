#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void int_in(int* n){
    char c[100];
    int error = 0;
    do{
    error = 0;
    fgets(c, sizeof(c), stdin);

    if (c[0] < '0' || c[0] > '9') {
      if (c[0] != '-') {
        error = 1;
      }
    }

    for (int i = 1; c[i] != '\n'; i++)
    {
      if (c[i] < '0' || c[i] > '9') {
        error = 1;
        break;
      }
    }

    if(!error)
    {
      if (sscanf(c, "%d", n) == 1)
        {
          return;
        }
      else{printf("Please enter one number\n");}
    }
    else{printf("Please enter a number\n");}
    }while(error);
    return;
}
int rand_in(){
    int n  = 0; 
    srand(clock());
    n = rand() % 129 - 35;
    return n;
}
void do_something(int a[100][100], int n, int n1){
    int sum = 0;
    for(int i = 0;i < n / 2;i++){
        for(int j = 0;j < n1 / 2;j++){
            sum += a[i][j];
        }
    }
    printf("%s %d \n", "sum =", sum);
}
int main(){
    int a[100][100];
    int f = 0;
    int n = 0;
    int n1 = 0;
    system("clear");
    puts("PLEASE ENTER SIZE OF NATRIX(max size - [100][100], min size[0][0])");
    while(1){
        int_in(&n);
        if(n <= 100 || n >= 0)
            break;
        else
            puts("max size - [100][100], min size[0][0]");
    }
    n1 = n;
    puts("HOW DO YOU WANT TO ENTER MATRIX(1 - manually, 0 - randomly)");
    while(1){
        int_in(&f);
        if(f == 0 || f == 1)
            break;
        else
            puts("PLEASE enter 1 or 0");
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n1;j++){
            if(f == 1)
                int_in(&a[i][j]);
            else
                a[i][j] = rand_in();
        }
    }
    puts("-------------------\n");
    puts("YOUR matrix:\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n1;j++){
            printf("%d " "", a[i][j]);
        }
        puts("\n");
    }
    puts("-------------------");
    do_something(a, n, n1);
return 0;
}