void LUBacksubstitute(int n, const float *d, const unsigned short *index,
                      const float *r, float *x) {
  for (int i = 0; i < n; i++)
    x[i] = r[index[i]];

  // Perform forward substitution for Ly = r.
  for (int i = 0; i < n; i++) {
    float sum = x[i];
    for (int k = 0; k < i; k++)
      sum -= d[k * n + i] * x[k];
    x[i] = sum;
  }

  // Perform backward substitution for Ux = y.
  for (int i = n - 1; i >= 0; i--) {
    float sum = x[i];
    for (int k = i + 1; k < n; k++)
      sum -= d[k * n + i] * x[k];
    x[i] = sum / d[i * n + i];
  }
}
