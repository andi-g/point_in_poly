
#include <Python.h>
#include "arrayobject.h"
#include "point_in_poly.h"
#include <math.h>

/**
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.


  This function determines whether a point is contained in a polygon by raycasting
  @param x double: longitudinal coordinate of the point
  @param y double: latitudinal coordinate of the point
  @param poly PyArrayObject: the polygon with col0 as longitude and col1 as latitude
  @return int Returns a 1 if successful, 0 otherwise  
  */
static int in_poly(const double x, const double y, PyArrayObject *poly){
    const npy_intp n = poly->dimensions[0];
    int inside = 0;
    double p1x, p1y, p2x, p2y, xinters = 0;
    int i = 0;
    p1x = *(double *)(poly->data + i*poly->strides[0]);
    p1y = *(double *)(poly->data + i*poly->strides[0] + poly->strides[1]);
    for (i = 0; i<=n; i++) {
        p2x = *(double *)(poly->data + (i % n)*poly->strides[0]);
        p2y = *(double *)(poly->data + (i % n)*poly->strides[0] + poly->strides[1]);
        if (y > fmin(p1y,p2y)){
            if (y <= fmax(p1y,p2y)){
                if (x <= fmax(p1x,p2x)){
                    if (p1y != p2y){
                        xinters = (y-p1y)*(p2x-p1x)/(p2y-p1y)+p1x;
                    }    
                    if ((p1x == p2x) || (x <= xinters)){
                        inside = (inside + 1) % 2;
                    }    
                }          
            }        
        }            
        p1x = p2x;
        p1y = p2y;
    }                
    return inside;
}    



static PyObject *
_point_in_poly(PyObject *self, PyObject *args)
{  

    double x;
    double y;
    PyArrayObject *polyin;
      
    int inside = 0;

    if (!PyArg_ParseTuple(args, "ddO!", 
        &x, &y, &PyArray_Type, &polyin))  return NULL;

    if (NULL == polyin) return NULL;

    if (polyin->nd != 2 || polyin->descr->type_num != NPY_DOUBLE) {
        PyErr_SetString(PyExc_ValueError,
        "point_to_poly: array must be two-dimensional and of type float");
        return NULL;
    }

    inside = in_poly(x, y, polyin);

    return Py_BuildValue("i", in_poly);
}

/* ==== Set up the methods table ====================== */
static PyMethodDef point_in_polyMethods[] = {
    {"point_in_poly", _point_in_poly, METH_VARARGS},
    {NULL, NULL},     /* Sentinel - marks the end of this structure */
};

/* ==== Initialize the C_test functions ====================== */
PyMODINIT_FUNC
initpoint_in_poly(void)  {
    PyObject *m;
    m = Py_InitModule("point_in_poly", point_in_polyMethods);
    import_array();  /* Must be present for NumPy.  Called first after above line.*/
    if (m == NULL)
        return;
}





