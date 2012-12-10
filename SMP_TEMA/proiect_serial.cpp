#include <cstring>
#include <iostream>
#include "md5.hpp"
#include "utils.hpp"
#define N 1000000000

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        std::cerr<<"Niciun md5 dat la intrare"<<std::endl;
        return -1;
    }

    std::cout<<"Caut md5 pentru stringul "<<argv[1]<<std::endl;
    for(int i = 0; i < N; i++)
    {
        if(md5(toString(i)) == std::string(argv[1]))
        {
            std::cout<<"L-am gasit "<<i<<std::endl;
            return 0;
        }
    }
    std::cout<<"Nu a fost gasit";
}
