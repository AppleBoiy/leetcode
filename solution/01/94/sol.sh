#!/usr/bin/env bash

# file.txt:
#name age
#alice 21
#ryan 30

# Output:
#name alice ryan
#age 21 30

awk '{
    for (i = 1; i <= NF; i++) {
        if (NR == 1) {
            res[i] = $i;
        } else {
            res[i] = res[i] " " $i;
        }
    }
} END {
    for (i = 1; i <= NF; i++) {
        print res[i];
    }
}' file.txt
