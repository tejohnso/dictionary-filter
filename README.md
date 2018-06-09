## FDIC - Dictionary filter for STDIN

### Overview

FDIC will read STDIN and output newline delimited words to stdout if they are contained in ~/.config/fdic/dict.txt

Basic punctuation should be filtered from the input if they are not in the dictionary.

Punctuation removal from the input can be achieved by piping to tr -d [:punct:]

Unprintable characters can be removed by piping to `tr -d -c [:print:]`

Spaces can be converted to newlines with `tr -s " " "\n"`

For example:

``` bash
> echo "The car ZZZ999 is red." |fdic
>
``` bash

``` bash
> echo "the car ZZZ999 is red." |tr -d [:punct:] |tr -s " " "\n" |fdic
the
car
is
red
>
``` bash

### Compilation

``` bash
g++ -Wall -o fdic fdic.cpp 
```
