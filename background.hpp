#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_

#include "abcgOpenGL.hpp"

struct VertexBG {
  glm::vec3 position{};

  friend bool operator==(VertexBG const &, VertexBG const &) = default;
};

class Background {
public:
  void loadObj(std::string_view path, bool standardize = true);
  void render(int numTriangles = -1) const;
  void setupVAO(GLuint program);
  void destroy() const;

  [[nodiscard]] int getNumTriangles() const {
    return gsl::narrow<int>(m_indices.size()) / 3;
  }

private:
  GLuint m_VAO{};
  GLuint m_VBO{};
  GLuint m_EBO{};

  std::vector<VertexBG> m_vertices;
  std::vector<GLuint> m_indices;

  void createBuffers();
  void standardize();
};

#endif