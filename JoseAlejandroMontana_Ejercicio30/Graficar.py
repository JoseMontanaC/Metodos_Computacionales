import numpy as np
import matplotlib.pylab as plt
archivo = np.genfromtxt("Estado_inicial.txt")
X = archivo[:,0]
U = archivo[:,1]
plt.plot(X,U)
for i in range(1,10):
    archivo = np.genfromtxt("Estado_"+str(i)+".txt")
    X = archivo[:,0]
    U = archivo[:,1]
    plt.plot(X,U)
plt.show()
