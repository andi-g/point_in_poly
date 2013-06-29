import point_in_poly as poly

import numpy as np

#arr = [[x1, y1], [x2, y2], ...]

arr = [[1,0], [10,0], [10,2], [1,2], [1,0]]

arr = np.array(arr, dtype = np.float64)

x = 5
y = 1
print 'inside:', poly.point_in_poly(x, y, arr) == 1

x = 5
y = 3
print 'inside:', poly.point_in_poly(x, y, arr) == 1
