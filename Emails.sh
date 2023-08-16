#!/bin/bash

Insert() {
    echo "Enter Book name: "
    read book

    res=`ls | grep $book | wc -w`

    if [ $res -gt 0 ]
     then
        echo "Book exists"
        echo "Enter email"
        read email
        len=`cat $book | grep $email | wc -w`
        if [ $len -gt 0 ]
         then
            echo "Email exists!"
        else
            echo "Enter Firstname and Lastname"
            read fn ln
            record= echo "$fn $ln $email"
            echo $record >> $book
            echo "Record inserted"
        fi
    else
        echo "Address book doesn't exist!"
    fi
}

Insert;
