#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "shapes.h"


int main()
{
  std::cout << 
  "1 : gradient" << std::endl <<
  "2 : soft_circle" << std::endl <<
  "3 : soft_square" << std::endl <<
  "4 : soft_star" << std::endl <<
  "5 : star" << std::endl <<
  "6 : sin texture" << std::endl <<
  "7 : soft_grid" << std::endl;
  
  sf::RenderWindow window(sf::VideoMode(800, 600), "Textures");
  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;
  
  image.create(800, 600);
  
  int attribute = 0;
  int axis = 0;
  
  int positionX = 400;
  int positionY = 300;
  int sizeX = 50;
  int sizeY = 50;
  
  shapes::gradient(image);
  texture.loadFromImage(image);
  sprite.setTexture(texture);
  
  // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
  while (window.isOpen())
  {
    // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
    sf::Event event;
    while (window.pollEvent(event))
    {
      // évènement "fermeture demandée" : on ferme la fenêtre
      if (event.type == sf::Event::Closed)
        window.close();
        
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        shapes::gradient(image);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        shapes::soft_circle(image, positionX, positionY, sizeX, sizeY);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        shapes::soft_square(image);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        shapes::soft_star(image);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
        shapes::star(image);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
        shapes::sinTex(image);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
        shapes::soft_grid(image);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      }
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        attribute = 0;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        attribute = 1;
      }
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        axis = 0;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        axis = 1;
      }
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        switch (attribute) {
          case 0:
            if (!axis) {
              positionX += 2;
            } else {
              positionY -= 2;
            }
            break;
          case 1:
            if (!axis) {
              sizeX += 2;
            } else {
              sizeY += 2;
            }
            break;
        }
        shapes::soft_circle(image, positionX, positionY, sizeX, sizeY);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        switch (attribute) {
          case 0:
            if (!axis) {
              positionX -= 2;
            } else {
              positionY += 2;
            }
            break;
          case 1:
            if (!axis) {
              sizeX -= 2;
            } else {
              sizeY -= 2;
            }
            break;
        }
        shapes::soft_circle(image, positionX, positionY, sizeX, sizeY);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      }
    }
    
    window.clear();
    
    window.draw(sprite);
    window.display();
  }

  return 0;
}