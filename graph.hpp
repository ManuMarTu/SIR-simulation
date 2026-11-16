#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Graph {
 public:
  Graph(int width, int height, int maxDays, int maxPopulation,
        const std::vector<int>& S_values, const std::vector<int>& I_values,
        const std::vector<int>& R_values);

  void run();

 private:
  int width, height;
  int maxDays, maxPopulation;
  const std::vector<int>& S_values;
  const std::vector<int>& I_values;
  const std::vector<int>& R_values;
  sf::RenderWindow window;
  sf::Font font;

  sf::Text xAxisLabel;
  sf::Text yAxisLabel;
  sf::VertexArray xAxis;
  sf::VertexArray yAxis;

  std::vector<sf::Text> xLabels;

  std::vector<sf::Text> yLabels;
  sf::VertexArray graphS;
  sf::VertexArray graphI;
  sf::VertexArray graphR;
};

#endif