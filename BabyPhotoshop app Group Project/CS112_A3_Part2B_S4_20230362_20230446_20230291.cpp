/*
 FCAI – CS112 - Structured Programming – 2024 - Assignment 3 - Part 2B

 Program Name: CS112_A3_Part2B_S4_20230362_20230446_20230291.cpp.

 Program Description: Baby Photoshop

 Last Modification Date: 27/3/2024

 Author1 and ID and Group: Mohammad Walid Abdulmotal  -  (20230362)
 Author2 and ID and Group: Nour Maged Mahmoud Abdel-Aal  -  (20230446)
 Author3 and ID and Group: Karen Fady Nabil Tawfik  -  (20230291)

 Teaching Assistant: Eng. Ahmed Fouad Lotfy

 Who did what:

 Mohammad Walid Abdulmotal - Filter 2 - Filter 5 - Filter 8 - Filter 11 - Filter 16
 Nour Maged Mahmoud Abdel-Aal - Filter 3 - Filter 6 - Filter 9 - Filter 12 - Filter 13
 Karen Fady Nabil Tawfik -  Filter 1 - Filter 4 - Filter 7 - Filter 10 - Filter 17


 Repo link (Github) : https://github.com/MohammadG4/TeamRepo
 
*/

#include <iostream>
#include "Image_Class.h"
#include <fstream>
#include <algorithm>
#include <regex>

using namespace std;

int main();

void saveImage(int x) // Save Image Function
{
  string newName, chunck = "";
  Image newImage("Temp.png");

  cout << "Enter new image file name with extention (xxxx.jpg) : "; // taking the name of the image from the user

  cin >> newName;

  for (ll i = 0; i < newName.size(); i++) // making sure that the name of the image match the regx
  {
    if (newName[i] == '.')
    {
      for (ll j = i + 1; j < newName.size(); j++)
      {
        chunck += newName[j];
      }
      break;
    }
  }
  // !regex_match(chunk1, regex("^[a-zA-Z0-9_]+\\.[a-zA-Z0-9]+$"))

  while (!(regex_match(newName, regex("^[a-zA-Z0-9_]+\\.[a-zA-Z0-9]+$"))) || (chunck != "jpg" && chunck != "png" && chunck != "jpeg" && chunck != "tga" && chunck != "bmp"))
  {
    chunck = "";
    cout << "Invalid file name : " << newName; // If it didn't match so the user will have to input the name again

    cout << "\nEnter new image file name with extention (jpg, png, jpeg, tga, bmp) : ";

    cin >> newName;

    for (ll i = 0; i < newName.size(); i++)
    {
      if (newName[i] == '.')
      {
        for (ll j = i + 1; j < newName.size(); j++)
        {
          chunck += newName[j];
        }

        break;
      }
    }
  }

  if (newImage.saveImage(newName)) // saving the image with the name
  {
    cout << "\nImage Saved Successfully!\n";
    if (x == 1) // exit from the program
    {
      cout << "\n*** Thank You For Using the Program ***\n";
      exit(EXIT_SUCCESS);
    }
    if (x == 8) // return to the main menu
    {
      main();
    }

    main();
  }

  else
  {
    cout << "Error Occurred while Saving the Image\nPlease try again later";
  }
}

void filter1(Image image) // Grayscale Conversion
{
  for (int i = 0; i < image.width; i++)
  {
    for (int j = 0; j < image.height; j++)
    {

      unsigned int avg = 0;

      for (int k = 0; k < 3; k++)
      {
        avg += image(i, j, k);
      }

      avg = avg / 3; // Taking the average of the image and make all channels equal to it
      image(i, j, 0) = avg;
      image(i, j, 1) = avg;
      image(i, j, 2) = avg;
    }
  }
  image.saveImage("Temp.png"); // saving the image in temp file

  cout << "Current Image Updated Successfully! \n";
}

