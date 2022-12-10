/*
The philosophy behind the inheritance used in this code is that there are a few base classes that the rest of the 
objects inherit from. These classes don't interfere with each other so we can inherit from as many of them as we want 
depending on the needs of an object. These three classes are Shape, Filled and textLabelled. The virtual keyword is used to ensure runtime polymorphism.
If the test document demanded it classes could be made for filled text circle and such. I put the constructors in the header file because it think its cleaner
and more readable but they could just as easily be in the implementation file. 
*/

#include<string>

class Shape {
    private:
        int length;
        int width;
    protected: // protected so inherited classes have access
        std::string borderColor;
        virtual void drawBorder() = 0; // marked with = 0 to show it is a pure virtual function, there is no implementation in the base class   
    public: 
        Shape(const int width, const int length, const std::string borderColor); // contructor with text option
        virtual ~Shape() {}; // virtual destructors ensure inherited classes get dealt with properly when they go out of scope
        virtual void draw() = 0;
};


class Filled {
    protected:
        std::string fillColor;
        virtual void fill() = 0; 
    public:
        Filled(const std::string);
        virtual ~Filled() {};
};



class TextLabelled {
    protected:
        std::string textLabel;
        virtual void drawText() = 0;    
    public:
        TextLabelled(std::string);
        virtual ~TextLabelled() {};
};


class Square : public Shape {
    protected:
        virtual void drawBorder();    
    public:
        Square(const int length, const int width, const std::string borderColor) : Shape(length, width, borderColor) {}; // use base class constructor
        ~Square() = default; // all classes must have destructors
        virtual void draw() {
            drawBorder(); // base level draw method calls runtime binding drawBorder function
        }
};


class FilledSquare : public Square, Filled {
    protected:
        virtual void fill();
    public:
        FilledSquare(const int length, const int width, const std::string borderColor, const std::string fillColor) 
                    : Square(length, width, borderColor), Filled(fillColor) {}; // use both base class contructors
        ~FilledSquare() = default;
        virtual void draw() {
            drawBorder(); // same idea as drawBorder method
            fill();
        }
};


class FilledTextSquare : public FilledSquare, TextLabelled { // an extension of filledSquare that also has a text option
    protected:
        virtual void drawText();
    public:
        FilledTextSquare(const int length, const int width, const std::string borderColor, const std::string fillColor, const std::string textLabel)
                        : FilledSquare(length, width, borderColor, fillColor), TextLabelled(textLabel) {};
        ~FilledTextSquare() = default;
        virtual void draw() {
            drawBorder();
            fill();
            drawText();
        }
};


class Circle : public Shape {
    protected:
        virtual void drawBorder();
    public:
        Circle(const int length, const int width, const std::string borderColor) : Shape(length, width, borderColor) {};
        ~Circle() = default;
        virtual void draw() {
            drawBorder();
        }
};


class FilledCircle : public Circle, Filled {
    protected:
        virtual void fill();
    public:
        FilledCircle(const int length, const int width, const std::string borderColor, const std::string fillColor) 
                    : Circle(length, width, borderColor), Filled(fillColor) {}; 
        ~FilledCircle() = default;
        virtual void draw() {
            drawBorder();
            fill();
        }
};


class Arc : public Shape { 
    protected:
        virtual void drawBorder();
    public:
        Arc(const int length, const int width, const std::string borderColor) : Shape(length, width, borderColor) {};
        ~Arc() = default;
        virtual void draw() {
            drawBorder();
        }
};