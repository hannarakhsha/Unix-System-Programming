#!/bin/sh

#NAME: Hanna Rakhsha              CS 4350 - Unix Systems Programming
#Serial Number: 25
#Assignment Number: 3
#Due Date: 10/7/2019

echo "CS 4350 - Unix Systems Programming"
echo "Name: Hanna Rakhsha"
echo "Serial Number: 25"
echo "Functions and Arrays"
echo "Assignment Number: 3"
echo "Due Date: 10/7/2019"

echo
echo "The function of this script is to:"

echo "1. List detailed list of all files in your directory. Redirect the output to"
echo "   zlsCommandFiles.txt"
echo "2. Create directory by checking its existence"
echo "3. Test if File Exist."
echo "4. Append \"Learning Scripts and Shell Programming\" to an existing File."
echo "5. Rename an existing File."
echo "6. Delete an existing File."
echo "7. Delete an existing Directory."
echo "8. Parse Current Date"
echo "9. Display a calendar for a specific month / year"
echo
echo "15. Exit"

echo

ls_to_file()
{
   for file in *;
   do
      ls -la > zlsCommandFiles.txt
   done
   
   echo "zlsCommandFiles.txt is created"
   echo
}

check_directory()
{
   if [ -d $1 ]
   then
      echo
      echo "$1 already exists"
      echo
   else
      mkdir $1
      echo
      echo "Directory created: $1"
      echo
   fi
}

check_file()
{
   if [ -f $1 ]
   then
      filename[0]=$( wc -l <"$1" )
      filename[1]=$( wc -w <"$1" )
      filename[2]=$( cat $1 )
      
      echo
      echo "Number of lines and words: ${filename[0]} ${filename[1]}"
      echo
      echo "File Content"
      echo
      echo "${filename[2]}"
      echo
   else
      touch $1
      echo
      echo "$1 does not exist (but was created)"
      echo
   fi
}

file_append()
{
   if [ -f $1 ]
   then
      filename[0]=$( cat $1 )
      echo "Learning Scripts and Shell Programming" >> $1
      filename[1]=$( cat $1 )
      
      echo
      echo "File Content Before Append"
      echo
      echo "${filename[0]}"
      echo
      echo
      echo "File Content After Append"
      echo
      echo "${filename[1]}"
      echo
   else
      echo
      echo "$1 does not exist"
      echo
   fi
}

rename_file()
{
   if [ -f $1 ]
   then
      echo
      read -p "Enter the new name:  " name
      mv $1 $name
      echo
      echo "$1 is renamed to $name"
      echo
   else
      echo
      echo "$1 does not exist"
      echo
   fi
}

delete_file()
{
   if [ -f $1 ]
   then
      echo
      rm $1
      echo "$1 is deleted"
      echo
   else
      echo
      echo "$1 does not exist"
      echo
   fi
}

delete_directory()
{
   if [ -d $1 ]
   then
      echo
      rmdir $1
      echo "$1 is deleted"
      echo
   else
      echo
      echo "$1 does not exist"
      echo
   fi
}

parse_date()
{
   set $(date)
   echo "Current Date is:  $1 $2 $3"
   echo
   echo "Current Time is:  $4"
   echo
}

specific_date()
{
   echo
   echo "$(cal $1 $2)"
   echo
}

while true
do
   echo
   read -p "Enter Your Choice:  " choice
   echo
   case $choice in
      1)    ls_to_file
            ;;
      2)    read -p "Enter Name of the Directory:  " directory
            check_directory $directory
            ;;
      3)    read -p "Enter File Name:  " file
            check_file $file
            ;;
      4)    read -p "Enter File Name:  " file
            file_append $file
            ;;
      5)    read -p "Enter file name to be renamed:  " file
            rename_file $file
            ;;
      6)    read -p "Enter the name of file to be deleted:  " file
            delete_file $file
            ;;
      7)    read -p "Enter the name of directory to be deleted:  " directory
            delete_directory $directory
            ;;
      8)    parse_date
            ;;
      9)    read -p "Enter Month:  " month
            echo
            read -p "Enter Year:  " year
            specific_date $month $year
            ;;
      15)   echo "Hanna Rakhsha - 10-7-2019"
            break
            ;;
      *)    echo "Invalid choice"
            echo
            ;;
   esac
done
