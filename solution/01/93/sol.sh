#!/usr/bin/env bash

# file.txt:
# 987-123-4567
# 123 456 7890
# (123) 456-7890

cat "file.txt" | grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$'