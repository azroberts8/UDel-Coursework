# CISC220 Dog In Forrest Game

The first project for UD CISC220 - Data Structures is intended for us to familiarize ourselves with C++ and brush up on object-oriented design patterns. This project is a minigame that resembles a maze and minesweeper. A dog enters the maze with a finite amount of health, each move costs the dog health, food is scattered that can increase health, there are hidden traps that can reduce health, and breaking walls/barriers costs health. Make it to the exit point of the maze without depleting the dog's health.

### Authors:
- Andrew Roberts (andrew@azroberts.com)
- Stephen Wiafe

### Committing Guidelines
- Avoid committing directly to master!
- Open a new branch for each new feature using ```git branch <feature-name>``` then ```git checkout <feature-name>```
- Commit often; if it compiles, might as well commit it
- After completing feature branch, switch to master branch ```git checkout master```, pull latest changes ```git pull```, and merge your branch ```git merge <feature-name>```
- After respolving merge conflicts (if any) test that it compiles and runs then commit to master branch ```git commit``` and ```git push```

## Basic Setup

### Mac/Linux (Terminal)
For this project we have prepared a Makefile that that uses GCC to compile for *NIX systems. Make sure you have GCC installed on your system before proceeding with these steps!

To compile and run the program use:
```bash
make run
```

To only compile the program without running use:
```bash
make all
```

To quickly recompile use:
```bash
make rebuild
```

To quickly recompile and run use:
```bash
make rerun
```

To remove the compiled output:
```bash
make clean
```

## How To Play
