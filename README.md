# Mandelbrot-set

this code allows one to create images of the Mandelbrot set, that are zoomed a specified point around the Mandelbrot set's main cardioid.
If one wants to zoom in, areas of interest usually lie along boundaries of the set.  There's a formula for the main cardioid so this program exploits this formula in an effort to provide interesting points that one might want to explore zooming in towards. 

Alpha sets the fractional angle around the cardioid.  The maxiter is the maximum iterations the program will run on a given pixel.

The text file sets the desired pixel resolution, maxiter, alpha, and new width and height (the last two number effectively decide how much to zoom in).

For example, the following parameters will give the whole Mandelbrot set (albeit it will be pretty coarse)

######
100 100 250 0.5 -3 3 

1.  Image Width pixels
2.  Image Height pixels
3.  maxiter	(n: f^n(z)=z^2+C)
4.  alpha (2pi*alpha)
5.  new domain width (in terms of C)
6.  new range height (in terms of C)
#####

I suggest using a low resolution and maxiter (for my old computer, 100x100 pixels with maxiter:250 is sufficiently low) just to find a window that you like.  Then I would increase pixels and maxiter which will give better detail but will also significantly increase processing time.  My most ambitious images took about 4 days to process (4000x4000 pixels, maxiter: 250000).

the final image is a .ppm file.  I just know that Windows users will need a 3rd party viewer that supports such files, Linux users will be fine.
