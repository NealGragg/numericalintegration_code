#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

  
int main (int argc, char* argv[]) {

  auto start = std::chrono::steady_clock::now();

  int functionID = atoi(argv[1]);
  int lowerBound = atoi(argv[2]);
  int upperBound = atoi(argv[3]);
  int numOfPoints = atoi(argv[4]);
  int intensity = atoi(argv[5]);
  float functionResult = 0.0;
  float x = 0.0;
  float sumValue = 0.0;
  float finalValue = 0.0;

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  
    switch(functionID)
      {
      case 1:
	for (int i = 0; i < numOfPoints-1; i++)
	  {
	    x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	    functionResult = f1(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	std::cout<<finalValue;
	break;
      case 2:
	for (int i = 0; i < numOfPoints-1; i++)
	  {
	    x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	     functionResult = f2(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	std::cout<<finalValue;
	break;
      case 3:
	for (int i = 0; i < numOfPoints-1; i++)
	  {
	    x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	     functionResult = f3(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	std::cout<<finalValue;
	break;
      case 4:
	for (int i = 0; i < numOfPoints-1; i++)
	  {
	    x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	     functionResult = f4(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	std::cout<<finalValue;
	break;
      default:
	std::cerr<<"Invalid function ID."<<std::endl;
      }
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> seconds_elapsed = end-start;
  std::cerr<<seconds_elapsed.count();
  
  return 0;
}
