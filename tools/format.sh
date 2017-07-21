#!/bin/bash
files="$(find src/ -name *.cpp -or -name *.h)"
clang-format-4.0 -i $files

