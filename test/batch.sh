#!/bin/bash
address[0]="127.0.0.1"
address[1]="239.0.0.1"
for i in `seq 0 300`; do
idx=$(( ( RANDOM % 2 ) ))
./client udp:${address[$idx]}:23456 &
done