void filter2(Image image) // Black and White
{
  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {
      unsigned int avg = 0;

      for (int k = 0; k < 3; ++k)
      {
        avg += image(i, j, k); // saving the image in a variable and divide it by 3
      }

      avg /= 3;

      if (avg < 128) // a condition to update the variable by a value and make the channels equal to it
        avg = 0;     // if average smaller than 128 than this pixel will be coloured with black
      else
        avg = 255; // if average smaller than 128 than this pixel will be coloured with white

      image(i, j, 0) = avg;
      image(i, j, 1) = avg;
      image(i, j, 2) = avg;
    }
  }

  image.saveImage("Temp.png");

  cout << "Current Image Updated Successfully! \n";
}

void filter3(Image image) // Invert Image
{
  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j) // difference between the 255 and the colour red in a specific colour
    {
      unsigned int invertedR = 255 - image(i, j, 0); // saving every pixel with red colour in a variable
      unsigned int invertedG = 255 - image(i, j, 1); // saving every pixel with green colour in a variable
      unsigned int invertedB = 255 - image(i, j, 2); // saving every pixel with blue colour in a variable

      image(i, j, 0) = invertedR; // make all pixels with the red colour = to the variable
      image(i, j, 1) = invertedG; // make all pixels with the green colour = to the variable
      image(i, j, 2) = invertedB; // make all pixels with the blue colour = to the variable
    }
  }

  image.saveImage("Temp.png");

  cout << "Current Image Updated Successfully! \n";
}

void filter4(Image image) // Merge Images
{
  ifstream file;
  string filename2;

  cout << "Please enter the file name of the second image: "; // Taking the image the user wanted to merge it with the original image
  cin >> filename2;
  file.open(filename2);

  while (!file.good()) // making sure the filename of the new image match the regex
  {
    cin.clear();
    cin.ignore();

    cout << "Invalid filename: " << filename2 << "\nCouldn't Load Image\nEnter the image name with the extention: ";
    cin >> filename2;
    file.open(filename2);
  }

  Image image2(filename2);

  double avgwidth = double(image.width) / image2.width;    // taking the average width of the two images
  double avgheight = double(image.height) / image2.height; // taking the average height of the two images

  Image merge(image.width, image.height); // creating a new image with the new width and height
  Image final(image.width, image.height); // creating the final image with the new width and height

  for (int i = 0; i < image.width; i++)
  {
    for (int j = 0; j < image.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        int z = int(i / avgwidth); // saving the pixels in a new varaible after dividing it to the avg
        int m = int(j / avgheight);

        z = min(z, image2.width - 1); // compare the min size of the width and heigh to save the new image based on it
        m = min(m, image2.height - 1);

        merge(i, j, k) = image2(z, m, k); // saving the image in the merge image as the new image we resize it
      }
    }
  }
  for (int i = 0; i < image.width; i++)
  {
    for (int j = 0; j < image.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        unsigned char pix1 = image(i, j, k); // saving the original image to a variable
        unsigned char pix2;
        if (i < merge.width && j < merge.height)
        {
          pix2 = merge(i, j, k);
        }
        else
        {
          pix2 = 0;
        }
        final(i, j, k) = (pix1 + pix2) / 2; // saving the final image based on the average of the two images
      }
    }
  }

  final.saveImage("Temp.png");

  cout << "Current Image Updated Successfully! \n";
}

