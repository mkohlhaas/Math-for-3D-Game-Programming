struct Edge {
  unsigned short vertexIndex[2];
  unsigned short faceIndex[2];
};

struct Triangle {
  unsigned short index[3];

  void Set(unsigned long i1, unsigned long i2, unsigned long i3) {
    index[0] = (unsigned short)i1;
    index[1] = (unsigned short)i2;
    index[2] = (unsigned short)i3;
  }
};
