/*
 FCAI – Structured Programming – 2024 - Assignment 3 - Part 1

 Program Name: CS112_A3_Part1_S4_20230362_20230446_20230291.cpp.

 Program Description: Baby Photoshop

 Last Modification Date: 27/3/2024

 Author1 and ID and Group: Mohammad Walid Abdulmotal  -  (20230362)
 Author2 and ID and Group: Nour Maged Mahmoud Abdel-Aal  -  (20230446)
 Author3 and ID and Group: Karen Fady Nabil Tawfik  -  (20230291)

 Teaching Assistant: Eng. Ahmed Fouad Lotfy

 Who did what:

 Mohammad Walid Abdulmotal - Filter 2 - Filter 5
 Nour Maged Mahmoud Abdel-Aal - Filter 3
 Karen Fady Nabil Tawfik -  Filter 1 - Filter 4
*/

#include <iostream>
#include "Image_Class.h"
using namespace std;

void filter1(Image image)
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

      avg = avg / 3;
      image(i, j, 0) = avg;
      image(i, j, 1) = avg;
      image(i, j, 2) = avg;
    }
  }
  cout << "Please enter image name to store new image\n";
  cout << "and specify extension .jpg, .bmp, .png, .tga: ";
  string filename;
  cin >> filename;
  image.saveImage(filename);
}

void filter2(Image image)
{
  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {
      unsigned int avg = 0;

      for (int k = 0; k < 3; ++k)
      {
        avg += image(i, j, k);
      }

      avg /= 3;

      if (avg < 128)
        avg = 0;
      else
        avg = 255;

      image(i, j, 0) = avg;
      image(i, j, 1) = avg;
      image(i, j, 2) = avg;
    }
  }
  cout << "Please enter image name to store new image\n";
  cout << "and specify extension .jpg, .bmp, .png, .tga: ";
  string filename;
  cin >> filename;
  image.saveImage(filename);
}

void filter3(Image image)
{
  for (int i = 0; i < image.width; ++i)
  {
    for (int j = 0; j < image.height; ++j)
    {
      unsigned int invertedR = 255 - image(i, j, 0);
      unsigned int invertedG = 255 - image(i, j, 1);
      unsigned int invertedB = 255 - image(i, j, 2);

      image(i, j, 0) = invertedR;
      image(i, j, 1) = invertedG;
      image(i, j, 2) = invertedB;
    }
  }
  cout << "Please enter image name to store new image\n";
  cout << "and specify extension .jpg, .bmp, .png, .tga: ";
  string filename;
  cin >> filename;
  image.saveImage(filename);
}

void filter4(Image image)
{
  string filename2;

  cout << "Please enter the file name of the second image: ";

  cin >> filename2;

  Image image2(filename2);

  double avgwidth = double(image.width) / image2.width;
  double avgheight = double(image.height) / image2.height;

  Image merge(image.width, image.height);
  Image final(image.width, image.height);

  for (int i = 0; i < image.width; i++)
  {
    for (int j = 0; j < image.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        int z = int(i / avgwidth);
        int m = int(j / avgheight);

        z = min(z, image2.width - 1);
        m = min(m, image2.height - 1);

        merge(i, j, k) = image2(z, m, k);
      }
    }
  }
  for (int i = 0; i < image.width; i++)
  {
    for (int j = 0; j < image.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        unsigned char pix1 = image(i, j, k);
        unsigned char pix2;
        if (i < merge.width && j < merge.height)
        {
          pix2 = merge(i, j, k);
        }
        else
        {
          pix2 = 0;
        }
        final(i, j, k) = (pix1 + pix2) / 2;
      }
    }
  }
  cout << "Please enter image name to store new image\n";
  cout << "and specify extension .jpg, .bmp, .png, .tga: ";
  string newFile;
  cin >> newFile;
  final.saveImage(newFile);
}

void filter5(Image image)
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
      for (int j = 0; j < image.height / 2; ++j)
      {
        unsigned int avg = 0; // Initialize average value

        for (int k = 0; k < 3; ++k)
        {
          unsigned char temp = image(i, j, k);
          image(i, j, k) = image(i, image.height - 1 - j, k);
          image(i, image.height - 1 - j, k) = temp;
        }
      }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
  }
  else
  {
    string filename;
    for (int i = 0; i < image.width / 2; ++i)
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

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
  }
}

void filter9(Image image)
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
  else if (choiceC == 2)
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
      image(i, image.height - image.width * (2.04 / 100) - x, 2) = color1;
      image(i, image.height - image.width * (2.04 / 100) - x, 1) = color2;
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

  cout << "Pls enter image name to store new image\n";
  cout << "and specify extension .jpg, .bmp, .png, .tga: ";

  cin >> fileName;
  image.saveImage(fileName);
}

void filter8(Image image)
{
  int x, y, w, h;
  cout << "Please enter colored image name to turn to gray scale: ";
  cin >> fileName;

  cout << "\nEnter the Center point X,Y : ";
  cin >> x >> y;

  cout << "\nEnter the Dimention W,H : ";
  cin >> w >> h;

  Image image(fileName);
  Image image2(w, h);

  for (int i = x; i < w + x; ++i)
  {
    for (int j = y; j < h + y; ++j)
    {

      image2(i - x, j - y, 0) = image(i, j, 0);
      image2(i - x, j - y, 1) = image(i, j, 1);
      image2(i - x, j - y, 2) = image(i, j, 2);
    }
  }

  cout << "Pls enter image name to store new image\n";
  cout << "and specify extension .jpg, .bmp, .png, .tga: ";

  cin >> fileName;
  image2.saveImage(fileName);
}

void filter11(Image image)
{
  int newHeight, newWidth;

  cout << "Enter new size (Width X Height) : ";

  cin >> newWidth >> newHeight;

  while (cin.fail() || newWidth <= 0 || newHeight <= 0)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid input\n Please enter valid pixel size (Width X Height): ";
    cin >> newWidth >> newHeight;
  }

  Image image2(newWidth, newHeight);

  for (int i = 0; i < image2.width; i++)
  {
    for (int j = 0; j < image2.height; j++)
    {
      image2(i, j, 0) = image(i * image.width / image2.width, j * image.height / image2.height, 0);
      image2(i, j, 1) = image(i * image.width / image2.width, j * image.height / image2.height, 1);
      image2(i, j, 2) = image(i * image.width / image2.width, j * image.height / image2.height, 2);
    }
  }

  cout << "Pls enter image name to store new image\n";
  cout << "and specify extension .jpg, .bmp, .png, .tga: ";

  cin >> fileName;
  image2.saveImage(fileName);
}

int main()
{
  string filename;
  cout << "Enter the image name with the extention: ";
  cin >> filename;
  int choice1;
  Image image(filename);
  cout << "Choose a filter:\n1) Gray Scale\n2) Black & White\n3) Invert Colors\n4) Merge Images\n5) Flip Images\n6) Rotate Images\n";
  cin >> choice1;
  while (cin.fail() || choice1 < 1 || choice1 > 6)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid choice\n";
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
  case 8:
    filter8(image);
    break;
  case 9:
    filter9(image);
    break;
  case 11:
    filter11(image);
    break;

  default:
    break;
  }
  int choice2;
  cout << "The image saved successfully\n";
  cout << "1) Import New Image\n2) Exit\n";
  cin >> choice2;
  while (cin.fail() || choice2 < 1 || choice2 > 2)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid choice\n";
    cin >> choice2;
  }
  if (choice2 == 1)
  {
    main();
  }
  else
  {
    exit(EXIT_SUCCESS);
  }

  return 0;
}