void filter5(Image image) // Flip Image
{

  int choice;
  cout << "1) Vertical Flip\n2) Horizontal Flip\n";
  cin >> choice;
  while (cin.fail() || (choice != 2 && choice != 1))
  {
    cin.clear(); // Clear the error flag
    cin.ignore();

    cout << "invalid choice!\n1) Vertical Flip\n2) Horizontal Flip" << endl;
    cin >> choice;
  }
  if (choice == 1)
  {
    string filename;
    for (int i = 0; i < image.width; ++i)
    {
      for (int j = 0; j < image.height / 2; ++j) // editing the height of the image for the vertical flip
      {
        unsigned int avg = 0; // Initialize average value

        for (int k = 0; k < 3; ++k)
        {
          unsigned char temp = image(i, j, k); // saving the original image to a variab
          image(i, j, k) = image(i, image.height - 1 - j, k);
          image(i, image.height - 1 - j, k) = temp; // update the image with the variable
        }
      }
    }

    image.saveImage("Temp.png");

    cout << "Current Image Updated Successfully! \n";
  }
  else
  {
    string filename;
    for (int i = 0; i < image.width / 2; ++i) // editing the width of the image for the horizontal flip
    {
      for (int j = 0; j < image.height; ++j)
      {

        for (int k = 0; k < 3; ++k)
        {
          unsigned char temp = image(i, j, k);
          image(i, j, k) = image(image.width - 1 - i, j, k);
          image(image.width - 1 - i, j, k) = temp;
        }
      }
    }

    image.saveImage("Temp.png");

    cout << "Current Image Updated Successfully! \n";
  }
}

void filter6(Image image, string fileName) // Rotate Image
{
  int choice;
  Image Newimage;
  Newimage.loadNewImage(fileName);
  cout << "Select the degree (90, 180 or 270):";
  cin >> choice;
  while (cin.fail() || (choice != 90 && choice != 180 && choice != 270)) // validation for the choice
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid choice\n";
    cin >> choice;
  }
  if (choice == 90)
  {

    Newimage.width = image.height; // saving the image width and height in the opposite direction
    Newimage.height = image.width;

    for (int i = 0; i < Newimage.width; ++i)
    {
      for (int j = 0; j < Newimage.height; ++j)
      {
        Newimage(i, j, 0) = image(j, image.height - 1 - i, 0); // editing the pixels of the image to apply the filter
        Newimage(i, j, 1) = image(j, image.height - 1 - i, 1);
        Newimage(i, j, 2) = image(j, image.height - 1 - i, 2);
      }
    }
  }
  else if (choice == 180)
  {

    Newimage.width = image.width;
    Newimage.height = image.height;

    for (int i = 0; i < Newimage.width; ++i)
    {
      for (int j = 0; j < Newimage.height; ++j)
      {
        Newimage(i, j, 0) = image(image.width - i - 1, image.height - 1 - j, 0); // editing the pixels of the image to apply the filter
        Newimage(i, j, 1) = image(image.width - i - 1, image.height - 1 - j, 1);
        Newimage(i, j, 2) = image(image.width - i - 1, image.height - 1 - j, 2);
      }
    }
  }
  else if (choice == 270)
  {

    Newimage.width = image.height;
    Newimage.height = image.width;

    for (int i = 0; i < Newimage.width; ++i)
    {
      for (int j = 0; j < Newimage.height; ++j)
      {
        Newimage(i, j, 0) = image(image.width - 1 - j, i, 0); // editing the pixels of the image to apply the filter
        Newimage(i, j, 1) = image(image.width - 1 - j, i, 1);
        Newimage(i, j, 2) = image(image.width - 1 - j, i, 2);
      }
    }
  }

  Newimage.saveImage("Temp.png");
}

void light(Image &image) // light function related to brightness filter
{
  int brighten = 25; // make a variable and save a value to edit the brightness by 50%

  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {
      for (int k = 0; k < 3; k++)
      {
        int light = (1.2 * image(i, j, k)) + brighten; // editing the saturation and the brightness of the image
        light = std::max(0, std::min(255, light));
        image(i, j, k) = light; // putting the image we edited to the original image
      }
    }
  }
}

void dark(Image &image) // dark function related to brightness filter
{
  int black = 5; // make a variable and save a value to edit the brightness and make it darker by 50%

  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {
      for (int k = 0; k < 3; k++)
      {
        int dark = (image(i, j, k) / 2) - black; // editing the saturation and the brightness of the image
        dark = std::max(0, std::min(255, dark));
        image(i, j, k) = dark; // putting the image we edited to the original image
      }
    }
  }
}

