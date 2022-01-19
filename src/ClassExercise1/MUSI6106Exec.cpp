
#include <iostream>
#include <ctime>

#include "MUSI6106Config.h"

#include "AudioFileIf.h"

using std::cout;
using std::endl;

// local function declarations
void    showClInfo ();

/////////////////////////////////////////////////////////////////////////////////
// main function
int main(int argc, char* argv[])
{
    std::string             sInputFilePath,                 //!< file paths
                            sOutputFilePath;

    static const int        kBlockSize = 1024;

    clock_t                 time = 0;

    float                   **ppfAudioData = 0;

    CAudioFileIf            *phAudioFile = 0;
    std::fstream            hOutputFile;
    CAudioFileIf::FileSpec_t stFileSpec;

    showClInfo();

    //////////////////////////////////////////////////////////////////////////////
    // parse command line arguments
    if (argc == 3) {
        sInputFilePath = argv[1];
        sOutputFilePath = argv[2];
    } else {
        printf("Enter Input File and Output File Paths");
    }
    //////////////////////////////////////////////////////////////////////////////
    // open the input wave file
    // set file spec struct
    stFileSpec.eFormat = CAudioFileIf::kFileFormatWav;
    stFileSpec.eBitStreamType = CAudioFileIf::kFileBitStreamFloat32;
    stFileSpec.iNumChannels = 2;
    stFileSpec.fSampleRateInHz = 44100;

    cAudioFileIf::create(phAudioFile);
    pHAudioFile->openFile(sInputFilePath, CAudioFileIf::kFileRead, &stFileSpec);

    //////////////////////////////////////////////////////////////////////////////
    // open the output text file
    hOutputFile.open(sOutputFilePath);

    //////////////////////////////////////////////////////////////////////////////
    // allocate memory
    
    ppfAudioData = new float* [stFileSpec.iNumChannels];
    for (int i = 0; i < stFileSpec.iNumChannels; i++) {
        ppfAudioData[i] = new float [kBlockSize];
    }

    //////////////////////////////////////////////////////////////////////////////
    // get audio data and write it to the output text file (one column per channel)

    long long int framesRead = kBlockSize;
    phAudioFile->readData(ppfAudioData, framesRead);

    while (framesRead != 0) {
        for (int i = 0; i < framesRead; i++) {
            for (int j = 0; j < stFileSpec.iNumChannels; j++) {
                hOutputFile << std::to_string(ppfAudioData[j][i]) + " | ";
            }
            hOutputFile << "\n";
        }
        framesRead = kBlockSize;
        phAudioFile->readData(ppfAudioData, framesRead)
    }

    //////////////////////////////////////////////////////////////////////////////
    // clean-up (close files and free memory)

    for (int i = 0; i < stFileSpec.iNumChannels; i++) {
        delete [] ppfAudioData[i];
    }
    delete ppfAudioData;

    hOutputFile.close();
    phAudioFile->closeFile();
    cAudioFileIf::destroy(phAudioFile);

    // all done
    return 0;

}


void     showClInfo()
{
    cout << "MUSI6106 Assignment Executable" << endl;
    cout << "(c) 2014-2022 by Alexander Lerch" << endl;
    cout  << endl;

    return;
}

