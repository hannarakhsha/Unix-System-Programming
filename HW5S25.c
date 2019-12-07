/*
NAME: Hanna Rakhsha                  CS 4350 – Unix Systems Programming
Serial Number: 25
Assignment Number: 5
Due Date: 11/4/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 This function displays the menu for the assignment.
 */
void menu(){
   printf("\n\nSelect one of the following :\n\n"
   "1. Generate a Password\n"
   "2. Detect Password\n"
   "9. Display the Password and Exit The program\t");
}

/*
 This function clears the buffer after input is read from the user.
 */
void validation(){
   int c = getchar();
   while (c != '\n' && c != EOF)
      c = getchar();
}

/*
 This function generates a random number between 2 given values.
*/
int randomNum(int lower, int upper){
   int num = 0;
   num = (rand() % (upper - lower + 1)) + lower;
   return num;
}

/*
 This function creates a password by randomly generating 4 numbers. Then each
 of the 4 random numbers is used in its respective array to get that unique
 character. The function returns the 4 character password.
 */
char *passwordCreate(char password[5]){
   srand(time(0));
   
   static char *passPtr;
   char numArr[] = {"0123456789"};
   char specialArr[] = {"!$%&'()*+,-./;<=>?@[]}{^~#`:"};
   char capitalArr[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
   char lowerArr[] = {"zyxwvutsrqponmlkjihgfedcba"};
   
   int num = randomNum(0, 9);
   int num2 = randomNum(0, 27);
   int num3 = randomNum(0, 25);
   int num4 = randomNum(0, 25);
   
   password[0] = numArr[num];
   password[1] = specialArr[num2];
   password[2] = capitalArr[num3];
   password[3] = lowerArr[num4];
   
   passPtr = password;
   
   return passPtr;
}

/*
 This function takes the password from the above function as a parameter and
 inputs a user's guess. The two are compared and output is respective to
 if the password is correct or incorrect. Function returns 1 for true and
 0 for false.
 */
int detectPassword(char *str){
   char guess[5];
   
   printf("\nEnter Password :\t");
   scanf("%s", guess);
   
   if(strcmp(str, guess) == 0){
      printf("\nPassword is Correct\n");
      return 1;
   }
   else{
      printf("\nIncorrect Password\n");
      return 0;
   }
}

int main(int argc, const char * argv[]) {
   int choice, flagChoice = 1, rtn, trueFalse = 0;
   char pass[5], *password = "";
   
   printf("Password Generator\n\nThis program will:-\n");
   printf("   •  Generate a password.\n   •  Guesses the password\n");
   printf("   •  Displays the Generated Password and Terminates the Program\n");
   
   while(flagChoice == 1){
      menu();
      rtn = scanf("%d", &choice);
      
      if(rtn == 0)
         validation();
      else
         validation();
      
      switch(choice){
         case 1:
            password = passwordCreate(pass);
            printf("%s", "\nPassword is Generated\n");
            //Uncomment to see password for testing purposes
            //printf("%s", password);
            break;
            
         case 2:
            if(strcmp(password, "") == 0)
               printf("\nNo password has been generated to detect.\n");
            else
               trueFalse = detectPassword(password);
            break;
            
         case 9:
            if(trueFalse == 1)
               printf("\nThis Algorithm is designed and Implemented by\n"
                      "Hanna Rakhsha - Security Group Inc.\n"
                      "November – 4 – 2019\n");
            else{
               printf("\n%s\t%s\n", "The Generated Password :", password);
               printf("\nThis Algorithm is designed and Implemented by\n"
                      "Hanna Rakhsha - Security Group Inc.\n"
                      "November – 4 – 2019\n");
            }
               
            flagChoice = 0;
            break;
            
         default:
            printf("\nInvalid Selection\n");
            break;
      }
   }
   
   return 0;
}
