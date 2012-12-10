#!/bin/bash
mpirun -np 4 proiect_mpi `cat $1` 2> /dev/null
