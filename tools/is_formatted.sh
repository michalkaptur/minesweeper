#!/bin/bash
files="$(find src/ -name *.cpp -or -name *.h)"
malformat_count=$(clang-format $files -output-replacements-xml | grep -c "<replacement ")
exit $malformat_count

