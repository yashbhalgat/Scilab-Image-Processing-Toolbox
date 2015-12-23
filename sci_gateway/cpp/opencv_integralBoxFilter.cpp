/*************************************************************************************
Author : Yash S. Bhalgat
***************************************************************************************
Usage :
	output_image = integralBoxFilter(input_img, guidance_img, r, eps);

Example : 
	img = imread("lena.jpg");
	imshow(img);
	guidedFiltered_image = imguidedfilter(img, img, 9);
	imshow(guidedFiltered_image);
***********************************************************************/

#include <numeric>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
extern "C"
{
  #include "api_scilab.h"
  #include "Scierror.h"
  #include "BOOL.h"
  #include <localization.h>
  #include <sciprint.h>
  #include "../common.h"
  
  int opencv_integralBoxFilter(char *fname, unsigned long fname_len)
  {

    SciErr sciErr;
    int intErr = 0;
    int iRows=0,iCols=0;
    int *piAddr2  = NULL;
    int *piAddr3  = NULL;
    int *piAddr4  = NULL;
    int i,j,k;
	
	//Default filter size
	double r= 4;
	double eps= 0.2 * 0.2 * 255 * 255;

    //checking input argument
    CheckInputArgument(pvApiCtx, 1, 4);
    CheckOutputArgument(pvApiCtx, 1, 1) ;
	
	int inputarg = *getNbInputArgument(pvApiCtx);
	
	
    Mat I;
    retrieveImage(I,1);
	
	Mat p=I;
	
	if(inputarg > 1){
		//for value of filter_height
		//sciErr = getVarAddressFromPosition(pvApiCtx,2,&piAddr2);
		//if (sciErr.iErr)
		//{
		//	printError(&sciErr, 0);
		//	return 0;
		//}
		//intErr = getScalarDouble(pvApiCtx, piAddr2, &filter_height);
		//if(intErr)
		//	return intErr;
		Mat G;
		retrieveImage(G,1);
		p=G;
		
		if(inputarg > 2){
			sciErr = getVarAddressFromPosition(pvApiCtx,3,&piAddr3);
			if (sciErr.iErr)
			{
				printError(&sciErr, 0);
				return 0;
			}
			intErr = getScalarDouble(pvApiCtx, piAddr3, &r);
			if(intErr)
				return intErr;
		}
		if(inputarg > 3){
			sciErr = getVarAddressFromPosition(pvApiCtx,4,&piAddr4);
			if (sciErr.iErr)
			{
				printError(&sciErr, 0);
				return 0;
			}
			intErr = getScalarDouble(pvApiCtx, piAddr4, &eps);
			if(intErr)
				return intErr;
		}
	}


    Mat guidedFiltered_image;


    //Main function
    //if both filter_size is not given, default value of 3x3 is used
	

    //returning image
    string tempstring = type2str(guidedFiltered_image.type());
    char *checker;
    checker = (char *)malloc(tempstring.size() + 1);
    memcpy(checker, tempstring.c_str(), tempstring.size() + 1);
    returnImage(checker,guidedFiltered_image,1);
    free(checker);

    //Assigning the list as the Output Variable
    AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;
    //Returning the Output Variables as arguments to the Scilab environment
    ReturnArguments(pvApiCtx);
    return 0;

  }
/* ==================================================================== */
}