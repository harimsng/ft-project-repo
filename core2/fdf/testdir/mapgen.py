import numpy as np

dx = 0.03
r = 2.0
color_height = 1.0 / (dx)
X = np.arange(-r, r + dx / 2, dx)
Y = np.arange(-r, r + dx / 2, dx)

file = open("testmap.fdf", 'w')

for y in Y:
    for x in X:
        num = (y*y + x*x)
        if (num > r * r):
            file.write("0,0x000000 ")
            continue
        if (num < dx * dx):
            file.write(str(-0.8 / (dx*dx)))
            file.write(",0x111111")
            file.write(' ')
            continue
        height = -1 / num
        file.write(str(height))
        file.write(',')
        color = int((1 - np.sqrt(np.sqrt((-height / color_height)))) * 210 + 45)
        color = color * 65536 + color * 256 + color
        file.write(hex(color))
        file.write(' ')
    file.write('\n')
