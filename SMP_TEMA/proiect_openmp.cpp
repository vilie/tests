#define __OPENMP__
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "md5.hpp"
#include "utils.hpp"
#include <omp.h>
#define N 1000000000

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        std::cerr<<"Niciun md5 dat la intrare"<<std::endl;
        return -1;
    }

    std::cout<<"Caut md5 pentru stringul "<<argv[1]<<std::endl;
    std::string stringCautat = std::string(argv[1]);
    #pragma omp parallel for schedule(static, N/4)
    for(int i = 0; i < N; i++)
    {
            if(md5(toString(i)) == stringCautat)
            {
                std::cout<<"Threadul "<<omp_get_thread_num()<<". L-am gasit "<<i<<std::endl;
                exit(0);
            }
    }
    //std::cout<<"Nu a fost gasit";
}
