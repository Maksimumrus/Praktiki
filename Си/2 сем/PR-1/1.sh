#!/bin/bash

DIR="$1"

if [ ! -d "$DIR" ]; then
    echo "Неверный путь"
    exit 1
fi

for i in {1..5}; do
    mkdir -p "./PR-1/grade/$i"
done

for student in "$DIR"/*; do
    if [ -d "$student" ]; then
        name=$(basename "$student")
        echo "Студент: $name"

        txt=("$student"/*.txt)

        if [ -e "${txt[0]}" ]; then
            for file in "${txt[@]}"; do
                less -F "$file"
            done
        else
            echo "Файлы не обнаружены"
            continue
        fi

        while true; do
            read -p "Введите оцнеку для студена $name от 1 до 5: " grade

            if [[ "$grade" =~ ^[1-5]$ ]]; then
                break;
            else
                echo "Неправильная оценка, введите другую"
            fi
        done    

        mv "$student" "./PR-1/grade/$grade/$name"   
    fi
done 