# import matplotlib
# matplotlib.use("Agg")
import numpy as np
import matplotlib.pylab as plt
archivo = np.genfromtxt("./Parallel_Non_linear/Estado_inicial.txt")
X = archivo[:,0]
U = archivo[:,1]
plt.plot(X,U,label="Parallel")
# for i in range(1,10):
archivo = np.genfromtxt("./Parallel_Non_linear/Estado_10.txt")
X = archivo[:,0]
U = archivo[:,1]
plt.plot(X,U,label="Parallel")

archivo = np.genfromtxt("./Serial_Non_linear/Estado_inicial.txt")
X = archivo[:,0]
U = archivo[:,1]
plt.plot(X,U,label="Serial",alpha=0.5)
# for i in range(1,10):
archivo = np.genfromtxt("./Serial_Non_linear/Estado_10.txt")
X = archivo[:,0]
U = archivo[:,1]
plt.plot(X,U,label="Serial",alpha=0.5)
plt.legend()
# plt.savefig("Nonlinear_comparacion.pdf")
# plt.close()
plt.show()
