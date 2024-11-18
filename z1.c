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
void do_something(int a[8][8]){
    int f = 0;
    int f1 = 0;
    int sum = 0;
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            sum += a[i][j];
            if(a[i][j] < 0)
                f1 = 1;
            if(a[i][j] == a[j][i])
                f++;
            //printf("%s %d %d \n","test =", a[i][j], a[j][i]);
            if(f == 8){
                printf("%s %d \n","k =", i + 1);
                f = 0;
            }
        }
        f = 0;
        if(f1 == 1){
            printf("%s %d %s %d \n","sum =", sum, "i =", i);
            sum = 0;
            f1 = 0;
        }
    }
}
int main(){
    int a[8][8];
    int f = 0;
    system("clear");
    puts("HOW DO YOU WANT TO ENTER MATRIX(1 - manually, 0 - randomly)");
    while(1){
        int_in(&f);
        if(f == 0 || f == 1)
            break;
        else
            puts("PLEASE enter 1 or 0");
    }
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            if(f == 1)
                int_in(&a[i][j]);
            else
                a[i][j] = rand_in();
        }
    }
    puts("-------------------\n");
    puts("YOUR matrix:\n");
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            printf("%d " "", a[i][j]);
        }
        puts("\n");
    }
    puts("-------------------");
    do_something(a);
return 0;
}