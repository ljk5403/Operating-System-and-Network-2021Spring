#!/bin/bash
counter=0
username='tom'
password='123456'
while [ 3 -gt $counter ]
do
  read -p "Username: " usernameInput
  read -p "Password: " passwordInput
  let counter++
  if [ $username = $usernameInput -a $password = $passwordInput ]
  then
    echo "Successfully login!"
    break
  elif [ 3 -eq $counter ]
  then
    echo "3 incorrect password attempts."
  else
    echo "Wrong username or password, try again"
  fi
done
