all: proiect_serial proiect_mpi proiect_pthread proiect_openmp
proiect_serial: proiect_serial.cpp md5.cpp utils.cpp
	g++ $^ -o proiect_serial
proiect_mpi: proiect_mpi.cpp md5.cpp utils.cpp
	mpiCC $^ -o proiect_mpi
proiect_pthread: proiect_pthread.cpp md5.cpp utils.cpp
	g++ -fpermissive $^ -pthread -o proiect_pthread
proiect_openmp: proiect_openmp.cpp md5.cpp utils.cpp
	g++ -fopenmp $^ -o proiect_openmp
clean:
	rm -f proiect_serial proiect_mpi proiect_pthread proiect_openmp
run: proiect_serial proiect_mpi
	./proiect_serial
	mpirun -np 4 proiect_mpi
	./proiect_pthread
	./proiect_openmp
