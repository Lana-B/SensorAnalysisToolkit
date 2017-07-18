/*==========================
 * PestalCalculation.cxx
 *
 *  Created on: 9 Jun 2015
 *      Author: phrfp
 *==========================*/

 //Example to show the use of the basic IO and add and divide functions
#include <iostream>
#include <sstream>

#include <chrono>
#include <ctime>
#include <ratio>

#include "stkImageHistogram.h"
#include "stkRawImageIO.h"//write pedestal in the frames
#include "stkRawImageStackIO.h"//load in the frames
#include "stkImageStack.h"//hold the files to be loaded
#include "stkImage.h"//will hold the result
#include "stkImageSum.h"//used to sum the stack
#include "stkImageDivision.h"//used to divide throgh to get final result

int main(int argc, const char** argv){

	//Check that the correct number of arguments have been passed

	if(argc != 8 ){
		std::cout<<"Usage: PestalCalculation [FILEPATH] [FILENAMEANDFORMAT] [OUTPUTFILENAMEANDPATH] [STARTINGFRAME] [NUMBEROFFILES] [ROWS] [COLS]"<<std::endl;
		std::cout<<"Only 16 bit is supported in this example"<<std::endl;
		return 0;
	}
	//Variables to hold the input parameters
	std::string filePath, fileNameAndFormat, outFileNameAndPath;
	int startingframe, numOfFrames, rows, cols, framesize;
	//
	std::stringstream inputs;
	for(int iArg=1; iArg < argc; iArg++){
		inputs << argv[iArg] << ' ';//get the argumnets
	}

	inputs >> filePath >> fileNameAndFormat >> outFileNameAndPath >> startingframe >> numOfFrames >> rows >> cols;//write the parameters into setup
	framesize = cols*rows;


	//Load image stack
	stk::IOImageStack<float> myIO;
	std::shared_ptr< stk::ImageStack<float> > myImageStack( new stk::ImageStack<float> );
	std::cout<<filePath+fileNameAndFormat<<std::endl;
	myImageStack->Initialise( myIO.ReadImageStack( filePath, fileNameAndFormat, startingframe, numOfFrames, framesize ), numOfFrames, rows, cols );
 std::cout<<"loaded image"<<std::endl;
	//Sum
	stk::ImageSum<float> mySummer;
	//divide
	stk::ImageDivision<float> myDivider;
	//Image to hold result
	std::shared_ptr< stk::Image<float> > myResult ( new stk::Image<float>(4096,4096) );


	std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();//used to find the time it takes for Image to run

	// mySummer.SumImageStack( myImageStack, myResult );

	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();//some timing info

	// myDivider.DivideImage(myResult, static_cast<float>(myImageStack->NumberOfImageInStack()) );

	std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();

	std::chrono::duration<double> time_span_1 = std::chrono::duration_cast<std::chrono::duration<double> >(t1 - t0);
	std::chrono::duration<double> time_span_2 = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);

	std::cout << "Time for Image Sum " << time_span_1.count() << " seconds." << std::endl;
	std::cout << "Time for Image Division " << time_span_2.count() << " seconds." << std::endl;

	//set up hist
	stk::ImageHistogram<TH2F, float> myImageHistogram;
	myImageHistogram.SetTitle("Test");

	myImageHistogram.SetYAxisTitle("Row");
	// myImageHistogram.SetTitleOffset(0.04, "Y");

	myImageHistogram.SetYAxisLog(false);
	myImageHistogram.SetNumberOfYBins( 4096 );
	myImageHistogram.SetYLimits( -0.5, 4095.5 );

	myImageHistogram.SetXAxisTitle( "Col" );
	myImageHistogram.SetNumberOfXBins( 4096 );
	myImageHistogram.SetXLimits( -0.5, 4095.5  );

	myImageHistogram.SetGridY(false);
	myImageHistogram.SetGridX(false);

	myImageHistogram.SetStatBoxOptions(0);

	myImageHistogram.SetOutputFileNameAndPath(outFileNameAndPath);
	myImageHistogram.SetOutputFileType( stk::FileType::PNG );

	myImageHistogram.Generate2DHistogram( myImageStack.at(0));
	// myImageHistogram.Generate2DHistogram( myResult );
	myImageHistogram.SaveHistogram();


	return 1;

}



