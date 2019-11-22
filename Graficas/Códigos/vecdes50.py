from matplotlib import pyplot as pp
import numpy as np

ejey = ["Heap", "Counting", "Selection", "Bubble", "Insertion", "Quick", "Merge", "Shell", "Gnome", "Cocktail"]
ejex = [3.5620e-5, 1.1883e-4, 4.1780e-5, 9.6610e-5, 1.0150e-5, 1.8070e-5, 8.6880e-5, 1.9840e-5, 5.9410e-5, 8.8410e-5]

pp.rcdefaults()
fig, ax = pp.subplots()

y_pos = np.arange(len(ejey))
ax.barh(y_pos, ejex, color = ("brown", "red", "darkorange", "gold", "yellowgreen", "green", "lightseagreen", "mediumblue", "violet", "pink"))
ax.set_yticks(y_pos)
ax.set_yticklabels(ejey)
ax.set_ylabel("Ordenamientos")
ax.set_xlabel("Tiempo Promedio")
ax.set_title("Vectores Desordenados Tamaño 50")

pp.show()
