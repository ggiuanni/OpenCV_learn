#include "ReadWriteImg.hpp"

void ReadWriteImgSample() {
  // Read images
  Mat color= imread("./samples/lena.jpg");
  Mat gray= imread("./samples/lena.jpg", IMREAD_GRAYSCALE);
  
  if(! color.data ) // Check for invalid input
    {
      cout << "Could not open or find the image" << std::endl ;
      return;
    }
  
  // Write images
  imwrite("./samples/lenaGray.jpg", gray);
  
  // Get same pixel with opencv function
  int myRow=color.cols-1;
  int myCol=color.rows-1;
  auto pixel= color.at<Vec3b>(myRow, myCol);
  cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
  
  // show images
  imshow("Lena BGR", color);
  imshow("Lena Gray", gray);
  // wait for any key press
  waitKey(0);
}
