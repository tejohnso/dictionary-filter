## FDIC - Dictionary filter for STDIN

### Overview

FDIC will read STDIN and output newline delimited words to stdout if
they are contained in a dictionary file at *~/.config/fdic/dict.txt*
or *~/snap/fdic/common/dict.txt*

Alternatively, the dictionary can be specified on the command line `./fdic word1 word2 word3`

Basic punctuation should be filtered from the input if they are not in the dictionary.

Punctuation removal from the input can be achieved by piping to tr -d [:punct:]

Unprintable characters can be converted to newlines by piping to `tr -s -c [:print:] "\n"`

Spaces can be converted to newlines with `tr -s " " "\n"`

For example:

``` bash
> cat /dev/urandom |tr -s -c [:alpha:] "\n" |tr [:upper:] [:lower:] |fdic
```

``` bash
> cat /dev/urandom |tr -s -c [:alpha:] "\n" |tr [:upper:] [:lower:] |fdic car dog cat
```

### Installation

#### AUR

Download [the AUR snapshot](https://aur.archlinux.org/cgit/aur.git/snapshot/fdic.tar.gz) then extract and build:

``` bash
curl -s "https://aur.archlinux.org/cgit/aur.git/snapshot/fdic.tar.gz" |tar xz --directory=/tmp
cd /tmp/fdic
makepkg
sudo pacman -U fdic[tab]
```

#### SNAP

``` bash
sudo snap install fdic
```

### Compilation from source

``` bash
g++ -std=c++17 -O3 -Wall -o fdic fdic.cpp dictionary.cpp
```
