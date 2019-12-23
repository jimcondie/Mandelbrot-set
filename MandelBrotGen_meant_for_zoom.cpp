//same code as julia set, modified for Mandelbrot

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//construct color pallete
struct color
{
	int r;
	int g;
	int b;


	void assignColor()
	{
	r=(rand() % (255+1));
	g=(rand() % (255+1));
	b=(rand() % (255+1));
	}

};


//contsruct new window (terms of C)
struct cWindow
{
long double cXMin, cXMax, cYMin, cYMax;

void setCWindow(long double cX,long double cY,long double cWidth,long double cHeight)
{
cXMin=cX-(cWidth/2);
cXMax=cX+(cWidth/2);	
cYMin=cY-(cHeight/2);
cYMax=cY+(cHeight/2);
}
	
};


//find Cx on main cardioid boundary
const long double PI=3.1415926535897932384626433832795028841971693993751;
long double getCXOnBoundary(double alpha)
{
	double cos2PiAlpha=cos(2*PI*alpha);
	double cos4PiAlpha=cos(4*PI*alpha);
long double cX=cos2PiAlpha/2-cos4PiAlpha/4;
cout<<"in cX fun alpha: "<<alpha<<" cosAlpha: "<<cos2PiAlpha<<" cos4PIalpha: "<<cos4PiAlpha<<" cX: "<<cX<<endl;
return cX;


}

//find Cy on main cardioid boundary
long double getCYOnBoundary(double alpha)
{
	double sin2PiAlpha=sin(2*PI*alpha);
	double sin4PiAlpha=sin(4*PI*alpha);
long double cY=sin2PiAlpha/2-sin4PiAlpha/4;
return cY;
}

//map cX (pixel) value into real part
long double mapXIntoReal(unsigned int Pwidth, long double minCX, long double maxCX, unsigned int pixelX)
{
long double domain=maxCX-minCX;

long double realPart=domain/(Pwidth)*pixelX+minCX;

return realPart;
}

//map y (pixel) value into imaginary part
long double mapYIntoImaginary(unsigned int Pheight, long double minCY, long double maxCY, unsigned int pixelY)
{
long double range=maxCY-minCY;

long double imaginaryPart=range/(Pheight)*pixelY+minCY;

return imaginaryPart;	
}

//function that calculates magnitudes
long double mag(long double Real, long double Imaginary)
{
long double mag=sqrt((Real*Real)+(Imaginary*Imaginary));
return mag;
}


//find nth iterate of function
unsigned int iterateFunction(unsigned int maxiter,long double cReal, long double cImaginary)
{

	//initialize n at 0
	unsigned int n=0;
	
	//set initial f^0(0)
	long double fReal=0;
	long double fImaginary=0;
	
		
		while(n<maxiter)
		{
		
		//calculate f^n(0),
		long double fRealTemp=fReal*fReal-fImaginary*fImaginary+cReal;
		long double fImaginaryTemp=2*fReal*fImaginary+cImaginary;
			
			//break if |f^n(0)|>2
			if(mag(fRealTemp,fImaginaryTemp) >2)
			break;
			
			else
			{
			fReal=fRealTemp;
			fImaginary=fImaginaryTemp;
			n++;
			}
					
		}
	
	//return value of n
	return n;
}


void colorPixel(int n, int maxiter, color* pallete, ofstream &ofile)
{
	bool is_in=false;
	
		//if n==maxiter, this z point is in; set color black
		if(n>=maxiter)
		{
			//cout<<"poit is in   ";
		//write black pixel to file
		ofile<<0<<" "<<0<<" "<<0<<" ";
		is_in=true;
		}	

		//if n<maxiter z point is out, set color based on n
		if(is_in==false)
		{
				cout<<"point is out  ";	
		ofile<<(pallete+n)->r<<" "<<(pallete+n)->g<<" "<<(pallete+n)->b<<" ";
		}	
}


int main()
{

//input program parameters
ifstream ifile("MandelbrotFrame (center_around_given_C).txt");

	if(!ifile)
	{
	cout<<"frame file not found"<<endl;
	cin.ignore();

	return 0;
	}

 unsigned int pixelWidth,pixelHeight, maxiter;
 long double alpha, cWidth, cHeight;

//read in values
ifile>>pixelWidth>>pixelHeight>>maxiter>>alpha>>cWidth>>cHeight;
ifile.close();


ofstream ofile("test.ppm");

//PPM header
ofile<<"P3 " << endl << pixelWidth << " " << pixelHeight << endl;
ofile<<"256"<<endl;


//contruct color pallete
color* pallete= new color[maxiter];
unsigned int seed=time(0);
srand(seed);
	for(unsigned int i=0; i<maxiter; i++)
	{
	(pallete+i)->assignColor();	
	}
	cout<<"pallette made"<<endl;

//find cX and cY based on alpha
long double cX=getCXOnBoundary(alpha);
long double cY=getCYOnBoundary(alpha);



//define new frame (in terms of C)
cWindow window;
window.setCWindow(cX,cY,cWidth,cHeight);
cout<<"cX: "<<cX<<" cY: "<<cY<<endl;

//iterate function for each pixel (representing a C-value)
	for(unsigned int y=0; y<pixelHeight; y++)
	{
		for(unsigned int x=0; x<pixelWidth; x++)
		{
		//map pixel to C
		long double cReal=mapXIntoReal(pixelWidth,window.cXMin,window.cXMax,x);
		long double cImaginary=mapYIntoImaginary(pixelHeight, window.cYMin,window.cYMax,y);
		
		//find n for C value
		int n=iterateFunction(maxiter, cReal, cImaginary);
		
		//write n to output
		
		colorPixel(n, maxiter, pallete, ofile);
		//cout<<"row: "<<y<<" col: "<<x<<endl;
		}
	ofile<<endl;
	}

cout<<"cXMin: "<<window.cXMin<<" cXMax: "<<window.cXMax<<endl;
cout<<"cYMin: "<<window.cYMin<<" cYMax: "<<window.cYMax<<endl;
cout<<"alpha: "<<alpha;

ofile.close();

delete [] pallete;
return 0;
}

