#!/bin/bash 

cd ..

FILES=$(find -not -path "*/.*" | grep -E "\.h|\.cpp|\.ino$")

echo "Formatting:"
echo $FILES

clang-format -style=Google -i $FILES

echo "Done."