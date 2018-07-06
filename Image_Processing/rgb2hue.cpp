#include <iostream>
#include <string>
#include <vector>
//#include "opendir.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

struct Color
{
  long long int hue_freq;
  std::string hue;
}red,blue,cyan,green,magenta,yellow;

struct final_analyze
{
  int count;
  std::string hue;
}fan[6];

std::vector<final_analyze> predict;

void initialize()
{
  red.hue_freq=0;
  red.hue="red";
  blue.hue_freq=0;
  blue.hue="blue";
  green.hue_freq=0;
  green.hue="green";
  cyan.hue_freq=0;
  cyan.hue="cyan";
  magenta.hue_freq=0;
  magenta.hue="magenta";
  yellow.hue_freq=0;
  yellow.hue="yellow";
}

std::string top_left(cv::Mat input)
{
  //TOP LEFT SECTION:
    initialize(); 
     for(int i=0;i<input.rows/2;i++)
    {
        cv::Vec3b* pixel = input.ptr<cv::Vec3b>(i); // point to first pixel in row
        for(int j=0;j<input.cols/2;j++)
        {
           if((pixel[j][0]>=0 && pixel[j][0]<40/2) || (pixel[j][0]>=320/2 && pixel[j][0]<=360/2))
           {
               red.hue_freq++;
           }
           
            else if(pixel[j][0]>=40/2 && pixel[j][0]<70/2)
            {   
              yellow.hue_freq++;
            }
            
            else  if(pixel[j][0]>=70/2 && pixel[j][0]<170/2)
            {   
              green.hue_freq++;
            } 
            
            else if(pixel[j][0]>=170/2 && pixel[j][0]<190/2)
            {   
              cyan.hue_freq++;
            }
            
            else if(pixel[j][0]>=190/2 && pixel[j][0]<290/2)
            {   
              blue.hue_freq++;
            }
            
             else if(pixel[j][0]>=290/2 && pixel[j][0]<320/2)
            {   
              magenta.hue_freq++;
            }
            
            
        }
        
    }
           // cv::cvtColor(input,input,CV_HSV2BGR);
           // cv::imshow("NEW",input);
           std::vector<Color> values;
           values.push_back(red);
           values.push_back(yellow);
           values.push_back(green);
           values.push_back(cyan);
           values.push_back(blue);
           values.push_back(magenta);
           std::sort(values.begin(),values.end(),[](Color c1,Color c2){return c1.hue_freq<c2.hue_freq;});
           for(int i=0;i<6;i++)
           {
            if(values.back().hue==fan[i].hue)
            {
              ++fan[i].count;
              break;
            }
           }


           return values.back().hue;
}

std::string top_right(cv::Mat input)
{
    //TOP LEFT SECTION:
    initialize(); 
     for(int i=0;i<input.rows/2;i++)
    {
        cv::Vec3b* pixel = input.ptr<cv::Vec3b>(i); // point to first pixel in row
        for(int j=input.cols/2;j<input.cols;j++)
        {
           if((pixel[j][0]>=0 && pixel[j][0]<40/2) || (pixel[j][0]>=320/2 && pixel[j][0]<=360/2))
           {
               red.hue_freq++;
           }
           
            else if(pixel[j][0]>=40/2 && pixel[j][0]<70/2)
            {   
              yellow.hue_freq++;
            }
            
            else  if(pixel[j][0]>=70/2 && pixel[j][0]<170/2)
            {   
              green.hue_freq++;
            } 
            
            else if(pixel[j][0]>=170/2 && pixel[j][0]<190/2)
            {   
              cyan.hue_freq++;
            }
            
            else if(pixel[j][0]>=190/2 && pixel[j][0]<290/2)
            {   
              blue.hue_freq++;
            }
            
             else if(pixel[j][0]>=290/2 && pixel[j][0]<320/2)
            {   
              magenta.hue_freq++;
            }
            
            
        }
        
    }
           // cv::cvtColor(input,input,CV_HSV2BGR);
           // cv::imshow("NEW",input);
           std::vector<Color> values;
           values.push_back(red);
           values.push_back(yellow);
           values.push_back(green);
           values.push_back(cyan);
           values.push_back(blue);
           values.push_back(magenta);
           std::sort(values.begin(),values.end(),[](Color c1,Color c2){return c1.hue_freq<c2.hue_freq;});
           for(int i=0;i<6;i++)
           {
            if(values.back().hue==fan[i].hue)
            {
              ++fan[i].count;
              break;
            }
           }
          

           return values.back().hue;

}

