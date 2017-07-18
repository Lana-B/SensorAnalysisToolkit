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

	int sizeOfImage = 4096;

	//Check that the correct number of arguments have been passed

	if(argc != 6 ){
		std::cout<<"Usage: DataConverter [FILEPATH] [FILENAMEANDFORMAT] [OUTPUTFILENAMEANDPATH] [ROWS] [COLS]"<<std::endl;
		return 0;
	}
	//Variables to hold the input parameters
	std::string filePath, fileNameAndFormat, outFileNameAndPath;
	int rows, cols, framesize;
	//
	std::stringstream inputs;
	for(int iArg=1; iArg < argc; iArg++){
		inputs << argv[iArg] << ' ';//get the argumnets
	}

	inputs >> filePath >> fileNameAndFormat >> outFileNameAndPath >> rows >> cols;//write the parameters into setup
	framesize = cols*rows;


	//Load image stack
	std::unique_ptr<stk::IO<float> > myImageReader(new stk::IO<float>);//IO build according to pixel depth.

	std::cout<<filePath+fileNameAndFormat<<std::endl;
	
	std::shared_ptr< std::vector<float> > mybuffer = myImageReader->ReadImage(filePath+fileNameAndFormat);
	//
	if (myImageReader->ImageLoaded()) {

		std::cout<<"Number of Bytes loaded: "<<myImageReader->BytesRead()<<std::endl;

		std::shared_ptr< stk::Image<float> > myImage( new stk::Image<float> );

		myImage->Initialise( mybuffer, rows, cols );	



		//set up hist
		stk::ImageHistogram<TH2F, float> myImageHistogram;
		myImageHistogram.SetTitle("Test");

		myImageHistogram.SetYAxisTitle("Row");
		// myImageHistogram.SetTitleOffset(0.04, "Y");

		myImageHistogram.SetYAxisLog(false);
		myImageHistogram.SetNumberOfYBins( sizeOfImage );
		myImageHistogram.SetYLimits( -0.5, ((double)sizeOfImage-0.5 ));

		myImageHistogram.SetXAxisTitle( "Col" );
		myImageHistogram.SetNumberOfXBins( sizeOfImage );
		myImageHistogram.SetXLimits( -0.5, ((double)sizeOfImage-0.5)  );

		myImageHistogram.SetGridY(false);
		myImageHistogram.SetGridX(false);

		myImageHistogram.SetStatBoxOptions(0);

		myImageHistogram.SetOutputFileNameAndPath(outFileNameAndPath);
		myImageHistogram.SetOutputFileType( stk::FileType::ROOT );

		myImageHistogram.Generate2DHistogram( myImage );
		// myImageHistogram.Generate2DHistogram( myResult );
		myImageHistogram.SaveHistogram();
	} else {
		std::cout<<"Error loading file"<<std::endl;
		return 0;
	}

	return 1;

}



