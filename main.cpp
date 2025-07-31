#include <SFML/Graphics.hpp>

int main() {
  // Render Window
  unsigned screen_x = 800;
  unsigned screen_y = 800;
  sf::RenderWindow window(sf::VideoMode({screen_x, screen_y}), "Volley Pong");

  // Create Ball
  float radius = 10.0;
  float centre_x = screen_x / 2 - radius;
  float centre_y = screen_y / 2 - radius;

  float ball_position_x = centre_x;
  float ball_position_y = centre_y;
  const float gravity = 0.00001;
  float mass = 1.0;
  float velocity_y = 0;
  sf::CircleShape ball;
  ball.setRadius(10);
  ball.setOutlineColor(sf::Color::Red);
  ball.setOutlineThickness(5);
  ball.setPosition({centre_x, centre_y});

  // main loop
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      // Close window: exit
      if (event->is<sf::Event::Closed>())
        window.close();
    }
    window.clear();
    // ball physics
    velocity_y += gravity;
    if (ball_position_y + 2 * radius >= screen_x) {
      velocity_y = -1 * velocity_y;
    }
    ball_position_y += velocity_y;
    ball.setPosition({ball_position_x, ball_position_y});

    window.draw(ball);

    window.display();
  }
  return 0;
}
