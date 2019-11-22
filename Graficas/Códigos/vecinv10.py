from matplotlib import pyplot as pp
import numpy as np

ejey = ["Heap", "Counting", "Selection", "Bubble", "Insertion", "Quick", "Merge", "Shell", "Gnome", "Cocktail"]
ejex = [5.630e-6, 2.685e-5, 2.860e-6, 7.250e-6, 1.380e-6, 1.760e-6, 1.440e-5, 2.190e-6, 5.440e-6, 6.010e-6]

pp.rcdefaults()
fig, ax = pp.subplots()

y_pos = np.arange(len(ejey))
ax.barh(y_pos, ejex, color = ("brown", "red", "darkorange", "gold", "yellowgreen", "green", "lightseagreen", "mediumblue", "violet", "pink"))
ax.set_yticks(y_pos)
ax.set_yticklabels(ejey)
ax.set_ylabel("Ordenamientos")
ax.set_xlabel("Tiempo Promedio")
ax.set_title("Vectores Invertidos Tamaño 10")

pp.show()
