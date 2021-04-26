//
// Created by artur on 4/11/21.
//
#include "GnuplotDrawings.h"

GnuplotDrawings::GnuplotDrawings() {
    GNU.ZmienTrybRys(PzG::TR_3D);
    this->fileName = "";
    this->XRange[0] = 0;
    this->XRange[1] = 0;
    this->YRange[0] = 0;
    this->YRange[1] = 0;
}

GnuplotDrawings::GnuplotDrawings(std::string _fileName, double _XRange[2], double _YRange[2]) {
    this->fileName = _fileName;
    this->XRange[0] = _XRange[0];
    this->XRange[1] = _XRange[1];
    this->YRange[0] = _YRange[0];
    this->YRange[1] = _YRange[1];
    GNU.DodajNazwePliku(this->fileName.c_str());
    GNU.UstawZakresX((this->XRange[0]),(this->XRange[1]));
    GNU.UstawZakresY((this->YRange[0]),(this->YRange[1]));
}

void GnuplotDrawings::drawRectangle(Cuboid &Rec){
    std::ofstream os;
    os.open(this->fileName);
    if(!os){
        throw std::exception();
    }
    os << Rec;
    os << Rec[0];
    os.close();
    GNU.Inicjalizuj();
    GNU.Rysuj();

}

void GnuplotDrawings::drawVector(Vector &Vec){
    std::ofstream os;
    os.open(this->fileName);
    if(!os){
        throw std::exception();
    }
    os << Vec;
    os << 0 << " " << 0;
    GNU.Inicjalizuj();
    GNU.Rysuj();
    os.close();
}

void GnuplotDrawings::animateRotateRectangle(Cuboid &Rec, double &degree) {
    Cuboid animateRec = Rec;
    double singleDegree = 0;
    while (std::abs(singleDegree) < std::abs(degree)){
        singleDegree += 2;
        if(degree >= 0){
            animateRec.rotationByDegrees(2);
        }else{
            animateRec.rotationByDegrees(-2);
        }
        usleep(ANIMATION_SPEED);
        drawRectangle(animateRec);
    }
    Rec.rotationByDegrees(degree);
    drawRectangle(Rec);
}

void GnuplotDrawings::animateTranslateRectangle(Cuboid &Rec, Vector &translation) {
    Cuboid animateRec = Rec;
    Vector animateTranslation = translation/translation.getLength();
    Vector unityTranslation = translation/translation.getLength();
    unityTranslation = unityTranslation/RESOLUTION;
    double i = 0;
    while (animateTranslation.getLength() < translation.getLength()){
        i++;
        animateTranslation = unityTranslation * i;
        animateRec.translationByVector(animateTranslation);
        usleep(ANIMATION_SPEED);
        drawRectangle(animateRec);
        animateTranslation = animateTranslation + unityTranslation;
        animateRec = Rec;
    }
    Rec.translationByVector(translation);
    drawRectangle(Rec);
}
