#!/bin/bash
NUM_TESTS=$1
if [[ -z "$1" ]]; then
  NUM_TESTS=25
fi

cd `dirname "$0"`

rm -f *.test-cmp
rm -f *.test-in

for (( i=0; i < $NUM_TESTS; ++i)); do
  touch echo$i.test-in
  touch echo$i.test-cmp

  string=`cat /dev/urandom | tr -dc 'a-zA-Z0-9 ' | fold -w 32 | head -n 1`
  echo -n "echo " >> echo$i.test-in
  echo $string >> echo$i.test-in
  echo $string >> echo$i.test-cmp
done