void filter7(Image image) // Darken and Lighten Image
{

  int choicem;
  cout << "1) Light \n2) Dark\n";
  cin >> choicem;
  while (cin.fail() || choicem > 2 || choicem < 1)
  {
    cout << "Please enter a valid choice : ";
    cin >> choicem;
  }
  if (choicem == 1)
  {
    light(image);
  }
  else if (choicem == 2)
  {
    dark(image);
  }
}

void filter8(Image image) // Crop Images
{
  int x, y, w, h;

  cout << "\nEnter the Center point X,Y : ";
  cin >> x >> y;
  while (cin.fail() || x < 0 || x > image.width || y < 0 || y > image.height) // validation for the input
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid Input\nEnter the Center point X,Y : ";
    cin >> x >> y;
  }

  cout << "\nEnter the Dimensions W,H : "; // asking the user for the specific dimensions so based on it we make the new picture
  cin >> w >> h;
  while (cin.fail() || w < 1 || w > image.width - x || h < 1 || h > image.height - y)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid Input\nEnter the Dimensions W,H : ";
    cin >> w >> h;
  }
  Image image2(w, h); // make the image with the dimensions the user input

  for (int i = x; i < w + x; ++i)
  {
    for (int j = y; j < h + y; ++j)
    {

      image2(i - x, j - y, 0) = image(i, j, 0);
      image2(i - x, j - y, 1) = image(i, j, 1);
      image2(i - x, j - y, 2) = image(i, j, 2);
    }
  }

  image2.saveImage("Temp.png");

  cout << "Current Image Updated Successfully! \n";
}

