
#include "graph.hpp"

#include <iostream>

Graph::Graph(int width, int height, int maxDays, int maxPopulation,
             const std::vector<int>& S_values, const std::vector<int>& I_values,
             const std::vector<int>& R_values)
    : width(width),
      height(height),
      maxDays(maxDays),
      maxPopulation(maxPopulation),
      S_values(S_values),
      I_values(I_values),
      R_values(R_values) {
  font.loadFromFile("arial.ttf");

  xAxisLabel.setFont(font);
  xAxisLabel.setCharacterSize(16);
  xAxisLabel.setFillColor(sf::Color::Black);
  xAxisLabel.setPosition((width - xAxisLabel.getLocalBounds().width) / 2,
                         height - 20);
  xAxisLabel.setString("Giorno della simulazione");

  yAxisLabel.setFont(font);
  yAxisLabel.setCharacterSize(16);
  yAxisLabel.setFillColor(sf::Color::Black);
  yAxisLabel.setPosition(10, 10);
  yAxisLabel.setString("Popolazione");

  xAxis.setPrimitiveType(sf::Lines);
  xAxis.append(sf::Vertex(sf::Vector2f(50, height - 50), sf::Color::Black));
  xAxis.append(
      sf::Vertex(sf::Vector2f(width - 50, height - 50), sf::Color::Black));
  yAxis.setPrimitiveType(sf::Lines);
  yAxis.append(sf::Vertex(sf::Vector2f(50, height - 50), sf::Color::Black));
  yAxis.append(sf::Vertex(sf::Vector2f(50, 50), sf::Color::Black));

  for (int i = 0; i <= maxDays; i += maxDays / 10) {
    float xTickPos = static_cast<float>(i) / maxDays * (width - 100) + 50;
    sf::Text xLabel(std::to_string(i), font, 13);
    xLabel.setFillColor(sf::Color::Black);
    xLabel.setPosition(xTickPos - 10, height - 30);
    xLabels.push_back(xLabel);
  }

  for (int i = 0; i <= maxPopulation; i += maxPopulation / 5) {
    float yTickPos =
        height - static_cast<float>(i) / maxPopulation * (height - 100) - 50;
    sf::Text yLabel(std::to_string(i), font, 13);
    yLabel.setFillColor(sf::Color::Black);
    yLabel.setPosition(10, yTickPos - 10);
    yLabels.push_back(yLabel);
  }
}

void Graph::run() {
  window.create(sf::VideoMode(width, height), "Grafico SIR");

  window.clear(sf::Color::White);

  sf::VertexArray graphS(sf::LineStrip, S_values.size());
  sf::VertexArray graphI(sf::LineStrip, I_values.size());
  sf::VertexArray graphR(sf::LineStrip, R_values.size());

  for (size_t i = 0; i < S_values.size(); ++i) {
    float x = static_cast<float>(i) / S_values.size() * (width - 100) + 50;
    float yS =
        static_cast<float>(S_values[i]) / maxPopulation * (height - 100) + 50;
    float yI =
        static_cast<float>(I_values[i]) / maxPopulation * (height - 100) + 50;
    i float yR =
        static_cast<float>(R_values[i]) / maxPopulation * (height - 100) + 50;

    graphS[i] = sf::Vertex(sf::Vector2f(x, height - yS), sf::Color::Blue);
    graphI[i] = sf::Vertex(sf::Vector2f(x, height - yI), sf::Color::Red);
    graphR[i] = sf::Vertex(sf::Vector2f(x, height - yR), sf::Color::Green);

    for (const auto& xLabel : xLabels) {
      window.draw(xLabel);
    }

    for (const auto& yLabel : yLabels) {
      window.draw(yLabel);
    }
  }

  window.draw(xAxis);
  window.draw(yAxis);

  window.draw(graphS);
  window.draw(graphI);
  window.draw(graphR);

  window.draw(xAxisLabel);
  window.draw(yAxisLabel);

  window.display();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
}
