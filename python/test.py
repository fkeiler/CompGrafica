# -*- coding: utf-8 -*-
from __future__ import print_function

from numpy import array
from numpy.linalg import norm

from ray import Ray
from cylinder import Cylinder

# from OpenGL.GL import *
# from OpenGL.GLUT import *
# from OpenGL.GLU import *


# def show_screen():
#   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) # Remove everything from screen (i.e. displays all white)

# glutInit() # Initialize a glut instance which will allow us to customize our window
# glutInitDisplayMode(GLUT_RGB) # Set the display mode to be colored
# glutInitWindowSize(640, 480)   # Set the width and height of your window
# glutInitWindowPosition(0, 0)   # Set the position at which this windows should appear
# wind = glutCreateWindow("Scene") # Give your window a title
# glutDisplayFunc(show_screen)  # Tell OpenGL to call the showScreen method continuously
# glutIdleFunc(show_screen)     # Draw any graphics or shapes in the showScreen function at all times
# glutMainLoop()  # Keeps the window created above displaying/running in a loop

p0 = array([0, -3, 0, 1])

base_cylinder = array([0, 1, 5, 1])
unitary_vector = array([0, 0, 1, 0])
cylinder_height = 8
cylinder_radius = 2

d = (base_cylinder-p0)/norm(base_cylinder-p0)
print(d)

ray = Ray(p0)
ray.d = d

cylinder = Cylinder(base_cylinder, unitary_vector, cylinder_height, cylinder_radius)
cylinder.verify_colision(ray)
