/*
 NAME : Hanna Rakhsha               CS 4350 – Unix Systems Programming
 Serial Number: 25
 Assignment Number: 7
 Due Date: 12 / 2 / 2019
 */
#include <stdio.h>
#include <pthread.h>
#include <math.h>

//Prototypes for input validation and threads
void validation();
void menu();
int power(int, int);
void *threadOdd(int);
void *threadEven(int);
void *threadHailstone(int);
void *threadArmstrong(int);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 1;

int main(){
   int number, rtn;
   pthread_t tid[4];
   
   menu();
   
   rtn = scanf("%d", &number);
   
   //Check if number is integer and greater than 0
   if(rtn == 0 || number <= 0){
      validation();
      printf("\n\n**** Number must be grantor than 0 ***\n\n");
      printf("Program by Hanna Rakhsha\n12 – 2 - 2019\n");
      return (0);
   }
   else
      validation();
   
   printf("\n\nAll Odd / Even numbers between 1 and %d\n\n", number);
   
   //Create the two threads needed for the even/odd print
   pthread_create(&tid[0], NULL, (void *(*)(void *))threadOdd, number);
   pthread_create(&tid[1], NULL, (void *(*)(void *))threadEven, number);
   
   //Join them so they follow each other sequentially
   pthread_join(tid[0], NULL);
   pthread_join(tid[1], NULL);
   
   //Create the other threads so they don't interfere with the first 2
   pthread_create(&tid[2], NULL, (void *(*)(void *))threadHailstone, number);
   pthread_create(&tid[2], NULL, (void *(*)(void *))threadArmstrong, number);
   
   //Join them so they follow each other sequentially
   pthread_join(tid[2], NULL);
   pthread_join(tid[3], NULL);
   
   //Footer comment and exit the program
   printf("Program by Hanna Rakhsha\n12 – 2 - 2019\n");
   
   pthread_exit(0);
   return (0);
}

//Function to print out the intro menu of the program.
void menu(){
   printf("Welcome to Hanna Rakhsha's Thread App\n\n"
          "This program will do the following:\n\n"
          "Accepts an integer number X from the user and then uses 4\n"
          "synchronized threads in order to do the following:\n\n"
          "1.The first thread prints all odd numbers between 1\n"
          "  and X.\n"
          "2.The second thread prints all the even numbers\n"
          "  between 1 and X.\n"
          "3.The third thread print the hailstone sequence for the\n"
          "  number X.\n"
          "4.The last thread determines whether or not X is an\n"
          "  Armstrong number.\n\n"
          "Enter an Integer > 0 --- >\t");
}
//Function to validate user input as an integer greater than 0
void validation(){
   int c = getchar();
   while (c != '\n' && c != EOF)
      c = getchar();
}

//Function to return x to the power of y. Was having trouble with pow()
//even while including math.h so I wrote my own to be safe.
int power(int x, int y){
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y/2) * power(x, y/2);
    else
        return x * power(x, y/2) * power(x, y/2);
}

//Function to print all odd numbers from the user's input.
//Uses counter and lock to work with threadEven to print output in order
void *threadOdd(int num){
   pthread_mutex_lock(&mutex);
   
   while(counter <= num){
      if(counter % 2 != 0){
         printf("Function1: %d\n", counter);
         counter++;
      }
      else
         pthread_mutex_unlock(&mutex);
   }
}

//Function to print all even numbers from the user's input.
//Uses counter and lock to work with threadOdd to print output in order
void *threadEven(int num){
   pthread_mutex_lock(&mutex);
   
   while(counter <= num){
      if(counter % 2 == 0){
         printf("Function2: %d\n", counter);
         counter++;
      }
      else
         pthread_mutex_unlock(&mutex);
   }
}

/*
 Function to find the Hailstone sequence of the user's input. The Hailstone
 sequence is a sequence of numbers where if n is even, then the next number
 is n/2. If n is odd, then the next number is 3n + 1. The sequence contnutes
 until the number 1 is written.
 */
void *threadHailstone(int num){
   sleep(1);
   printf("\n\n\nFunction3 - Hailstone Process Started\n"
          "Input Number %d\n", num);
   printf("Hailstone sequence of %d is : %d, ", num, num);
   while(num != 1){
      if(num % 2 == 0){
         num = num/2;
         printf("%d, ", num);
      }
      else if(num % 2 == 1){
         num = (3 * num) + 1;
         printf("%d, ", num);
      }
      else if(num == 1){
         printf("%d", num);
         break;
      }
   }
   printf("\nHailstone Process Exits\n\n\n\n");
}

/*
 Function to find whether or not the user's input is an Armstrong number.
 A positive integer is called an Armstrong number if the sum of cubes of
 the individual digit is equal to that number itself.
 */
void *threadArmstrong(int num){
   
   int originalNumber = num, remainder, total = 0;
   
   sleep(1);
   printf("Function4 - Armstrong Process Started\n\n");
   
   while(originalNumber != 0){
      remainder = originalNumber%10;
      total += power(remainder, 3);
      originalNumber /= 10;
   }
   
   if(total == num)
      printf("%d is an Armstrong number\n\n", num);
   else
      printf("%d is not an Armstrong number\n\n", num);
}
