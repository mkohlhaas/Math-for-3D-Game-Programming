void LoadOffsetMatrix(float l, float r, float b, float t, float n, float f,
                      float delta, float pz) {
  float matrix[16];

  // Set up standard perspective projection.
  glMatrixMode(GL_PROJECTION);
  glFrustum(l, r, b, t, n, f);

  // Retrieve the projection matrix.
  glGetFloatv(GL_PROJECTION_MATRIX, matrix);

  // Calculate epsilon with Equation (9.7).
  float epsilon = �2.0F * f * n * delta / ((f + n) * pz * (pz + delta));

  // Modify entry (3,3) of the projection matrix.
  matrix[10] *= 1.0F + epsilon;

  // Send the projection matrix back to OpenGL.
  glLoadMatrix(matrix);
}
