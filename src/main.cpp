#include <iostream>
#include <fstream>
#include <lacze_do_gnuplota.hh>
#include <utility>
#include "Matrix.h"
#include "Cuboid.h"
#include "Vector.h"
#include "GnuplotDrawings.h"
#define Vector Vector<double, 3>

void menuDisplay();

int main(int argc, char** argv) {
    /* Initialize Cuboid and translation vector and sides pair*/
    Vector Ver0 = Vector(0,1,1);
    Vector Ver1 = Vector(5,1,1);
    Vector Ver2 = Vector(5,1,4);
    Vector Ver3 = Vector(0,1,4);

    Vector Ver4 = Vector(0,9,1);
    Vector Ver5 = Vector(5,9,1);
    Vector Ver6 = Vector(5,9,4);
    Vector Ver7 = Vector(0,9,4);

    Vector vertices[VERTICES_NUMBER] = {Ver0, Ver1, Ver2, Ver3, Ver4, Ver5, Ver6, Ver7};
    Cuboid<double> cub = Cuboid<double>(vertices);

    Vector translation;
    /* Initialize "Lacze do gnuplota" to work with */
    std ::string file ="../data/data.txt";
    double XRange[2] = {-10, 10};
    double YRange[2] = {-10, 10};
    double ZRange[2] = {-10, 10};
    GnuplotDrawings gnu = GnuplotDrawings(file, XRange, YRange, ZRange);
    /* Drawing initial rectangle and display menu*/
    menuDisplay();

    double degree, amountOfRotation;
    char c = ' ';
    while(c != 'k'){
        gnu.drawCuboid(cub);
        if(!(std::cin >> c)){
            throw std::exception();
        }
        switch (c) {
            case 'm':
                menuDisplay();
                break;
            case 'o':
                std::cout << "enter rotation angle by degree:\n";
                std::cin >> degree;
                std::cout << "enter amount of rotation:\n";
                std::cin >> amountOfRotation;
                degree *= amountOfRotation;
                gnu.animateRotateRectangle(cub, degree, 'z');
                std::cout << "You chose: '"<< c << "' (m-menu)\n";
                break;
            case 'p':
                std::cin >> translation;
                gnu.animateTranslateRectangle(cub,translation);
                std::cout << "You chose: '"<< c << "' (m-menu)\n";
                break;
            case 'w':
                std::cout << cub;
                break;
            case 'k':
                break;
            case 'l':
                cub.calculateSidesLength();
                std::cout << "shorter side: " << cub.getSideLength(0) << std::endl;
                std::cout << "longer side: " << cub.getSideLength(5) << std::endl;
                break;
            default:
                std::cout << "unknown argument, pleas use correct arguments\n";
                break;
        }
        std::cout << "You chose: '"<< c << "' (m-menu)\n";


    }
}

void menuDisplay(){
  std::cout << "o - rotate rectangle by angle in degree\n";
  std::cout << "p - translate rectangle by vector\n";
  std::cout << "w - display coordinates of rectangle vertices\n";
  std::cout << "m - display menu\n";
  std::cout << "k - close\n";
  std::cout << "l - display length of sides\n";
}

