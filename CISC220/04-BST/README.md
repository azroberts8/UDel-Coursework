# CISC220 Binary Search Tree Project

The third project of the semester in CISC220. For this assignment we will be implementing a basic binary search tree to easily add, remove and search from a list of students and print out their information.

### Authors:
- Andrew Roberts (andrew@azroberts.com)
- John Serino (jhserino@udel.edu)

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
