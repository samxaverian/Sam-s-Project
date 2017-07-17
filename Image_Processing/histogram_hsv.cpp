#include <stdio.h>
#include <iostream>
#include <string.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>



/**
 * @function main
 */
int main()
{
  cv::Mat src, dst;

  /// Load image
  src = cv::imread( "/home/samxaverian/me/designgraphics/test_folder/index5.jpg", 1 );
  cv::imshow("image",src);
  cv::cvtColor(src,src,CV_BGR2HSV);
  if( !src.data )
    { return -1; }

  /// Separate the image in 3 places ( B, G and R )
  std::vector<cv::Mat> hsv_planes;
  cv::split( src, hsv_planes );

  /// Establish the number of bins
  int hue_size = 6;
  int saturation_size =8;
 int value_size =8;
  /// Set the ranges ( for B,G,R) )
  float saturation_range[] = { 0, 256 } ;
  float value_range[] = { 0, 256 } ;
  float hue_range[] = { 0, 181 } ;  
  const float* hue_Range = { hue_range };
  const float* saturation_Range = { saturation_range };
  const float* value_Range = { value_range };

  bool uniform = true; bool accumulate = true;

  cv::Mat h_hist, s_hist, v_hist;

  /// Compute the histograms:
  cv::calcHist( &hsv_planes[0], 1, 0, cv::Mat(), h_hist, 1, &hue_size, &hue_Range, uniform, accumulate );
  cv::calcHist( &hsv_planes[1], 1, 0, cv::Mat(), s_hist, 1, &saturation_size, &saturation_Range, uniform, accumulate );
  cv::calcHist( &hsv_planes[2], 1, 0, cv::Mat(), v_hist, 1, &value_size, &value_Range, uniform, accumulate );

  // Draw the histograms for B, G and R
  int hist_w = 512; int hist_h = 400;
  
  int hue_bin_w = cvRound( (double) hist_w/hue_size );
  int saturation_bin_w = cvRound( (double) hist_w/saturation_size );
  int value_bin_w = cvRound( (double) hist_w/value_size );
  /*
  int hue_bin_w = cvRound( (double) 30.00 );
  int saturation_bin_w = cvRound( (double) 64.00 );
  int value_bin_w = cvRound( (double) 64.00 );
*/

//  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
  cv::Mat HuehistImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255) );
  cv::Mat ValuehistImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255) );
  cv::Mat SaturationhistImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255) );


  /// Normalize the result to [ 0, histImage.rows ]
  cv::normalize(h_hist, h_hist, 0, HuehistImage.rows, cv::NORM_MINMAX, -1);
  cv::normalize(s_hist, s_hist, 0, SaturationhistImage.rows, cv::NORM_MINMAX, -1);
  cv::normalize(v_hist, v_hist, 0, ValuehistImage.rows, cv::NORM_MINMAX, -1 );

  /// Draw for each channel
  for( int i = 1; i < hue_size; i++ )
  {
      cv::line( HuehistImage, cv::Point( hue_bin_w*(i-1), hist_h - cvRound(h_hist.at<float>(i-1)) ) ,
                       cv::Point( hue_bin_w*(i), hist_h - cvRound(h_hist.at<float>(i)) ),
                       cv::Scalar( 0, 0, 0), 2, 8, 0  );
  }
    for( int i = 1; i < saturation_size; i++ )
    {
      cv::line( SaturationhistImage, cv::Point( saturation_bin_w*(i-1), hist_h - cvRound(s_hist.at<float>(i-1)) ) ,
                       cv::Point( saturation_bin_w*(i), hist_h - cvRound(s_hist.at<float>(i)) ),
                       cv::Scalar( 0, 0, 0), 2, 8, 0  );
    }
    for( int i = 1; i < value_size; i++ )
      {
      cv::line( ValuehistImage, cv::Point( value_bin_w*(i-1), hist_h - cvRound(v_hist.at<float>(i-1)) ) ,
                       cv::Point( value_bin_w*(i), hist_h - cvRound(v_hist.at<float>(i)) ),
                       cv::Scalar( 0, 0, 0), 2, 8, 0  );
      }

  /// Display
  cv::namedWindow("HUE", CV_WINDOW_AUTOSIZE );
  cv::imshow("HUE", HuehistImage );

  cv::namedWindow("SATURATION", CV_WINDOW_AUTOSIZE );
  cv::imshow("SATURATION", SaturationhistImage );

  cv::namedWindow("VALUE", CV_WINDOW_AUTOSIZE );
  cv::imshow("VALUE", ValuehistImage );
  
  cv::waitKey(0);

  return 0;
}

 
 
 
