## FDIC - Dictionary filter for STDIN

### Overview

FDIC will read STDIN and output newline delimited words to stdout if
they are contained in a dictionary file at *~/.config/fdic/dict.txt*

Alternatively, the dictionary can be specified on the command line `./fdic word1 word2 word3`

Basic punctuation should be filtered from the input if they are not in the dictionary.

Punctuation removal from the input can be achieved by piping to tr -d [:punct:]

Unprintable characters can be converted to newlines by piping to `tr -s -c [:print:] "\n"`

Spaces can be converted to newlines with `tr -s " " "\n"`

For example:

``` bash
> cat /dev/urandom |tr -s -c [:alpha:] "\n" |tr [:upper:] [:lower:] |./fdic
```

``` bash
> cat /dev/urandom |tr -s -c [:alpha:] "\n" |tr [:upper:] [:lower:] |./fdic car dog cat
```

### Compilation

``` bash
g++ -std=c++17 -Wall -o fdic fdic.cpp dictionary.cpp
```

### AUR

Download [the AUR snapshot](https://aur.archlinux.org/cgit/aur.git/snapshot/fdic.tar.gz) then extract with:

``` bash
tar xzf fdic[tab]
```

Then build/install with:

```bash
makepkg
pacman -U fdic[tab]
```

Optionally, remove current directory.

If you've cloned the git repo instead of downloading the snapshot, you'll have to bring in the submodule:

``` bash
git submodule init
git submodule update
```

Then `cd AUR` and run the above `makepkg` and `pacman` commands from there.
