import numpy as np
import matplotlib.pylab as plt
import sys

datos=sys.argv[1]
archivo=np.genfromtxt(datos)
x=archivo[:,1]
y=archivo[:,0]
exact= 155.0/6.0
error=np.abs(exact-y)/exact * 100
plt.figure(figsize=(7,4))
plt.xscale("log")
plt.plot(x,error,color="firebrick")
plt.scatter(x,error,color="navy")
plt.xlabel("Numero de puntos N")
plt.ylabel("Porcentaje de error")
plt.title("Error en funcion de la particion N")
plt.tight_layout()
plt.show()
# plt.savefig("Histogram.pdf")
# plt.show()

