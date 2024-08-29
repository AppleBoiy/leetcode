#!/usr/bin/env bash


sol1() {
    awk '{
        if (NR == 10) {
            print $0;
        }
    }' $1
}

sol2() {
    sed -n '10p' $1
}

sol3() {
    while read -r line; do
        if [ $((++i)) -eq 10 ]; then
            echo $line
            break
        fi
    done < $1
}

sol3 file.txt
