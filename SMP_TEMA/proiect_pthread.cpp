#define __PTHREADS__
#define NUMTHRDS 4
#include <iostream>
#include <cstdlib>
#include "md5.hpp"
#include "utils.hpp"

int n = 1000000000;
std::string g_stringCautat;
pthread_t thds[NUMTHRDS];
pthread_mutex_t mutexx;
void *dotprod(void *arg)
{
    int myid, i, my_first, my_last;
    myid = (int) arg;
    my_first = myid * n/NUMTHRDS;
    my_last = (myid + 1) * n/NUMTHRDS;
    for (i = my_first; i < my_last; i++)
    {
        if(md5(toString(i)) == g_stringCautat)
        {
            std::cout<<"L-am gasit "<<i<<std::endl;
            exit(0);
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cerr<"Primul parametru este invalid ";
        return 0;
    }
    std::cout<<"Caut md5 pentru stringul "<<argv[1]<<std::endl;

    int status;
    std::string stringCautat = std::string(argv[1]);
    g_stringCautat = stringCautat;
    pthread_attr_t attr;
    pthread_mutex_init(&mutexx, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for(int i = 0; i < NUMTHRDS; i++)
        pthread_create(&thds[i], &attr, dotprod, (void *) i);

    pthread_attr_destroy(&attr);
    for (int i = 0; i<NUMTHRDS; i++)
        pthread_join( thds[i], (void **)&status);

    std::cout<<"Rezultatul nu a fost gasit "<<std::endl;
    pthread_mutex_destroy(&mutexx);
    pthread_exit(NULL);
}
