#include "shapesGood.h"
#include <iostream>

Shape::Shape(const int lengthIn, const int widthIn, const std::string borderColorIn) {
    length = lengthIn;
    width = widthIn;
    borderColor = borderColorIn;
}


Filled::Filled(const std::string fillColorIn) {
    fillColor = fillColorIn;
}


TextLabelled::TextLabelled(const std::string shapeTextIn) {
    textLabel = shapeTextIn;
}


void Square::drawBorder() {
    std::cout <<"\nDrawing a " + borderColor + " square.";
}

void FilledSquare::fill() {
    std::cout <<" With " + fillColor + " fill.";
}

void FilledTextSquare::drawText() {
    std::cout <<" Containing the text: \"" << textLabel << "!\"";
}


void Circle::drawBorder() {
    std::cout <<"\nDrawing a " + borderColor + " circle.";
}

void FilledCircle::fill() {
    std::cout <<" With " + fillColor + " fill.";
}


void Arc::drawBorder() {
    std::cout << "\nDrawing a " + borderColor + " arc.";
}