void filter9(Image image) // Adding a Frame to the Picture
{
  int choiceK;

  cout << "1) Normal Frame\n2) Fancy Frame\nChoose (1,2) : ";
  cin >> choiceK;

  while (cin.fail() || choiceK < 1 || choiceK > 2)
  {
    cout << "Invalid Choice!\nPlease choose (1,2) : ";
    cin >> choiceK;
  }

  if (choiceK == 2)
  {
    int thick = (image.width + image.height) / 2 * 0.01, color0, color1, color2, choiceC; // making the frame based on the original size of the image

    cout << "Please choose the frame Color :\n1) Red\n2) Orange\n3) Yellow\n4) Green\n5) Blue\n6) Pink\n7) Purple\n8) White\n9) Black\n ";
    cin >> choiceC;
    while (cin.fail() || choiceC > 9)
    {
      cin.clear();
      cin.ignore();
      cout << "Invalid Choice\nPlease choose the frame Color: ";
      cin >> choiceC;
    }
    if (choiceC == 1)
    {
      color0 = 255;
      color1 = 0;
      color2 = 0;
    }
    else if (choiceC == 2)
    {
      color0 = 255;
      color1 = 103;
      color2 = 31;
    }
    else if (choiceC == 3)
    {
      color0 = 254;
      color1 = 219;
      color2 = 0;
    }
    else if (choiceC == 4)
    {
      color0 = 0;
      color1 = 117;
      color2 = 64;
    }
    else if (choiceC == 5)
    {
      color0 = 0;
      color1 = 51;
      color2 = 160;
    }
    else if (choiceC == 6)
    {
      color0 = 239;
      color1 = 149;
      color2 = 207;
    }
    else if (choiceC == 7)
    {
      color0 = 112;
      color1 = 47;
      color2 = 138;
    }
    else if (choiceC == 8)
    {
      color0 = 255;
      color1 = 255;
      color2 = 255;
    }
    else if (choiceC == 9)
    {
      color0 = 0;
      color1 = 0;
      color2 = 0;
    }

    // inner
    for (size_t x = 0; x < thick; x++)
    {
      // inner
      // left

      for (int j = 0; j < image.height; ++j)
      {

        image(image.width * (2.04 / 100) + x, j, 0) = color0;
        image(image.width * (2.04 / 100) + x, j, 1) = color1;
        image(image.width * (2.04 / 100) + x, j, 2) = color2;
      }

      // up

      for (int i = 0; i < image.width; ++i)
      {

        image(i, image.height * (2.04 / 100) + x, 0) = color0;
        image(i, image.height * (2.04 / 100) + x, 1) = color1;
        image(i, image.height * (2.04 / 100) + x, 2) = color2;
      }

      // down

      for (int i = 0; i < image.width; ++i)
      {
        image(i, image.height - image.width * (2.04 / 100) - x, 0) = color0;
        image(i, image.height - image.width * (2.04 / 100) - x, 1) = color1;
        image(i, image.height - image.width * (2.04 / 100) - x, 2) = color2;
      }

      // right

      for (int j = 0; j < image.height; ++j)
      {

        image(image.width - image.width * (2.04 / 100) - x, j, 0) = color0;
        image(image.width - image.width * (2.04 / 100) - x, j, 1) = color1;
        image(image.width - image.width * (2.04 / 100) - x, j, 2) = color2;
      }

      for (int j = 0; j < image.height; ++j)
      {

        image(image.width * (2.04 / 100) + x + 15, j, 0) = color0;
        image(image.width * (2.04 / 100) + x + 15, j, 1) = color1;
        image(image.width * (2.04 / 100) + x + 15, j, 2) = color2;
      }

      // up

      for (int i = 0; i < image.width; ++i)
      {

        image(i, image.height * (2.04 / 100) + x + 15, 0) = color0;
        image(i, image.height * (2.04 / 100) + x + 15, 1) = color1;
        image(i, image.height * (2.04 / 100) + x + 15, 2) = color2;
      }

      // down

      for (int i = 0; i < image.width; ++i)
      {
        image(i, image.height - image.width * (2.04 / 100) - x - 15, 0) = color0;
        image(i, image.height - image.width * (2.04 / 100) - x - 15, 1) = color1;
        image(i, image.height - image.width * (2.04 / 100) - x - 15, 2) = color2;
      }

      // right

      for (int j = 0; j < image.height; ++j)
      {

        image(image.width - image.width * (2.04 / 100) - x - 15, j, 0) = color0;
        image(image.width - image.width * (2.04 / 100) - x - 15, j, 1) = color1;
        image(image.width - image.width * (2.04 / 100) - x - 15, j, 2) = color2;
      }
    }
  }

  else
  {

    int thick = (image.width + image.height) / 2 * 0.0075, color0, color1, color2, choiceC;

    cout << "Please choose the frame Color :\n1) Red\n2) Orange\n3) Yellow\n4) Green\n5) Blue\n6) Pink\n7) Purple\n8) White\n9) Black\n ";
    cin >> choiceC;
    while (cin.fail() || choiceC > 9)
    {
      cin.clear();
      cin.ignore();
      cout << "Invalid Choice\nPlease choose the frame Color: ";
      cin >> choiceC;
    }
    if (choiceC == 1)
    {
      color0 = 255;
      color1 = 0;
      color2 = 0;
    }
    else if (choiceC == 2)
    {
      color0 = 255;
      color1 = 103;
      color2 = 31;
    }
    else if (choiceC == 3)
    {
      color0 = 254;
      color1 = 219;
      color2 = 0;
    }
    else if (choiceC == 4)
    {
      color0 = 0;
      color1 = 117;
      color2 = 64;
    }
    else if (choiceC == 5)
    {
      color0 = 0;
      color1 = 51;
      color2 = 160;
    }
    else if (choiceC == 6)
    {
      color0 = 239;
      color1 = 149;
      color2 = 207;
    }
    else if (choiceC == 7)
    {
      color0 = 112;
      color1 = 47;
      color2 = 138;
    }
    else if (choiceC == 8)
    {
      color0 = 255;
      color1 = 255;
      color2 = 255;
    }
    else if (choiceC == 9)
    {
      color0 = 0;
      color1 = 0;
      color2 = 0;
    }

    // inner
    for (size_t x = 0; x < thick; x++)
    {
      // inner
      // left

      for (int j = image.height * (2.04 / 100); j < image.height - image.width * (2.04 / 100); ++j)
      {

        image(image.width * (2.04 / 100) + x, j, 0) = color0;
        image(image.width * (2.04 / 100) + x, j, 1) = color1;
        image(image.width * (2.04 / 100) + x, j, 2) = color2;
      }

      // up

      for (int i = image.width * (2.04 / 100); i < image.width - image.width * (2.04 / 100); ++i)
      {

        image(i, image.height * (2.04 / 100) + x, 0) = color0;
        image(i, image.height * (2.04 / 100) + x, 1) = color1;
        image(i, image.height * (2.04 / 100) + x, 2) = color2;
      }

      // down

      for (int i = image.width * (2.04 / 100); i < image.width - image.width * (2.04 / 100); ++i)
      {
        image(i, image.height - image.width * (2.04 / 100) - x, 0) = color0;
        image(i, image.height - image.width * (2.04 / 100) - x, 1) = color1;
        image(i, image.height - image.width * (2.04 / 100) - x, 2) = color2;
      }

      // right

      for (int j = image.height * (2.04 / 100); j < image.height - image.width * (2.04 / 100); ++j)
      {

        image(image.width - image.width * (2.04 / 100) - x, j, 0) = color0;
        image(image.width - image.width * (2.04 / 100) - x, j, 1) = color1;
        image(image.width - image.width * (2.04 / 100) - x, j, 2) = color2;
      }

      // outer ===================================================================================
      // left

      for (int j = 0; j < image.height; ++j)
      {

        image(x, j, 0) = color0;
        image(x, j, 1) = color1;
        image(x, j, 2) = color2;
      }

      // up

      for (int i = 0; i < image.width; ++i)
      {

        image(i, x, 0) = color0;
        image(i, x, 1) = color1;
        image(i, x, 2) = color2;
      }

      // down

      for (int i = 0; i < image.width; ++i)
      {
        image(i, image.height - x - 1, 0) = color0;
        image(i, image.height - x - 1, 1) = color1;
        image(i, image.height - x - 1, 2) = color2;
      }

      // right

      for (int j = 0; j < image.height; ++j)
      {

        image(image.width - x - 1, j, 0) = color0;
        image(image.width - x - 1, j, 1) = color1;
        image(image.width - x - 1, j, 2) = color2;
      }
    }
  }

  image.saveImage("Temp.png");

  cout << "Current Image Updated Successfully! \n";
}

