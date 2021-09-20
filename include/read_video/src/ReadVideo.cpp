#include "ReadVideo.hpp"

const char* keys =
{
  "{help h usage ? | | print this message}"
  "{@video | | Video file, if not defined try to use webcamera}"
};

void ReadVideoSample(int argc, const char** argv) {
  CommandLineParser parser(argc, argv, keys);
  parser.about("Chapter 2. v1.0.0");
  //If requires help show
  if (parser.has("help"))
    {
      parser.printMessage();
      return;
    }
  
  String videoFile= parser.get<String>(0);
  
  // Check if params are correctly parsed in his variables
  if (!parser.check())
    {
      parser.printErrors();
      return;
    }
  
  VideoCapture cap; // open the default camera
  if(videoFile != "")
    cap.open(videoFile);
  else
    cap.open(0);
  if(!cap.isOpened())  // check if we succeeded
    return;
  
  namedWindow("Video",1);
  for(;;)
    {
      Mat frame;
      cap >> frame; // get a new frame from camera
      if(frame.empty())
	return ;
      imshow("Video", frame);
      if(waitKey(30) >= 0) break;
    }
  
  // Release the camera or video cap
  cap.release();
}
