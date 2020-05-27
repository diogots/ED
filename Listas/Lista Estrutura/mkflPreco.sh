#!/bin/bash
gcc -c listaEst.c
gcc -c preco.c
gcc -o precos listaEst.o preco.o
