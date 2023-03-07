#!/bin/bash

echo "FUNCTIONNAL TEST STARTED"

cat tests/groundhog_example_input.csv | ./groundhog 7 > tests/functionnal_res.txt

res = `diff tests/groundhog_example_output.csv tests/functionnal_res.txt`

if res 
    then echo "INVALID OUTPUT"
    exit
fi

echo "FUNCTIONNAL TEST ENDED"