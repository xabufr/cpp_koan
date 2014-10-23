#!
cmake .
watch -cn 0,5 "make -j4 >> /dev/null && ./bin"

