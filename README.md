# wc

> **wc** (short for word count) is a command in Unix, Plan 9, Inferno, and Unix-like operating systems. The program reads either standard input or a list of computer files and generates one or more of the following statistics: newline count, word count, and byte count. If a list of files is provided, both individual file and total statistics follow.

☝🏽[wikipedia](https://www.wikiwand.com/en/Wc_(Unix))

### TODO
- [x] support the command line option **-c** and outputs the number of bytes in a file.
- [x] support the command line option **-l** that outputs the number of lines in a file.
- [x] support the command line option **-w** that outputs the number of words in a file
- [ ] support the command line option **-m** that outputs the number of characters in a file. If the current locale does not support multibyte characters this will match the -c option.
- [ ] support the default option - i.e. no options are provided, which is the equivalent to the **-c**, **-l** and **-w** options.
- [ ] support being able to read from standard input if no filename is specified.

### How to run the program

```console
make          # create executable
./bin/wc -h   # display manual or help message
make clean    # always clean after yourself 😃
```


For reference: [Coding Challenge # 1 - Build your own wc](https://codingchallenges.substack.com/p/coding-challenge-1).
