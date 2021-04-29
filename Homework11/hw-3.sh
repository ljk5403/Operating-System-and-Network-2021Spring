#!/usr/bin/env bash
while :
do
    clear
    echo -------------------------------
    echo '    1: chmod'
    echo '    2: cat'
    echo '    3: rename'
    echo '    q: exit manu'
    echo -------------------------------
    read choice
    case $choice in
        1)
            read filename
            if [ -a $filename ]
            then
                chmod +x $filename
                ls -la $filename|cut -f 1 -d " "
            else
                echo "$filename does not exist"
            fi
        ;;
        2)
            read filename
            if [ -r $filename ]
            then
                cat $filename
            else
                touch $filename
            fi
        ;;
        3)
            read sourceName targetName
            if [ -a $sourceName ]
            then
                mv -f $sourceName $targetName
            else
                echo 'Source file does not exist'
            fi
        ;;
        q)
            echo 'quit'
            break
        ;;
        *)
            echo 'input error'
        ;;
    esac
    echo 'Press return to contenue...'
    read DUMMY
done