std::string bottom_left(cv::Mat input)
{
    //TOP LEFT SECTION:
    initialize(); 
     for(int i=input.rows/2;i<input.rows;i++)
    {
        cv::Vec3b* pixel = input.ptr<cv::Vec3b>(i); // point to first pixel in row
        for(int j=0;j<input.cols/2;j++)
        {
           if((pixel[j][0]>=0 && pixel[j][0]<40/2) || (pixel[j][0]>=320/2 && pixel[j][0]<=360/2))
           {
               red.hue_freq++;
           }
           
            else if(pixel[j][0]>=40/2 && pixel[j][0]<70/2)
            {   
              yellow.hue_freq++;
            }
            
            else  if(pixel[j][0]>=70/2 && pixel[j][0]<170/2)
            {   
              green.hue_freq++;
            } 
            
            else if(pixel[j][0]>=170/2 && pixel[j][0]<190/2)
            {   
              cyan.hue_freq++;
            }
            
            else if(pixel[j][0]>=190/2 && pixel[j][0]<290/2)
            {   
              blue.hue_freq++;
            }
            
             else if(pixel[j][0]>=290/2 && pixel[j][0]<320/2)
            {   
              magenta.hue_freq++;
            }
            
            
        }
        
    }
           // cv::cvtColor(input,input,CV_HSV2BGR);
           // cv::imshow("NEW",input);
           std::vector<Color> values;
           values.push_back(red);
           values.push_back(yellow);
           values.push_back(green);
           values.push_back(cyan);
           values.push_back(blue);
           values.push_back(magenta);
           std::sort(values.begin(),values.end(),[](Color c1,Color c2){return c1.hue_freq<c2.hue_freq;});
           for(int i=0;i<6;i++)
           {
            if(values.back().hue==fan[i].hue)
            {
              ++fan[i].count;
              break;
            }
           }

           return values.back().hue;

}

std::string bottom_right(cv::Mat input)
{
    //TOP LEFT SECTION:
    initialize(); 
     for(int i=input.rows/2;i<input.rows;i++)
    {
        cv::Vec3b* pixel = input.ptr<cv::Vec3b>(i); // point to first pixel in row
        for(int j=input.cols/2;j<input.cols;j++)
        {
           if((pixel[j][0]>=0 && pixel[j][0]<40/2) || (pixel[j][0]>=320/2 && pixel[j][0]<=360/2))
           {
               red.hue_freq++;
           }
           
            else if(pixel[j][0]>=40/2 && pixel[j][0]<70/2)
            {   
              yellow.hue_freq++;
            }
            
            else  if(pixel[j][0]>=70/2 && pixel[j][0]<170/2)
            {   
              green.hue_freq++;
            } 
            
            else if(pixel[j][0]>=170/2 && pixel[j][0]<190/2)
            {   
              cyan.hue_freq++;
            }
            
            else if(pixel[j][0]>=190/2 && pixel[j][0]<290/2)
            {   
              blue.hue_freq++;
            }
            
             else if(pixel[j][0]>=290/2 && pixel[j][0]<320/2)
            {   
              magenta.hue_freq++;
            }
            
            
        }
        
    }
           // cv::cvtColor(input,input,CV_HSV2BGR);
           // cv::imshow("NEW",input);
           std::vector<Color> values;
           values.push_back(red);
           values.push_back(yellow);
           values.push_back(green);
           values.push_back(cyan);
           values.push_back(blue);
           values.push_back(magenta);
           std::sort(values.begin(),values.end(),[](Color c1,Color c2){return c1.hue_freq<c2.hue_freq;});
           for(int i=0;i<6;i++)
           {
            if(values.back().hue==fan[i].hue)
            {
              ++fan[i].count;
              break;
            }
           }

           return values.back().hue;

}

