#  0x16. C - Simple Shell

<p align="center">
    <img src="https://www.holbertonschool.com/holberton-logo.png"/>
</p>

This repository contains the files for Holberton's simple_shell project. This project contains the source code necessary to run a simple UNIX command line interpreter.

# Description

simple_shell is a command line interpreter, or shell, in the traditions of the first Unix shell written by Ken Thompson in 1971.Remember that it is the command interpretor in a operating system such as Unix or linux,This shell includes basic functionality found in the traditional Unix shell.

## First steps

You can get a copy of the project, cloning from the repository with:
```
https://github.com/Gdsoto/simple_shell.git
```

## Developed with
- Programming languaje: C.
- Editor: Vim / Emacs
- Compiler: gcc 4.8.4

## File Structure
These are the files with the custom funtions and system calls, each one contains a brief description:

|   ***File***    |  ***Description***                   |
|---------------|---------------------------------------|
|  [`holberton.h`](./holberton.h)	|  Header file with the prototypes	|
|  [`man_1_simple_shell`](./man_1_simple_shell)  | Manual Page	|
|  [`README.md`](./README.md)  | Project description |
|  [`AUTHORS`](./AUTHORS)  | List of contributors |
|  [pending others files]  | xxxxxxx |

## How to use
After cloning the repository, we will use gcc to compile the project.

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
After compiling, there will be an **hsh** file and we execute it with the command.

```
./hsh
```
## Example

Interactive Mode:

In interactive mode input is accepted from character input, as follow:
```
./hsh
    $ ls
    hsh main.c shell.c
    $
```

Non-Interative Mode:

In non-interactive mode, the shell is run from commands being piped in, as follow:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```

## Features
- [ ] handle commands
- [ ] use the PATH
- [ ] implements builtins
- [ ] handle special characters
- [ ] use exit
- [ ] handle commands with arguments

## Project structure

General Flow Chart:

![Proyect flow chart](https://i.ibb.co/kxYxPL3/Flowchart-Shell.png "Flow Chart")

## AUTHORS
* Diana Ayala
* Sergio Monroy
* Gerson Soto
