## FDIC - Dictionary filter for STDIN

### Overview

FDIC will read STDIN and output newline delimited words to stdout if they are contained in ~/.config/fdic/dict.txt

Basic punctuation should be filtered from the input if they are not in the dictionary.

Punctuation removal from the input can be achieved by piping to tr -d [:punct:]

Unprintable characters can be converted to newlines by piping to `tr -s -c [:print:] "\n"`

Spaces can be converted to newlines with `tr -s " " "\n"`

For example:

``` bash
> cat /dev/urandom |tr -s -c [:alpha:] "\n" |tr [:upper:] [:lower:] |./fdic
```

### Compilation

``` bash
g++ -Wall -o fdic fdic.cpp 
```
