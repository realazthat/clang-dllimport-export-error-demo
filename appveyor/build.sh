
set -exv

PROJECT_PATH=$PWD

rm -rf ./build && mkdir -p ./build && cd build

cmake -G"$CMAKE_GENERATOR" .. -DCMAKE_BUILD_TYPE="$CMAKE_BUILD_TYPE" -DCMAKE_VERBOSE_MAKEFILE=1

make
