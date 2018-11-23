import matplotlib
matplotlib.use("Agg")
import numpy as np
import matplotlib.pylab as plt

archivo=np.genfromtxt("Walk_serial.txt")
plt.hist(archivo,density=True,bins=100,label="Serial")
archivo=np.genfromtxt("Walk_parallel.txt")
plt.hist(archivo,density=True,bins=100,alpha=0.5,label="Parallel")
plt.savefig("walk_comparacion.pdf")
plt.close()
