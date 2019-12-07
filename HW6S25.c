/*
NAME: Hanna Rakhsha                       CS 4350 - Unix Systems Programming
Serial Number: 25
Assignment Number: 6
Due Date: 11/18/2019
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
   
   FILE *fin, *fout;
   int lines = 1, words = 0, lower = 0, capital = 0, digit = 0,
       spaces = 0, special = 0, lineNumber = 1;
   char c = '\0', line[256],
        address[80] = "Texas State University\n601 University Drive"
                      "\nSan Marcos , Texas 78666\nUSA";
   
   //Open input file and write the above string address into it
   fin = fopen("zp6in.txt", "w");

   if (fin == NULL)
      printf("Input file failed to open.");
   else {
      if (strlen(address) > 0)
         fputs(address, fin);
      
      fclose(fin);
   }
   
   //Open input file and swap lowercase/uppercase letters as well as remove
   //spaces. Write new contents to output file zp6out1.txt.
   fin = fopen("zp6in.txt", "r");
   fout = fopen("zp6out1.txt", "w");
   
   if (fin == NULL)
      printf("Input file failed to open.");
   else if (fout == NULL)
      printf("Output file failed to open.");
   else {
      while ((c = fgetc(fin)) != EOF){
         if(islower(c))
            fputc(toupper(c), fout);
         if(isupper(c))
            fputc(tolower(c), fout);
         if(isdigit(c))
            fputc(tolower(c), fout);
         if(isspace(c))
            if(c == '\n'){
               fputc(c, fout);
            }
      }
      fclose(fin);
      fclose(fout);
   }
   
   //Open input file and read line by line, adding line numbers as well as lines
   //into output file zp6out2.txt
   fin = fopen("zp6in.txt", "r");
   fout = fopen("zp6out2.txt", "w");
   
   if (fin == NULL)
      printf("Input file failed to open.");
   else if (fout == NULL)
      printf("Output file failed to open.");
   else{
      while(fgets(line, sizeof(line), fin)){
         fprintf(fout, "%d. %s", lineNumber, line);
         lineNumber++;
      }
      
      fclose(fin);
      fclose(fout);
   }
   
   /*
    Open input file and count lines, words, lower and uppercase letters,
    digits, spaces, and special characters. Special characters are based on ASCII
    values. Output to console along with system call of
    output files and standard assignment footer.
   */
   fin = fopen("zp6in.txt", "r");
   
   if (fin == NULL)
      printf("Input file failed to open.");
   else {
      for (c = getc(fin); c != EOF; c = getc(fin)){
         if (c == '\n')
            lines++;
         if(c ==' ' || c =='\n')
            words++;
         if(islower(c))
            lower++;
         if(isupper(c))
            capital++;
         if(isdigit(c))
            digit++;
         if(isspace(c))
            if(c == ' ')
               spaces++;
         if((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
            continue;
         else if(c >= 48 && c <= 57)
            continue;
         else if(isspace(c))
            continue;
         else
            special++;
      }
      
      printf("File Manipulation Program\n\n");
      printf("The number of lines in file are:\t%d\n", lines);
      printf("The number of words in the file are:\t%d\n", words);
      printf("The number of lowercase letters in the file are:\t%d\n", lower);
      printf("The number of uppercase letters in the file are:\t%d\n", capital);
      printf("The number of digits in the file are:\t%d\n", digit);
      printf("The number of spaces in the file are:\t%d\n", spaces);
      printf("The number of special characters in the file are:\t%d\n\n", special);
      
      system("echo Contents of zp6out1.txt:");
      system("echo");
      system("cat zp6out1.txt");
      system("echo");
      system("echo");
      system("echo");
      system("echo Contents of zp6out2.txt:");
      system("echo");
      system("cat zp6out2.txt");
      system("echo");
      system("echo");
      system("echo");
      system("echo Implemented by Hanna Rakhsha");
      system("echo November - 18 - 2019");
      fclose(fin);
   }
   
   return 0;
}
