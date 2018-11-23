import numpy as np
import matplotlib.pylab as plt

archivo=np.genfromtxt("Walk.txt")
plt.hist(archivo,normed=True,bins=100)
plt.show()
