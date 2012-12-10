#define __MPI__
#include <iostream>
#include "mpi.h"
#include "md5.hpp"
#include "utils.hpp"
#include <cstdlib>
int main(int argc, char* argv[]) {
    if(argc == 1) {
        std::cerr<<"Primul parametru trebuie sa fie hash-ul problemei";
        return 0;
    }
    int n = 1000000000, numprocs, myid;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    int my_first = myid * n / numprocs;
    int my_last = (myid + 1) * n/numprocs;
    if(myid == 0)
        std::cout<<"Caut md5 pentru stringul "<<argv[1]<<std::endl;

    for (int i = my_first; i < my_last; i++)
    {
        if(md5(toString(i)) == std::string(argv[1]))
        {
            std::cout<<"L-am gasit "<<i<<std::endl;
            exit(0);
        }

    }

    MPI_Finalize();
    std::cout<<"Rezultatul nu a fost gasit ";
    return 0;
}
