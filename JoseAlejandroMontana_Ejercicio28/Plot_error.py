import numpy as np
import matplotlib.pylab as plt
import sys

datos=sys.argv[1]
archivo=np.genfromtxt(datos)
x=archivo[:,1]
y=archivo[:,0]
a={}
for i in range(len(x)):
    a[x[i]]=y[i]
X=[]
Y=[]
for i in sorted(a.keys()):
    X.append(i)
    Y.append(a[i])
X=np.array(X)
Y=np.array(Y)
exact= 155.0/6.0
error=np.abs(exact-Y)/exact * 100
plt.figure(figsize=(7,5))
plt.xscale("log")
plt.yscale("log")
plt.plot(X,error,color="firebrick")
plt.scatter(X,error,color="navy")
plt.xlabel("Numero de puntos N")
plt.ylabel("Porcentaje de error")
plt.title("Error en funcion de la particion N")
plt.savefig("Error.pdf")
plt.savefig("Error.png")
plt.tight_layout()
plt.close()


