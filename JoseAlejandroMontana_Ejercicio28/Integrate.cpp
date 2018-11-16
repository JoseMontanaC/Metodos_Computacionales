#include<iostream>
#include<cmath>
#include<vector>
#include<random>
#include "mpi.h"

double function_to_integrate(double *x);
const double lowerLimit = 0.0;
const double upperLimit = 1.0;
const int exponente = 10;

int main(int argc, char *argv[])
{
  std::mt19937 generator(1);
  int dest, size, rank, tag;
  int N = atoi(argv[1]);
  double Lambda = 1.0;
  MPI_Status status;
  double area, punto, heigth, width, total, range, lower;
  double lista[exponente];
  
  // Inicializar
  for (int ii = 0; ii <  exponente; ii++)
    {
      lista[ii]=0.0; 
    }
  
  // /*MPI setup*/
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // /* Adjust problem size for sub-process */
  range = (upperLimit - lowerLimit) / size;
  width = range /(double) N;
  // lower = lowerLimit + range*rank;

  area=0.0;
  std::uniform_real_distribution<double> number(lowerLimit,upperLimit);
  
  for (int ii = 0; ii < N; ++ii)
    {
      for(int jj=0; jj< exponente;++jj)
	{
	  lista[jj]= number(generator);
	}
      heigth = function_to_integrate(lista);
      area += heigth*width;
    }

  /* Collect info and print results */
  tag = 0;
  if (0 == rank)
    { /* Master */
      total = area; 
      for (int src = 1; src < size; ++src)
  	{
  	  MPI_Recv(&area, 1, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, &status);
  	  total += area;
  	}
      fprintf("%f \n",total)
      // fprintf(stderr, "The area from %g to %g is : %25.16e\n", lowerLimit,upperLimit, total);
    }
  else
    { /* slaves only send */
      dest = 0; 
      MPI_Send(&area, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
    } 
  
  /* finish */
  MPI_Finalize();

  
  return 0;



  
}

double function_to_integrate(double *x)
{
  double cuadratic=0.0;
  for(int ii=0; ii<sizeof(x);ii++)
    {
      cuadratic += x[ii];
    }
  cuadratic = cuadratic*cuadratic;
  return cuadratic;
}