void filter10(Image image) // Detect Image Edges
{
  filter2(image); // run through the black and white for better detection
  image.loadNewImage("Temp.png");

  int constant = 90; // make a constant and save a value that based on it will compare the pixels intensity diff

  for (int i = 0; i < image.width; i++)
  {
    for (int j = 0; j < image.height; j++)
    {

      int intensity = 0;

      for (int k = 0; k < 3; k++)
      {
        intensity += abs(image(i, j, k) - image(i + 1, j + 1, k));
      }

      if (intensity > constant)
      {
        image(i, j, 0) = 0;
        image(i, j, 1) = 0;
        image(i, j, 2) = 0;
      }
      else
      {
        image(i, j, 0) = 240;
        image(i, j, 1) = 240;
        image(i, j, 2) = 240;
      }
    }
  }
  image.saveImage("Temp.png");
}

void filter11(Image image) // Resizing Images
{
  int newHeight, newWidth; // making variable for the new dimensions

  cout << "Enter new size (Width X Height) : ";

  cin >> newWidth >> newHeight;

  while (cin.fail() || newWidth <= 0 || newHeight <= 0) // validation
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid input\n Please enter valid pixel size (Width X Height): ";
    cin >> newWidth >> newHeight;
  }

  Image image2(newWidth, newHeight); // create an image with the new dimensions

  for (int i = 0; i < image2.width; i++)
  {
    for (int j = 0; j < image2.height; j++)
    {
      image2(i, j, 0) = image(i * image.width / image2.width, j * image.height / image2.height, 0); // editing the pixels and save it in the original image
      image2(i, j, 1) = image(i * image.width / image2.width, j * image.height / image2.height, 1);
      image2(i, j, 2) = image(i * image.width / image2.width, j * image.height / image2.height, 2);
    }
  }

  image2.saveImage("Temp.png");

  cout << "Current Image Updated Successfully! \n";
}

