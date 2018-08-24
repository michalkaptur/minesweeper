#!/bin/bash
files="$(find src/ -name *.cpp -or -name *.h)"
malformat_count=$(clang-format-4.0 $files -output-replacements-xml | grep -c "<replacement ")
clang-format-4.0 $files -output-replacements-xml
exit $malformat_count

