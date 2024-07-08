echo "Enter a number"
read num

flag=0

for ((i=2; i<num; i++))
do
  if (( num % i == 0 ))
  then 
    flag=1
    break
  fi
done

if (( num == 1 ))
then
  echo "The number is not prime"
elif (( flag == 1 ))
then 
  echo "The number is not prime"
else
  echo "The number is prime"
fi
