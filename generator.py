def int_len(n):
    i = 1
    while n > 0xff:
        n >>= 8
        i += 1
    return i

name = "test_1.grd"
data = [
    [0, 0, 0, 0, 0],
    [1, 1, 0, 1, 1]
]


sy = len(data)
sx = len(data[0])
r = []
t = 0
for i in range(sy):
    for j in range(sx):
        t <<= 1
        t |= data[i][j]
        if j % 8 == 7:
            r.append(t)
            t = 0
print(r)
f = open(name, "wb")
f.write(bytes([int_len(sx), sx, int_len(sy), sy]))
f.write(bytes(r))
