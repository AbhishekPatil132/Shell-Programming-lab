#!/bin/bash

println(){

clear
echo "1) View the Data In the address Book"
echo "2) Insert the Data In the address book"
echo "3) Delete the Data In the address Book"



}

insert(){

    echo "Enter the name of the address Book "
    read book
    rc=`ls|grep $book | wc -w`
    echo "$rc........."
    if [ $rc -gt 0 ]
    then 
    	echo "Enter email :"
    	read email
    	e=`cat $book| grep $email | wc -w`
    	if [ $e -gt 0 ]
    	then 
    	     	echo "Email is already Existed"
    	else
    	     	echo "Enter Name :"
    		read name
    		echo "Enter Phone no:"
    		read phone
    		echo "$name|$phone|$email">>$book
    		echo "Record inserted"
    		
    	fi
    else
         echo "Address book is not existed "
    fi
}


exitt(){

	echo "If you want to continue Press 1 , for exit press 0 "
	read check
	if [ $check -eq 1 ];then 
		println
		read choice
	elif [ $check -eq "0" ];then
		exit 0
	else
		echo "Your are entered the wrong choice "
	fi
}



delete(){
       
       echo "Enter Book name from where you want to Delete"
       read filename
           rc=`ls| grep $filename | wc -w`
    
       if [ $rc -gt 0 ]
       then 
    	 echo "Enter the Email You want to Delete"
          read email

           if grep -q "$email" "$filename" ; then
             grep -v "$email" "$filename" > "$filename.tmp"
             mv "$filename.tmp" "$filename"
             echo "Record deleted."
           else
             echo "Email not found in the address book."
        fi
    else
        echo "Address book does not exist."
    fi
}


          
          
echo "Hello Guys , Welcome to Jspm Address Book "
println;

echo "Enter your choice "
read choice

while [ $choice -lt 4 ]
	do
		if [ $choice -eq 2 ]; then 
			insert;
			exitt;
		elif [ $choice -eq 3 ]; then
		         delete;
		         exitt; 
		
		else
		     echo "Your option is wrong "
		fi
done
		


