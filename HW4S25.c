//NAME: Hanna Rakhsha               CS 4350 – Unix Systems Programming
//Serial Number: 25
//Assignment Number: 4
//Due Date: 10/21/2019

#include <stdio.h>

int patternOne(int size){
   
   int i, j;
   
   printf("\n\nPattern 1 is displayed\n\n");
   
   for(i = 0; i < size; i++){
      for(j = 0; j < size; j++){
         if (i == j)
            printf("%d", size);
         else
            printf("P");
      }
      printf("\n");
   }
   
   return 0;}

int patternTwo(int size){
   
   int i, j;
   
   printf("\n\nPattern 2 is displayed\n\n");
   
   for(i = 0; i < size; i++){
      for(j = 0; j < size; j++){
         if ((i + j) == size - 1)
            printf("%d", size);
         else
            printf("P");
      }
      printf("\n");
   }
   
   return 0;
}

int patternThree(int size){
   
   int i, j;
   
   printf("\n\nPattern 3 is displayed\n\n");
   
   for(i = 0; i < size; i++){
      for(j = 0; j < (size - i); j++)
         printf("P");
      
      for(j = (size - i); j < size; j++)
         printf("%d", size);
      
      printf("\n");
   }
   return 0;
}

int patternFour(int size){
   
   int i, j;
   
   printf("\n\nPattern 4 is displayed\n\n");
   
   for(i = 0; i < size; i++){
      for(j = 0; j < i; j++)
         printf("%d", size);

      for(j = i; j < size; j++)
         printf("P");
      
      printf("\n");
   }
   return 0;
}

void menu(){
   printf("Menu\n\n1.     Pattern One\n2.     Pattern Two\n");
   printf("3.     Pattern Three\n4.     Pattern Four\n15.    Quit\n\n");
}

void validation(){
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int main(int argc, const char * argv[]) {
   
   int choice, rtn, rtn2, size, flagChoice = 1;
   
   printf("%56s", "Welcome to My Pattern Program\n");
   printf("This program is written by Hanna Rakhsha. The purpose of this ");
   printf("program is to create\nfour different patterns of different sizes. ");
   printf("The size of each pattern is determined by the\nnumber of columns ");
   printf("or rows. For example, a pattern of size 5 has 5 columns and 5 rows.\n");
   printf("Each pattern is made up of character P and a digit, which shows ");
   printf("the size. The size\nmust be between 2 and 9.\n\n");
   
   menu();
   
   do{
      printf("\nChoose an option (between 1 and 4 or 15 to end the program): ");
      rtn = scanf("%d", &choice);
      int flagSize = 1;
      
      if(rtn == 0){
         validation();
         printf("\nYour option is incorrect. Please try again\n");
      }
      else{
         validation();
      switch(choice){
         case 1:
            while(flagSize == 1){
               printf("\nChoose a pattern size (between 2 and 9): ");
               rtn2 = scanf("%d", &size);
               if (rtn2 == 0){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else if(size < 2 || size > 9){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else{
                  validation();
                  patternOne(size);
                  flagSize = 0;
                  printf("\n\n");
                  menu();
               }
            }
            break;
         case 2:
            while(flagSize == 1){
               printf("\nChoose a pattern size (between 2 and 9): ");
               rtn2 = scanf("%d", &size);
               if (rtn2 == 0){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else if(size < 2 || size > 9){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else{
                  validation();
                  patternTwo(size);
                  flagSize = 0;
                  printf("\n\n");
                  menu();
               }
            }
            break;
         case 3:
            while(flagSize == 1){
               printf("\nChoose a pattern size (between 2 and 9): ");
               rtn2 = scanf("%d", &size);
               if (rtn2 == 0){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else if(size < 2 || size > 9){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else{
                  validation();
                  patternThree(size);
                  flagSize = 0;
                  printf("\n\n");
                  menu();
               }
            }
            break;
         case 4:
            while(flagSize == 1){
               printf("\nChoose a pattern size (between 2 and 9): ");
               rtn2 = scanf("%d", &size);
               if (rtn2 == 0){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else if(size < 2 || size > 9){
                  validation();
                  printf("\nYour pattern size is incorrect. Please try again\n");
               }
               else{
                  validation();
                  patternFour(size);
                  flagSize = 0;
                  printf("\n\n");
                  menu();
               }
            }
            break;
         case 15:
            printf("\nPattern Program By:\nHanna Rakhsha – 10 – 21 - 2019\n");
            flagChoice = 0;
            break;
         default:
            printf("\nYour option is incorrect. Please try again\n");
            break;
      }
         
      }
   }while(flagChoice == 1);
   
   return 0;
}
