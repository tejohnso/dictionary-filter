## FDIC - Dictionary filter for STDIN

### Overview

FDIC will read STDIN and output space delimited words to stdout if they are contained in ~/.config/fdic/dict.txt

Basic punctuation should be filtered from the input so that "The car is red." will output all 4 words. Otherwise, "red." is not going to be output because the word red is not space delimited.

Punctuation removal can be achieved by piping to tr -d [:punct:]

For example:

``` bash
> echo "The car ZZZ999 is red." |fdic
The car is>
``` bash

``` bash
> echo "The car ZZZ999 is red." |tr -d [:punct:] |fdic
The car is red>
``` bash

If the input has new line or other unprintable characters, you may want them converted to spaces via `tr -s -c [:print:] " "`

### Compilation

``` bash
g++ -Wall -o fdic fdic.cpp 
```
