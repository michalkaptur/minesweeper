#!/bin/bash
files="$(find src/ -name *.cpp -or -name *.h)"
clang-format -i $files

