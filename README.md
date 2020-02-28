[![Build Status](https://travis-ci.org/michalkaptur/minesweeper.svg?branch=master)](https://travis-ci.org/michalkaptur/minesweeper)
[![CircleCI](https://circleci.com/gh/michalkaptur/minesweeper.svg?style=shield)](https://github.com/michalkaptur/minesweeper)

# minesweeper engine

## dependencies
  - compiler with c++14 support
  - clang-format

## building
```shell
mkdir build
cd build
cmake ..
make minesweeper
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
