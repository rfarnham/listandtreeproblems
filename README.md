# Intro
Solutions to linked list problems and tree list recursion problem found in http://cslibrary.stanford.edu/105/LinkedListProblems.pdf and http://cslibrary.stanford.edu/109/TreeListRecursion.pdf

The repo also includes the PDFs themselves.

# Building and Running
Makefile is provided.

```
$ make main
cc -Wall -Werror -I. -c -o obj/main.o main.c
cc -Wall -Werror -I. -c -o obj/utils.o utils.c
cc -Wall -Werror -I. -o bin/main obj/main.o obj/utils.o
$ bin/main
```

```
$ make treelist
cc -Wall -Werror -I. -o bin/treelist treelist.c
$ bin/treelist
```

```
$ make clean
rm obj/*.o bin/*
```
