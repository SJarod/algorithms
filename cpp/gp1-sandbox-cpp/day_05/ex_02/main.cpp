#include <iostream>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "compound_shape.h"

int main()
{
    std::cout << "Rectangle : " << std::endl;

    {
        rectangle r( 0.5f, // scale
        2.0f, // width
        3.0f); // height
        const shape& s = r;
        std::cout << "Shape base area : " << s.get_base_area() << std::endl;
        std::cout << "Shape scaled area : " << s.get_area() << std::endl;
        std::cout << "Rectangle width : " << r.get_width() << ", height : " << r.get_height() << std::endl;
    }

    std::cout << std::endl << "Circle : " << std::endl;

    {
        circle c( 2.0f, // scale
        1.0f ); // radius
        const shape& s = c;
        std::cout << "Shape base area : " << s.get_base_area() << std::endl;
        std::cout << "Shape scaled area : " << s.get_area() << std::endl;
        std::cout << "Circle radius : " << c.get_radius() << std::endl;
    }

    std::cout << std::endl << "Compound shape : " << std::endl;

    {
        compound_shape cs( 3.0f, // scale
        2 ); // number of shape
        std::cout << std::endl << "Shape base area : " << cs.get_base_area() << std::endl;
        std::cout << "Shape scaled area : " << cs.get_area() << std::endl;
        cs.set_shape(0, new rectangle(0.5f, 2.0f, 3.0f));
        std::cout << std::endl << "Shape base area : " << cs.get_base_area() << std::endl;
        std::cout << "Shape scaled area : " << cs.get_area() << std::endl;
        cs.set_shape(1, new circle(2.0f, 1.0f));
        std::cout << std::endl << "Shape base area : " << cs.get_base_area() << std::endl;
        std::cout << "Shape scaled area : " << cs.get_area() << std::endl << std::endl;
    }
    
    return EXIT_SUCCESS;
}