void filter12(Image image) // Blur Images
{

  Image image2(image.width, image.height);

  int radius = 20; // a constant that based on it will edit the width and height
  int kernelSize = 2 * radius + 1;

  int kernelArea = kernelSize * kernelSize;

  for (int i = radius; i < image.width - radius; i++)
  {
    for (int j = radius; j < image.height - radius; j++)
    {

      for (int k = 0; k < 3; k++)
      {
        int sum = 0;
        for (int x = -radius; x <= radius; x++)
        {
          for (int y = -radius; y <= radius; y++)
          {
            sum += image(i + x, j + y, k);
          }
        }
        image2(i, j, k) = sum / kernelArea;
      }
    }
  }

  image2.saveImage("Temp.png");
}

void filter13(Image image) // Sunlight Filter
{
  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {

      if (image(i, j, 0) + 38 < 255) // editing the colour red
      {
        image(i, j, 0) = image(i, j, 0) + 38;
      }
      else
      {
        image(i, j, 0) = 255;
      }

      if (image(i, j, 1) + 19 < 255) // editing the colour green
      {
        image(i, j, 1) = image(i, j, 1) + 19;
      }
      else
      {
        image(i, j, 1) = 255;
      }

      if (image(i, j, 2) - 15 < 255) // editing the colour blue
      {
        image(i, j, 2) = image(i, j, 1) - 15;
      }
      else
      {
        image(i, j, 2) = 255;
      }
    }
  }

  image.saveImage("Temp.png");
}

void filter16(Image image) // Purplescale Filter
{
  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {

      if (image(i, j, 0) + 12 <= 255) ////editing the colour red
      {
        image(i, j, 0) = image(i, j, 0) + 12;
      }
      else
      {
        image(i, j, 0) = 255;
      }

      if (image(i, j, 1) - 55 >= 0) // //editing the colour green
      {
        image(i, j, 1) = image(i, j, 1) - 55;
      }
      else
      {
        image(i, j, 1) = 0;
      }

      if (image(i, j, 2) + 8 <= 255) // editing the colour blue
      {
        image(i, j, 2) = image(i, j, 2) + 8;
      }
      else
      {
        image(i, j, 2) = 255;
      }
    }
  }

  image.saveImage("Temp.png");
}

void filter17(Image image) // Infrared filter
{
  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {
      for (int k = 0; k < 3; k++)
      {
        int red = 255;                         // save the red value in a variable
        image(i, j, 0) = red;                  // editing the colour red
        image(i, j, 1) = red - image(i, j, 1); // editing the colour green
        image(i, j, 2) = red - image(i, j, 2); // editing the colour blue
      }
    }
  }

  image.saveImage("Temp.png");
}