std::string central(cv::Mat input)
{
  //TOP LEFT SECTION:
    initialize(); 
     for(int i=(3*input.rows)/8;i<(5*input.rows)/8;i++)
    {
        cv::Vec3b* pixel = input.ptr<cv::Vec3b>(i); // point to first pixel in row
        for(int j=(3*input.cols)/8;j<(5*input.cols)/8;j++)
        {
           if((pixel[j][0]>=0 && pixel[j][0]<40/2) || (pixel[j][0]>=320/2 && pixel[j][0]<=360/2))
           {
               red.hue_freq++;
           }
           
            else if(pixel[j][0]>=40/2 && pixel[j][0]<70/2)
            {   
              yellow.hue_freq++;
            }
            
            else  if(pixel[j][0]>=70/2 && pixel[j][0]<170/2)
            {   
              green.hue_freq++;
            } 
            
            else if(pixel[j][0]>=170/2 && pixel[j][0]<190/2)
            {   
              cyan.hue_freq++;
            }
            
            else if(pixel[j][0]>=190/2 && pixel[j][0]<290/2)
            {   
              blue.hue_freq++;
            }
            
             else if(pixel[j][0]>=290/2 && pixel[j][0]<320/2)
            {   
              magenta.hue_freq++;
            }
            
            
        }
        
    }
           // cv::cvtColor(input,input,CV_HSV2BGR);
           // cv::imshow("NEW",input);
           std::vector<Color> values;
           values.push_back(red);
           values.push_back(yellow);
           values.push_back(green);
           values.push_back(cyan);
           values.push_back(blue);
           values.push_back(magenta);
           std::sort(values.begin(),values.end(),[](Color c1,Color c2){return c1.hue_freq<c2.hue_freq;});
           for(int i=0;i<6;i++)
           {
            if(values.back().hue==fan[i].hue)
            {
              ++fan[i].count;
              break;
            }
           }

           return values.back().hue;

}

int main()
{
   for(int i=0;i<6;i++)
   {
    fan[i].count=0;
   }

   fan[0].hue="red";
   fan[1].hue="blue";
   fan[2].hue="green";
   fan[3].hue="cyan";
   fan[4].hue="magenta";
   fan[5].hue="yellow";

   


    cv::Mat input =cv::imread("D:/#me/JU_Project/train_folder/94.jpe",1);
    cv::Mat result;
    cv::cvtColor(input,result,CV_BGR2HSV);
    std::cout<<"\ntop_left:";
    std::cout<<"\n"<<top_left(result);
    std::cout<<"\ntop_right:";
    std::cout<<"\n"<<top_right(result);
    std::cout<<"\nbottom_left:";
    std::cout<<"\n"<<bottom_left(result);
    std::cout<<"\nbottom_right:";
    std::cout<<"\n"<<bottom_right(result);
    std::cout<<"\ncentral:";
    std::cout<<"\n"<<central(result)<<"\n";
    for(int i=0;i<6;i++)
   {
    predict.push_back(fan[i]);
   }

    std::sort(predict.begin(),predict.end(),[](final_analyze c1,final_analyze c2){return c1.count<c2.count;});
   // cv::waitKey(30);
    std::cout<<"final prediction:"<<predict.back().hue;
    cv::imshow("ORIGINAL",input);
    
    
    
            cv::waitKey(0);
    
    return 0;
}
