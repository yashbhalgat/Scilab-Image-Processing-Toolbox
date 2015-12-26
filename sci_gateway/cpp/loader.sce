// This file is released under the 3-clause BSD license. See COPYING-BSD.
// Generated by builder.sce : Please, do not edit this file
// ----------------------------------------------------------------------------
//
libskeleton_imagepr_path = get_absolute_file_path('loader.sce');
//
// ulink previous function with same name
[bOK, ilib] = c_link('libskeleton_imageprocessing');
if bOK then
  ulink(ilib);
end
//
list_functions = [ 'imread';
                   'blur';
                   'canny';
                   'circle';
                   'clipline';
                   'convexhull';
                   'cornerEigenValsAndVecs';
                   'cornerHarris';
                   'cornerMinEigenVal';
                   'dilate';
                   'ellipse2poly';
                   'erode';
                   'fillconvexpoly';
                   'filter2D';
                   'findContours';
                   'gaussianblur';
                   'getStructuringElement';
                   'getTextSize';
                   'goodfeaturestotrack';
                   'houghcircles';
                   'houghlines';
                   'im2double';
                   'imcontrast';
                   'imcrop';
                   'imresize';
                   'imsharpen';
                   'imwrite';
                   'laplacian';
                   'line';
                   'medianblur';
                   'puttext';
                   'scharr';
                   'sobel';
                   'threshold';
                   'undistort';
                   'boundingRect';
                   'ellipse';
                   'montage';
                   'morphologyEx';
                   'pyrDown';
                   'pyrUp';
                   'rectangle';
                   'sepFilter2D';
                   'copymakeborder';
                   'cvtColor';
                   'getgaussiankernel';
                   'getrectsubpix';
                   'getrotationmatrix2D';
                   'houghlinesp';
                   'imgaussfilt3';
                   'imhmax';
                   'convmtx2';
                   'imboxfilt3';
                   'imguidedfilter';
                   'integralImage';
                   'adapthisteq';
                   'affine2d';
];
addinter(libskeleton_imagepr_path + filesep() + 'libskeleton_imageprocessing' + getdynlibext(), 'libskeleton_imageprocessing', list_functions);
// remove temp. variables on stack
clear libskeleton_imagepr_path;
clear bOK;
clear ilib;
clear list_functions;
// ----------------------------------------------------------------------------
