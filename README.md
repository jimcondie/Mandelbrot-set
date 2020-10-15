# Mandelbrot-set

Allows one to create images of the Mandelbrot set, either whole set, or zoomed in on areas of interest.  User sets an angle, alpha, that corresponds to a point on the set's main cardioid. The reasoning for centering the frame on a point on the cardiod is to ensure the program zooms in on an edge of the Mandelbrot set. The edge of the set provides interesting results which oterhwise aren't generally guaranteed. 

The maxiter is the maximum iterations the program will run on a single pixel.

The text file sets the desired pixel resolution, maxiter, alpha, and new width and height (the last two numbers effectively decide how much to zoom in).

For example, the following parameters will give the whole, coarse Mandelbrot set

######
100 100 250 0.5 -3 3 

1.  Image Width pixels
2.  Image Height pixels
3.  maxiter	(n: f^n(z)=z^2+C)
4.  alpha (2pi*alpha)
5.  new domain width (in terms of C)
6.  new range height (in terms of C)
#####

To increase resolution, increase the pixels and maxiter.

I recommend using a low resolution just to find a window that you like.  Then, increase resolution.  My most ambitious images took about 4 days to process (4000x4000 pixels, maxiter: 250000).

the final image is a .ppm file. Windows users will need a 3rd party viewer such as Gimp or IrframView. Linux users will be fine.
