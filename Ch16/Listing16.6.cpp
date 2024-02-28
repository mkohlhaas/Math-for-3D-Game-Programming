void SolveTridiagonalSystem(int n, const float *a, const float *b,
                            const float *c, const float *r, float *x) {
  // Allocate temporary storage for c[i]/beta[i].
  float *t = new float[n - 1];

  float recipBeta = 1.0F / b[0];
  x[0] = r[0] * recipBeta;

  for (int i = 1; i < n; i++) {
    t[i - 1] = c[i - 1] * recipBeta;
    recipBeta = 1.0F / (b[i] - a[i] * t[i - 1]);
    x[i] = (r[i] - a[i] * x[i - 1]) * recipBeta;
  }

  for (int i = n - 2; i >= 0; i--)
    x[i] -= t[i] * x[i + 1];

  delete[] t;
}
