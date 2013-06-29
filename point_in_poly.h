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
static int in_poly(const double x, const double y, PyArrayObject *poly);
static PyObject *_point_in_poly(PyObject *self, PyObject *args);

