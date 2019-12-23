# Mandelbrot-set

this code allows one to create views of the Mandelbrot set, that are zoomed in.
Areas of interest usually lie at the boundary of the set, that's why this program uses the formula to pick points on the main cardioid of the Mandelbrot set

the text file sets the center and window size and zoom for example, the following parameters will give a whole Set centered (albeit it will be pretty coarse)

######
100 100 250 0.5 -3 3 

1.  Image Width pixels
2.  Image Height pixels
3.  maxiter	(n: f^n(z)=z^2+C)
4.  alpha (2pi*alpha)
5.  new domain width (in terms of C)
6.  new range height (in terms of C)
#####

I suggest using 100x100 pixels with maxiter at 250 until you find a frame and zoom you like, and then increase pixels and maxiter which can significantly increase processing time.  my most ambitious images took about 4 days to process.
