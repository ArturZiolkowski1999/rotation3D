#include <iostream>
#include <fstream>
#include <lacze_do_gnuplota.hh>
#include <utility>
#include "Matrix.h"
#include "cuboid.h"
#include "Vector.h"
#include "GnuplotDrawings.h"

void menuDisplay();

int main(int argc, char** argv) {
    /* Initialize Rectangle and translation vector and sides pair*/
//    Vector ver1 = Vector(1,1);
//    Vector ver2 = Vector(11,1);
//    Vector ver3 = Vector(11,6);
//    Vector ver4 = Vector(1,6);
//    Rectangle rec = Rectangle(ver1, ver2, ver3, ver4);
//    Vector translation;
//    std::pair <double, double> sides;
//    /* Initialize "Lacze do gnuplota" to work with */
//    std ::string file ="../data/xd.txt";
//    double XRange[2] = {-30, 30};
//    double YRange[2] = {-30, 30};
//    GnuplotDrawings gnu = GnuplotDrawings(file, XRange, YRange);
//    /* Drawing initial rectangle and display menu*/
//    menuDisplay();
//
//    double degree, amountOfRotation;
//    char c = ' ';
//    while(c != 'k'){
//        gnu.drawRectangle(rec);
//        if(!(std::cin >> c)){
//            throw std::exception();
//        }
//        switch (c) {
//            case 'm':
//                menuDisplay();
//                break;
//            case 'o':
//                std::cout << "enter rotation angle by degree:\n";
//                std::cin >> degree;
//                std::cout << "enter amount of rotation:\n";
//                std::cin >> amountOfRotation;
//                degree *= amountOfRotation;
//                gnu.animateRotateRectangle(rec, degree);
//                std::cout << "You chose: '"<< c << "' (m-menu)\n";
//                break;
//            case 'p':
//                std::cin >> translation;
//                gnu.animateTranslateRectangle(rec,translation);
////                rec.translationByVector(translation);
//                std::cout << "You chose: '"<< c << "' (m-menu)\n";
//                break;
//            case 'w':
//                std::cout << rec;
//                break;
//            case 'k':
//                break;
//            case 'l':
//                sides = rec.getSidesLength(rec[0], rec[1], rec[2], rec[3]);
//                std::cout << "shorter side: " << sides.second << std::endl;
//                std::cout << "longer side: " << sides.first << std::endl;
//                break;
//            default:
//                std::cout << "unknown argument, pleas use correct arguments\n";
//                break;
//        }
//        std::cout << "You chose: '"<< c << "' (m-menu)\n";
//
//
//    }
}

void menuDisplay(){
  std::cout << "o - rotate rectangle by angle in degree\n";
  std::cout << "p - translate rectangle by vector\n";
  std::cout << "w - display coordinates of rectangle vertices\n";
  std::cout << "m - display menu\n";
  std::cout << "k - close\n";
  std::cout << "l - display length of sides\n";
}

