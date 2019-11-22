from matplotlib import pyplot as pp
import numpy as np

ejey = ["Heap", "Counting", "Selection", "Bubble", "Insertion", "Quick", "Merge", "Shell", "Gnome", "Cocktail"]
ejex = [9.932100e-4, 2.773860e-3, 3.420000e-3, 2.098000e-5, 4.090000e-5, 2.870356e-2, 1.408150e-3, 2.671700e-4, 1.960000e-5, 2.575000e-5]

pp.rcdefaults()
fig, ax = pp.subplots()

y_pos = np.arange(len(ejey))
ax.barh(y_pos, ejex, color = ("brown", "red", "darkorange", "gold", "yellowgreen", "green", "lightseagreen", "mediumblue", "violet", "pink"))
ax.set_yticks(y_pos)
ax.set_yticklabels(ejey)
ax.set_ylabel("Ordenamientos")
ax.set_xlabel("Tiempo Promedio")
ax.set_title("Vectores Ordenados Tamaño 1000")

pp.show()
