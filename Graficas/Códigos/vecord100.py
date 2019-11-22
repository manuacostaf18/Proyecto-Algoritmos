from matplotlib import pyplot as pp
import numpy as np

ejey = ["Heap", "Counting", "Selection", "Bubble", "Insertion", "Quick", "Merge", "Shell", "Gnome", "Cocktail"]
ejex = [8.7590e-5, 2.4440e-4, 1.1380e-4, 1.9500e-6, 3.0000e-6, 9.9716e-4, 1.2913e-4, 1.7940e-5, 2.1500e-6, 2.9600e-6]

pp.rcdefaults()
fig, ax = pp.subplots()

y_pos = np.arange(len(ejey))
ax.barh(y_pos, ejex, color = ("brown", "red", "darkorange", "gold", "yellowgreen", "green", "lightseagreen", "mediumblue", "violet", "pink"))
ax.set_yticks(y_pos)
ax.set_yticklabels(ejey)
ax.set_ylabel("Ordenamientos")
ax.set_xlabel("Tiempo Promedio")
ax.set_title("Vectores Ordenados Tamaño 100")

pp.show()
