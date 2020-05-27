# `bfc`
[![License information](https://img.shields.io/badge/license-MIT-lightgrey.svg)](https://github.com/cabellwg/elizabeth-cabell-fine-art-api/blob/master/LICENSE)
[![Build Status](https://travis-ci.com/cabellwg/bfc.svg?token=LKSsVQYJaBXGxfgSBjEE&branch=master)](https://travis-ci.com/cabellwg/bfc)

`bfc` is a simple Brainfuck compiler written in C.

### Installation

###### Linux with GCC

Ensure that `/usr/local/bin` is in your path and run:

```
$ git clone https://github.com/cabellwg/bfc.git
$ make build
$ cp build/bfc /usr/local/bin/bfc
```

###### MacOS (or Linux with Clang)

Ensure that `/usr/local/bin` is in your path and run:

```
git clone https://github.com/cabellwg/bfc.git
make build cc=clang
cp build/bfc /usr/local/bin/bfc
```

###### Windows

Set up a Linux virtual machine (distro of your choice) and set it to automatically open to fullscreen after login. Follow the instructions for Linux above. Now you can use `bfc` and, as an added bonus, you'll never have to use Windows again!

### Usage

```
bfc bf_src.bf
```

Run `bfc --help` to view a list of available flags.


