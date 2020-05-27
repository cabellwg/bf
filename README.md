# `bf`
[![License information](https://img.shields.io/badge/license-MIT-lightgrey.svg)](https://github.com/cabellwg/bf/blob/master/LICENSE)

`bf` is a simple Brainfuck interpreter written in C.

### Installation

###### Linux with GCC

Ensure that `/usr/local/bin` is in your path and run:

```
$ git clone https://github.com/cabellwg/bf.git
$ make build
$ cp build/bf /usr/local/bin/bf
```

###### MacOS (or Linux with Clang)

Ensure that `/usr/local/bin` is in your path and run:

```
git clone https://github.com/cabellwg/bf.git
make build cc=clang
cp build/bf /usr/local/bin/bf
```

###### Windows

Set up a Linux virtual machine (distro of your choice) and set it to automatically open to fullscreen after login. Follow the instructions for Linux above. Now you can use `bf` and, as an added bonus, you'll never have to use Windows again!

### Usage

```
bf bf_src.bf
```

Run `bf --help` to view a list of available flags.


