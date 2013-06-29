
from distutils.core import setup, Extension

module1 = Extension('point_in_poly',
                    define_macros = [('MAJOR_VERSION', '0'),
                                     ('MINOR_VERSION', '1')],
                    include_dirs = ['/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk/System/Library/Frameworks/Python.framework/Versions/2.5/Extras/lib/python/numpy/core/include/numpy', '/usr/local/include', '/usr/include'],
                    libraries = ['m'],
                    library_dirs = ['/usr/local/lib', '/usr/lib'],
                    sources = ['point_in_poly.c'])

setup (name = 'In_Poly',
       version = '0.1',
       description = 'This is a package to determine whether a point is contained in a polygon',
       author = 'Andreas Gros',
       author_email = 'andigros72@gmail.com',
       url = 'http://andreasgros.net',
       long_description = '''
This is a package to determine whether a point is contained in a polygon
''',
       ext_modules = [module1])



