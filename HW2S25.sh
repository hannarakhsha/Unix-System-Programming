#!/bin/sh

#NAME: Hanna Rakhsha
#Serial Number: 25
#CS 4350 - Unix Systems Programming
#Assignment Number: 2
#Due Date: 9/25/2019

echo "Name: Hanna Rakhsha"
echo "Serial Number: 25"
echo "CS 4350 - Unix Systems Programming"
echo "Assignment Number: 2"
echo "Due Date: 9/25/2019"

echo
echo "The function of this script is to:"
echo

echo "1. The integer arguments that are entered."
echo "2. Sum of the 3 integer arguments."
echo "3. Product of the 3 integer arguments."
echo "4. Average of the 3 integer arguments."
echo "5. Square of each integer argument."
echo "6. Determine that each integer argument is positive, negative, or zero."
echo "7. Determine that each integer argument is odd or even."
echo "8. Find all odd and even numbers between 1 and the second integer argument."
echo "9. Find the factorial of the first integer argument."
echo "10. Determine whether or not the third integer argument is a prime number."

echo
echo

echo "1) The numbers are $1 $2 $3"
echo

total=$(expr $1 + $2 + $3)
echo "2) $1 + $2 + $3 = $total"
echo

product=$(expr $1 \* $2 \* $3)
echo "3) $1 * $2 * $3 = $product"
echo

average=$(expr $total / 3)
echo "4) ($1 + $2 + $3)/3 = $average"
echo

square1=$(expr $1 \* $1)
square2=$(expr $2 \* $2)
square3=$(expr $3 \* $3)
echo "5) $1 * $1 = $square1 , $2 * $2 = $square2 , $3 * $3 = $square3"
echo


if test $1 -gt 0
then
   status1="positive"
elif test $1 -eq 0
then
   status1="zero"
else
   status1="negative"
fi

if test $2 -gt 0
then
   status2="positive"
elif test $2 -eq 0
then
   status2="zero"
else
   status2="negative"
fi

if test $3 -gt 0
then
   status3="positive"
elif test $3 -eq 0
then
   status3="zero"
else
   status3="negative"
fi

echo "6) $1 is $status1 , $2 is $status2 , $3 is $status3"
echo


rem=$(expr $1 % 2)

if test $rem -eq 0
then
   status1="even"
else
   status1="odd"
fi

rem=$(expr $2 % 2)

if test $rem -eq 0
then
   status2="even"
else
   status2="odd"
fi

rem=$(expr $3 % 2)

if test $rem -eq 0
then
   status3="even"
else
   status3="odd"
fi

echo "7) $1 is $status1 , $2 is $status2 , $3 is $status3"
echo


if test $2 -lt 0
then
   for ((i=-3; i > $2; i--))
   do
      if test $(expr $i % 2) -eq -1
      then
         oddArray+=($i)
         i=$i-1
      fi
   done

   for ((i=-1; i > $2; i--))
   do
      if test $(expr $i % 2) -eq 0
      then
         evenArray+=($i)
         i=$i-1
      fi
   done
else
   for ((i=3; i < $2; i++))
   do
      if test $(expr $i % 2) -eq 1
      then
         oddArray+=($i)
         i=$i+1
      fi
   done

   for ((i=1; i < $2; i++))
   do
      if test $(expr $i % 2) -eq 0
      then
         evenArray+=($i)
         i=$i+1
      fi
   done
fi

echo "8) All odd numbers between 1 and $2 are:"
echo "${oddArray[@]}"
echo
echo "8) All even numbers between 1 and $2 are:"
echo "${evenArray[@]}"
echo


if test $1 -lt 0
then
   factorial="not possible"
else
   factorial=1

   for((i=1;i<=$1;i++))
   do
      factorial=$((factorial * i))
   done
fi

echo "9) Factorial of $1 is: $factorial"
echo


if test $3 -lt 0
then
   primeornot="not prime"
else
   middle=$(expr $3 / 2)
   flag=0

   for ((i=2; i<=middle; i++))
   do
      if test $(expr $3 % $i) -eq 0
      then
         primeornot="not prime"
         flag=1
         break
      fi
   done

   if test $flag -eq 0
   then
      primeornot="prime"
   fi
fi

echo "10) $3 is $primeornot"
echo

echo
echo "End of script"
echo "Implemented by Hanna Rakhsha - 9 – 25 - 2019"

exit 0
