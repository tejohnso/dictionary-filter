## FDIC - Dictionary filter for STDIN

### Overview

FDIC will read STDIN and output space delimited words to stdout if they are contained in ~/.config/fdic/dict.txt

Basic punctuation will be filtered from the input so that "The car is red." will output all 4 words.

For example:

``` bash
> echo "The car ZZZ999 is red." |fdic
The car is red >
``` bash


### Compilation

``` bash
g++ -Wall -o fdic fdic.cpp 
```
