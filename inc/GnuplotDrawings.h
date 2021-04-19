//
// Created by artur on 4/11/21.
//

#ifndef ROTATION2D_GNUPLOTDRAWINGS_H
#define ROTATION2D_GNUPLOTDRAWINGS_H
#include <unistd.h>
#include "Rectangle.h"
#include <lacze_do_gnuplota.hh>
#include <fstream>

class GnuplotDrawings{
private:
    std::string fileName;
    PzG::LaczeDoGNUPlota GNU;
    double XRange[2];
    double YRange[2];

public:
    GnuplotDrawings();
    GnuplotDrawings(std::string _fileName, double _XRange[2], double _YRange[2]);
    void drawRectangle(Rectangle &Rec);
    void drawVector(Vector &Vec);
    void animateRotateRectangle(Rectangle &Rec, double &degree);
    void animateTranslateRectangle(Rectangle &Rec, Vector &translation);
};

#endif //ROTATION2D_GNUPLOTDRAWINGS_H
