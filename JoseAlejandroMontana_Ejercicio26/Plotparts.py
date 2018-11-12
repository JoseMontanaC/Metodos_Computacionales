import numpy as np
import matplotlib.pylab as plt

a = range(10,110,10)
X=np.array([])
Y_err=np.array([])
for i in a:
    archivo = np.genfromtxt("./Part_"+str(i)+"/tiempos.txt")
    x=archivo
    x_mean=archivo.mean()
    y=archivo.std()
    X=np.append(X,x_mean)
    Y_err=np.append(Y_err,y)
plt.yscale("log")
plt.plot(a,X)
plt.errorbar(a,X,Y_err)
plt.show()
