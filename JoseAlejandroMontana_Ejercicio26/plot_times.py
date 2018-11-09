import numpy as np
import matplotlib.pylab as plt

archivo= np.genfromtxt("Tiempos.txt")
div=archivo[:,0]
times = archivo[:,1]
D={}
for i in range(len(div)):
    if div[i] in D:
        D[div[i]].append(times[i])
    else:
        D[div[i]] = [times[i]]
X=[]
Y=[]
Y_err=[]
yy=[]
for i in sorted(D.keys()):
    Y.append(np.mean(D[i]))
    X.append(i)
    Y_err.append(np.std(D[i]))
    yy.append(np.sum(D[i]))
 
X=np.array(X)
Y=np.array(Y)
Y_err=np.array(Y_err)
# los datos estan el microsegundo, entonces lo pasamos a mili multiplicando por 10^-3
plt.figure(figsize=(8,4))
plt.errorbar(X,Y,Y_err,color="firebrick")
plt.scatter(X,Y,color="navy")
# plt.plot(X,Y)
plt.title("Tiempo del algoritmo en funcion de la particion")
plt.xlabel("Particion")
plt.ylabel("Tiempo de computo")
plt.ticklabel_format(style="sci",axis="y",scilimits=(0,3))
plt.tight_layout()
plt.savefig("Grafica_tiempo.pdf")
plt.close()
plt.figure(figsize=(8,4))
plt.plot(X,yy,color="slateblue")
plt.scatter(X,yy,color="firebrick")
plt.title("Tiempo total del algoritmo en funcion de la particion")
plt.xlabel("Particion")
plt.ylabel("Tiempo total de computo")
plt.ticklabel_format(style="sci",axis="y",scilimits=(0,3))
plt.tight_layout()
plt.savefig("Graf_tiempo_total.pdf")
plt.close()
