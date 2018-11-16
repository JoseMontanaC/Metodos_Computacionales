import numpy as np
import matplotlib.pylab as plt
import sys

def exp(x,Lambda=1):
    return Lambda*np.exp(-Lambda*x)
datos=sys.argv[1]
Lambda = float(sys.argv[2])

archivo=np.genfromtxt(datos)
a=archivo
x = np.linspace(0,10.0*1.0/Lambda**2)
plt.plot(x,exp(x,Lambda))
plt.hist(a,bins=50,density=True)
# plt.savefig("Histogram.pdf")
plt.show()
