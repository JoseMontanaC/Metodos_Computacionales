#include<iostream>
#include<cmath>
#include<vector>
#include<random>
#include "mpi.h"

double func_def(double x);
double function(double x, double mu, double sigma);
double exponential_dist(double x, double Lambda);
void Metropolis(double *lista, int N,double Lambda);
// void Met(double *lista, int N,double mu, double sigma);
/* double Int_montecarlo(int size); */
const double lowerLimit = 0.0;
const double upperLimit = 1.0;

int main(int argc, char *argv[])
{
  std::mt19937 generator(1);
  int dest, size, rank, tag;
  int N = atoi(argv[1]);
  double Lambda = 1.0;
  // MPI_Status status;
  double area, punto, heigth, width, total, range, lower;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  /* Adjust problem size for sub-process */
  range = (upperLimit - lowerLimit) / size;
  width = range / N;
  lower = lowerLimit + range*rank;

  area=0.0;
  for (int ii = 0; ii < N; ++ii)
    {
      punto = lower + ii*width + width/2.0;
      heigth = func_def(punto);
      area = area + width*heigth;
    }

  /* Collect info and print results */
  tag = 0;
  if (0 == processId)
    { /* Master */
      total = area; 
      for (src = 1; src < noProcesses; ++src)
	{
	  MPI_Recv(&area, 1, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, &status);
	  total += area;
	}
      fprintf(stderr, "The area from %g to %g is : %25.16e\n", lowerLimit, upperLimit, total);
    }
  else
    { /* slaves only send */
      dest = 0; 
      MPI_Send(&area, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
    } 
  
  /* finish */
  MPI_Finalize();
  // std::exponential_distribution<double> exp(Lambda);
  // for(int i = 0; i<= N;i++)
  //   {
  //     // std::cout<< 1/(N-1)<<std::endl;
  //     integral +=  func_def(exp(generator))/(double) N;
  //     // std::cout<< func_def(distribution[i])/(double)  (N-1)<<"   "<<func_def(distribution[i])/(N-1)<<"  "<<distribution[i]<<std::endl;
      
  // //     std
  //   }
  // std::cout<<"La integral es: "<<integral<<std::endl;
  // std::cout<<"con error "<<std::fabs(integral-0.5)/0.5 *100<<"%"<<std::endl;
  return 0;



  
  // int N_prime = 5.0*N/4.0;

  // ------------- Tentativa que no funciono para hacer con un montecarlo----
   // double lista[N_prime];
  // Inicializar
  // for (int ii = 0; ii < N_prime; ii++) {
  //   lista[ii]=0.0; 
  // }
  // Metropolis(lista,N,Lambda);
 
  
  // int length = N_prime*0.8;
  // std::vector<double> distribution(length);
  
  // for(int ii= N_prime-length ;ii<N_prime; ii++)
  //   {
  //     distribution[ii-N_prime+length] = lista[ii];
  //     // std::cout<<exp(generator)<<std::endl;
  //     // std::cout<<distribution[ii-N_prime+length]<<std::endl;
  //     // printf("%.16f \n",distribution[ii-N+length]);
  //   }

 
}


double func_def(double x)
{
  return sin(x);
}


double function(double x, double mu, double sigma)
{
  double gauss = (1.0/(sqrt(2.0*M_PI*sigma*sigma)))*exp(-(x-mu)*(x-mu)/(2.0*sigma*sigma));
  return gauss;
}
double exponential_dist(double x, double Lambda)
{
  return Lambda*exp(-x*Lambda);
}
void Metropolis(double *lista, int N,double Lambda)
{
  std::mt19937 generator(1);
  std::uniform_real_distribution<double> number(0.0,1.0);
  // std::uniform_real_distribution<double> number2(0, 10);
  std::normal_distribution<double> Noise(0.0, Lambda);
  double propuesta = 0.0;
  lista[0] = number(generator);
  // Monte Carlo method

  for(int ii=1 ;ii<N; ii++)
    {
      propuesta = 100.0*number(generator);
      // propuesta = lista[ii-1] + Noise(generator);
      double ratio = exponential_dist(propuesta,Lambda)/exponential_dist(lista[ii-1],Lambda);
      double r = std::min(1.0,ratio);
      double alpha = number(generator);
      // std::cout<<propuesta<<"  "<<exponential_dist(propuesta,Lambda)/exponential_dist(lista[ii-1],Lambda)<<std::endl;
      if(alpha < r)
	{
	  lista[ii] = propuesta;
	  continue;
	}
      
      else
	{
	  lista[ii] = lista[ii-1];
	  continue;
	}
    }
}
// void Met(double *lista,int N,double mu, double sigma)
// {
//   std::mt19937 generator(1);
//   std::uniform_real_distribution<double> number(0.0,1.0);
//   std::normal_distribution<double> Noise(0.0, 1.0);
//   double propuesta = 0.0;
//   lista[0] = number(generator);
//   // Monte Carlo method
//   for(int ii=1 ;ii<N; ii++)
//     {
//       propuesta = lista[ii-1] + Noise(generator);
//       double ratio = function(propuesta,mu,sigma)/function(lista[ii-1],mu,sigma);
//       double r = std::min(1.0,ratio);
//       double alpha = number(generator);
      
//       if(alpha < r)
// 	{
// 	  lista[ii] = propuesta;
// 	  continue;
// 	}
      
//       else
// 	{
// 	  lista[ii] = lista[ii-1];
// 	  continue;
// 	}
//     }
  
// }
