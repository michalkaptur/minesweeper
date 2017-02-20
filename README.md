[![Build Status](https://travis-ci.org/michalkaptur/saper.svg?branch=master)](https://travis-ci.org/michalkaptur/saper)

# saper (minesweeper) engine

## dependencies
  - gtest
  - compiler with c++11 support
  - clang-format

## building
```shell
mkdir build
cd build
cmake ..
make saper
```

## running tests
```shell
make ut
./ut
```

## check formatting
```shell
./tools/is_formatted.sh
```
