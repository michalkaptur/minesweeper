#!/bin/bash
files="$(find src/ -name *.cpp -or -name *.h)"
malformat_count=$(clang-format $files -output-replacements-xml | grep -c "<replacement ")
clang-format -i $files
git status
git diff
clang-format --version
exit $malformat_count

