#include <stdio.h>
#include <cmath>
#include <random>
#include <mpi.h>
int main (int argc, char *argv[])
{
  int rank, size;
  int n = atoi(argv[1]);
  int N = atoi(argv[2]);
  double mu = atof(argv[3]);
  double sigma = atof(argv[4]);
  std::mt19937 generator(1);
  std::normal_distribution<double> Noise(mu, sigma);
  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  printf("numero aleatorio de  %d of %d %f\n", rank, size, Noise(generator) );

  MPI_Comm_size (MPI_COMM_WORLD, &size);
  MPI_Finalize();
