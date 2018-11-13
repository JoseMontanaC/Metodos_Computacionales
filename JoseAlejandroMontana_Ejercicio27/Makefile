CXX = mpicc
CXX_2 = mpirun

.PHONY: all #se utiliza este target para que corra todos los comandos que se desean 

all: todo

todo: output

output: Hello.x MPI_Send_Recv.x
	$(CXX_2) -np 20 	Hello.x
	$(CXX_2) -np 20 	MPI_Send_Recv.x

Hello.x: Hello_world_MPI.c
	$(CXX) -o Hello.x Hello_world_MPI.c

MPI_Send_Recv.x: MPI_Send_Recv.c	
	$(CXX) -o MPI_Send_Recv.x MPI_Send_Recv.c


clean:
	rm *.x
