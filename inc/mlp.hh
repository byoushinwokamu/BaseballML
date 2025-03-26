#ifndef __MLP_HH__
#define __MLP_HH__

#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

double random_weight() {
  return ((double)rand() / RAND_MAX) * 2 - 1; // -1 ~ 1 사이 값
}

vector<double> relu(const vector<double> &x) {
  vector<double> result(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    result[i] = max(0.0, x[i]);
  }
  return result;
}

vector<double> matmul(const vector<vector<double>> &W,
                      const vector<double> &x) {
  vector<double> result(W.size(), 0.0);
  for (size_t i = 0; i < W.size(); i++) {
    for (size_t j = 0; j < x.size(); j++) {
      result[i] += W[i][j] * x[j];
    }
  }
  return result;
}

vector<double> add(const vector<double> &a, const vector<double> &b) {
  vector<double> result(a.size());
  for (size_t i = 0; i < a.size(); i++) {
    result[i] = a[i] + b[i];
  }
  return result;
}

class MLP {
private:
  vector<vector<double>> W1, W2; // 가중치 행렬
  vector<double> b1, b2;         // 편향 벡터

public:
  MLP(int input_size, int hidden_size, int output_size) {
    // 랜덤 가중치 초기화
    srand(time(0));
    W1 = vector<vector<double>>(hidden_size, vector<double>(input_size));
    b1 = vector<double>(hidden_size);
    W2 = vector<vector<double>>(output_size, vector<double>(hidden_size));
    b2 = vector<double>(output_size);

    // 가중치 및 편향 랜덤 초기화
    for (auto &row : W1)
      for (auto &w : row)
        w = random_weight();
    for (auto &w : b1)
      w = random_weight();
    for (auto &row : W2)
      for (auto &w : row)
        w = random_weight();
    for (auto &w : b2)
      w = random_weight();
  }

  // 순전파 (입력 -> 은닉층 -> 출력)
  vector<double> forward(const vector<double> &x) {
    vector<double> hidden = relu(add(matmul(W1, x), b1)); // 은닉층
    vector<double> output = add(matmul(W2, hidden), b2);  // 출력층
    return output;
  }
};

#endif