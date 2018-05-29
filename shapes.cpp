#include "shapes.h"
#include <cmath>

namespace shapes {
  
  /*void gradient(sf::Image& image) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int c = (int)(x*255/800);
        if (c < 0) {
          c = 0;
        }
        if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }*/
  
  void gradient(sf::Image& image) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int c = (int)(tan(x / 100.0) * 128 + 128);
        if (c < 0) {
          c = 0;
        }
        if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }
  
  void soft_circle(sf::Image& image, int positionX, int positionY, int sizeX, int sizeY) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int dx = x - positionX;
        int dy = y - positionY;
        dx = abs(dx);
        dy = abs(dy);
        int c = 255-(dx*dx)/sizeX-(dy*dy)/sizeY;
        if (c < 0) {
          c = 0;
        }
        if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }
  
  void soft_square(sf::Image& image) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int dx = x - 400;
        int dy = y - 300;
        dx = abs(dx);
        dy = abs(dy);
        int c = 255-(dx*dx*dx)/100-(dy*dy*dy)/100;
        if (c < 0) {
          c = 0;
        }
        if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }
  
  void soft_star(sf::Image& image) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int dx = x - 400;
        int dy = y - 300;
        dx = abs(dx);
        dy = abs(dy);
        int c = 255-(dx)-(dy);
        if (c < 0) {
          c = 0;
        }
        if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }
  
  void star(sf::Image& image) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int dx = x - 400;
        int dy = y - 300;
        if (dy < 0) {
          dy *= -1;
        }
        if (dx < 0) {
          dx *= -1;
        }
        int c = (int)((255/((dx+50.0)/50))/((dy+25.0)/25))+(int)((255/((dy+50.0)/50))/((dx+25.0)/25));
        if (c < 0) {
          c = 0;
        } else if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }
  
  void sinTex(sf::Image& image) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int c = (int)(sin(x/10.0)*128 + 128);
        if (c < 0) {
          c = 0;
        }
        if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }
  
  void soft_grid(sf::Image& image) {
    for (size_t x = 0; x < 800; x++) {
      for (size_t y = 0; y < 600; y++) {
        int c = (sin(x/10.0)+sin(y/10.0)) * 64 + 128;
        if (c < 0) {
          c = 0;
        }
        if (c > 255) {
          c = 255;
        }
        image.setPixel(x, y, sf::Color(c,c,c));
      }
    }
  }
  
}
