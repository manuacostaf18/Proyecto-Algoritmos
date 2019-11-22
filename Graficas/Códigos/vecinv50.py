from matplotlib import pyplot as pp
import numpy as np

ejey = ["Heap", "Counting", "Selection", "Bubble", "Insertion", "Quick", "Merge", "Shell", "Gnome", "Cocktail"]
ejex = [4.2250e-5, 1.4405e-4, 4.2190e-5, 1.4057e-4, 5.8200e-6, 1.8840e-5, 7.2620e-5, 5.5700e-6, 1.1435e-4, 1.3561e-4]

pp.rcdefaults()
fig, ax = pp.subplots()

y_pos = np.arange(len(ejey))
ax.barh(y_pos, ejex, color = ("brown", "red", "darkorange", "gold", "yellowgreen", "green", "lightseagreen", "mediumblue", "violet", "pink"))
ax.set_yticks(y_pos)
ax.set_yticklabels(ejey)
ax.set_ylabel("Ordenamientos")
ax.set_xlabel("Tiempo Promedio")
ax.set_title("Vectores Invertidos Tamaño 50")

pp.show()
