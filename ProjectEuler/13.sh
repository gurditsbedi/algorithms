#!/usr/bin/env sh
# uses GNU awk and grep
# the nunmbers should be in data.txt file.
awk '{sum += $1}; END {print sum}' data.txt | grep -Eo "^.{10}"
