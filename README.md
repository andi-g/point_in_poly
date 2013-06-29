point_in_poly
=============


ABOUT
===
Author: Andreas Gros, andigros72@gmail.com

This python package uses C code to faster determine whether a point is contained in a polygon.


INSTALL
===
To install call

python setup.py build

sudo python setup.py install

You may have to adjust the "include" paths in the setup.py file 


USAGE
===

Example:

```python

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
print 'outside:', poly.point_in_poly(x, y, arr) != 1

```