int main()
{
  string filename;
  ifstream file;
  Image image;
  int choiceM;
  int choiceE;

  //==========================================================================
  cout << "1)Load New Image\n2)Exit\n";
  cin >> choiceM;

  while (cin.fail() || choiceM < 1 || choiceM > 2)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid choice\n";
    cin >> choiceM;
  }

  if (choiceM == 2)
  {
    cout << "\n*** Thank You For Using the Program ***\n";
    exit(EXIT_SUCCESS);
  }

  //==========================================================================

  cout << "Enter the image name with the extention: ";

  // Checking the image file name

  cin >> filename;
  file.open(filename);

  while (!file.good())
  {
    cin.clear();
    cin.ignore();

    cout << "Invalid filename: " << filename << "\nCouldn't Load Image\nEnter the image name with the extention: ";
    cin >> filename;
    file.open(filename);
  }

  image.loadNewImage(filename);

  while (true)
  {
    choiceE = 0;
    int choice1;
    cout << "Choose a filter:\n1) Gray Scale\n2) Black & White\n3) Invert Colors\n4) Merge Images\n5) Flip Images\n6) Rotate Images\n7) Darken and Lighten Image\n8) Crop Images\n9) ِAdding a Frame to the Picture\n10) ِDetect Image Edges\n11) ِResizing Images\n12) Blur Images\n13) Sunlight filter\n14) Purplescale filter\n15) Infrared filter\n00) Exit Program\n";
    cin >> choice1;

    while (cin.fail() || choice1 < 0 || choice1 > 15)
    {
      cin.clear();
      cin.ignore();
      cout << "Invalid choice\nEnter a valid choice :";
      cin >> choice1;
    }

    switch (choice1)
    {

    case 1:
      filter1(image);
      break;

    case 2:
      filter2(image);
      break;

    case 3:
      filter3(image);
      break;

    case 4:
      filter4(image);
      break;

    case 5:
      filter5(image);
      break;

    case 6:
      filter6(image, filename);
      break;

    case 7:
      filter7(image);
      break;

    case 8:
      filter8(image);
      break;

    case 9:
      filter9(image);
      break;

    case 10:
      filter10(image);
      break;

    case 11:
      filter11(image);
      break;

    case 12:
      filter12(image);
      break;

    case 13:
      filter13(image);
      break;

    case 14:
      filter16(image);
      break;

    case 15:
      filter17(image);
      break;

    case 0:
      cout << "Do you want to save image before exit?\n1) Yes\n2) No\n";

      cin >> choiceE;

      while (cin.fail() || choiceE < 1 || choiceE > 2)
      {
        cin.clear();
        cin.ignore();
        cout << "Invalid choice\n";
        cin >> choiceE;
      }

      if (choiceE == 1)
      {
        saveImage(choiceE);
      }
      cout << "\n*** Thank You For Using the Program ***\n";
      exit(EXIT_SUCCESS);
      break;

    default:
      break;
    }

    int choice2;

    cout << "1) Import New Image\n2) Use Another Filter\n3) Save Current Image\n4) Exit\n";
    cin >> choice2;

    while (cin.fail() || choice2 < 1 || choice2 > 4)
    {
      cin.clear();
      cin.ignore();
      cout << "Invalid choice\n";
      cin >> choice2;
    }

    if (choice2 == 1)
    {
      cout << "Do you want to save image before add new image\n1) Yes\n2) No\n";

      cin >> choiceE;

      while (cin.fail() || choiceE < 1 || choiceE > 2)
      {
        cin.clear();
        cin.ignore();
        cout << "Invalid choice\n";
        cin >> choiceE;
      }

      if (choiceE == 1)
      {
        choiceE = 8;
        saveImage(choiceE);
      }
      main();
    }
    else if (choice2 == 2)
    {
      image.loadNewImage("Temp.png");
      continue;
    }
    else if (choice2 == 3)
    {
      saveImage(choiceE);
    }
    else
    {
      cout << "Do you want to save image before exit?\n1) Yes\n2) No\n";

      cin >> choiceE;

      while (cin.fail() || choiceE < 1 || choiceE > 2)
      {
        cin.clear();
        cin.ignore();
        cout << "Invalid choice\n";
        cin >> choiceE;
      }

      if (choiceE == 1)
      {
        saveImage(choiceE);
      }
      cout << "\n*** Thank You For Using the Program ***\n";
      exit(EXIT_SUCCESS);
    }
  }
  return 0;
}




