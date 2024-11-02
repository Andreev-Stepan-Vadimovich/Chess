#include "App.h"
#include <SFML/Graphics.hpp>


int main() {
	App MyApp;
	MyApp.StartApp();
}

//using namespace sf;
//
//int main()
//{
//
//    RenderWindow window(VideoMode(1600, 1200), L"Games!", Style::Default);
//
//    window.setVerticalSyncEnabled(true);
//
//    CircleShape shape(100.f, 3);
//    shape.setPosition(100, 100);
//    shape.setFillColor(Color::Magenta);
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        window.clear(Color::Black);
//        window.draw(shape);
//        window.display();
//    }
//    return 0;
//}