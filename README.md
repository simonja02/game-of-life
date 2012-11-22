# Game of Life

This is another implementation of Conway's famous Game of Life.

## Introduction

This is a C implementation of Conway's Game of Life. The goal is to utilize
GTK's library to create a user interface. At a later date the code will be
extended to run a smaller map and control an LED matrix via an AVR
microcontroller.

## Building and Usage

To build the program, compile all the C files using your favourite compiler. (makefile forthcoming).

Currently the program is written to load initial map data from a file, whose name is specified as the command line argument.

### Map File Specifications
The first line is simply the map's height and width, followed by a newline. These values are currently ignored.

Following come the x and y pairs of alive cells, with each pair separated by a newline.

## Disclaimer

This project has been undertaken to learn about and practice C programming, as
well as the use of GitHub.
Therefore there may be mistakes and bugs in the code. Use of the code or the
program is at the user's risk. 
