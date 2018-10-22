#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>


using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
        string filename;
        Bitmap image;
        Pixel color;
        if(argc != 2)
        {
                cout<<"Please specify one image file!\n";
        }
        if(argc ==2)
        {
                filename = argv[1];
                image.open(filename);
        }
        if(image.isImage() == false)
        {
                cout<<"Image file must be a bitmap with 24-bit color depth.\n";
        }
        if(image.isImage() == true)
        {
                vector <vector <Pixel> > imagePixels = image.toPixelMatrix();
                cout<<filename<<" is "<<imagePixels.size()<<" pixels high and "<<imagePixels[0].size()<<" wide."<<endl;       
                for(int rows =0; rows < imagePixels.size(); rows++)
                {
                        for(int columns =0; columns < imagePixels[rows].size(); columns++)
                        {
                                color = imagePixels[rows][columns];
                                color.green = 0;
                                color.blue =0;
                                imagePixels[rows][columns] = color;
                               // cout<<color.red<<endl;
                        }
                }
                image.fromPixelMatrix(imagePixels);
                image.save("redness.bmp");
        }



        return 0;
}
