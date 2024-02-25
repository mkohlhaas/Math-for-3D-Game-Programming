void LURefineSolution(int n, const float *m, const float *d,
                      const unsigned short *index, const float *r, float *x) {
  float *t = new float[n];

  for (int i = 0; i < n; i++) {
    double q = -r[i];
    for (int k = 0; k < n; k++)
      q += m[k * n + i] * x[k];
    t[i] = (float)q;
  }

  LUBacksubstitute(n, d, index, t, t);
  for (int i = 0; i < n; i++)
    x[i] -= t[i];

  delete[] t;
}
