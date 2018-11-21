#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Flux(double *flux,double *u,int n);

/* void Lax(double *u,double t_max, double delta_t, double delta_x); */
int main(int argc, char ** argv)
{
  /* Archivo para escribir */
  FILE *out;
  /* Inicializar */
  int L = 4;
  double delta_x = 0.05;
  int n = L/delta_x +1;
  double *x = (double *) malloc(sizeof(double)*n);
  for( int ii=0; ii < n;ii++)
    {
      x[ii] = ii*0.05;
      /* printf("%.5f \n",x[ii]); */
    }
  
  double *u = (double *) malloc(sizeof(double)*n);
  /* double *aux = (double *) malloc(sizeof(double)*n); */
  for( int ii=0; ii < n;ii++)
    {
      if(x[ii]<2.0)
	{
	  u[ii] = 1.0;
	}
      else
	{
	  u[ii] = 0.0;
	}
    }
  
  /* Se escribe el archivo con las condiciones iniciales */
  
  if(!(out = fopen("Inicial.txt", "w"))){
    fprintf(stderr, "Problema abriendo el archivo\n");
    exit(1);
  }
  for(int i=0;i<n;i++){
    fprintf(out, "%.5f  %.5f\n", x[i],u[i]);
  }

  
  /* Se definen la variables a utilizar para el metodo */
  double t_max=0.45, delta_t=0.015;
  int N_t = t_max/delta_t;

  /* Arreglos para guardar el flujo y la configuracion final */
  double *F = (double *) malloc(sizeof(double)*n);
  double *u_final = (double *) malloc(sizeof(double)*n);
  
  /* Se ponen las mismas condiciones de contorno */
  u_final[n-1]=u[n-1];
  u_final[0]=u[0];
  for(int ii= 0; ii<N_t ;ii++)
    {
      Flux(F,u,n);
      for(int jj = 1; jj< n-1;jj++)
	{
	  u_final[jj] = 0.5*(u[jj+1] +u[jj-1])
	    - 0.5*(delta_t/delta_x)*(F[jj+1]-F[jj-1]);;
	  /* u_final[jj] -= 0.5*(delta_t/delta_x)*(F[jj+1]-F[jj-1]); */
	  u[jj] = u_final[jj];
	  /* printf("%.5f terminacon %.5f \n",u[jj],u_final[jj]); */
	}
    }
  /* Se escribe el estado final */

  if(!(out = fopen("Final.txt", "w"))){
    fprintf(stderr, "Problema abriendo el archivo\n");
    exit(1);
  }
  /* for(int i=0;i<n;i++){ */
  /*   fprintf(out, "%.5f  %.5f\n", x[i],u[i]); */
  /* } */
  
  for(int i = 0;i<n; i++)
    {
      fprintf(out,"%.5f  %.5f \n",x[i],u_final[i]);
    }
  
  free(u);
  free(F);
  free(x);
  free(u_final);
  /* free(aux); */
  return 0;
}

void Flux(double *flux,double *u,int n)
{
  
  for( int ii=0; ii < n;ii++)
    {
      flux[ii] = 0.5 *u[ii]*u[ii];
    }
}

/* void Lax(double *u,double t_max, double delta_t, double delta_x) */
/* { */
/*   int N_t = t_max/t_delta_t; */
/*   double *flux = (double *) malloc(sizeof(double)*n); */
/*   for(int jj=0; jj< N_t; jj++) */
/*     { */
      
/*     } */
/*   free(flux) */
/* } */
