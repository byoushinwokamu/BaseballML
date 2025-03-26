#include "mlp.hh"

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

vector<double> vecadd(const vector<double> &a, const vector<double> &b) {
  vector<double> result(a.size());
  for (size_t i = 0; i < a.size(); i++) {
    result[i] = a[i] + b[i];
  }
  return result;
}

MLP::MLP(int input_size, int hidden_size, int output_size) {
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
vector<double> MLP::forward(const vector<double> &x) {
  vector<double> hidden = relu(vecadd(matmul(W1, x), b1)); // 은닉층
  vector<double> output = vecadd(matmul(W2, hidden), b2);  // 출력층
  return output;
}

vector<int> MLP::convert_output(const vector<double> &raw_output) {
  vector<double> probabilities = softmax(raw_output); // 확률 변환
  return softmax_to_numbers(probabilities);           // 최적 숫자 선택
}

// Softmax 함수 (확률 변환)
vector<double> MLP::softmax(const vector<double> &x) {
  vector<double> exp_x(x.size());
  double sum_exp = 0.0;

  // 지수 연산
  for (size_t i = 0; i < x.size(); i++) {
    exp_x[i] = exp(x[i]);
    sum_exp += exp_x[i];
  }

  // 확률값으로 변환
  for (size_t i = 0; i < x.size(); i++) {
    exp_x[i] /= sum_exp;
  }
  return exp_x;
}

// 확률을 기반으로 1~9에서 선택
vector<int> MLP::softmax_to_numbers(const vector<double> &softmax_output) {
  vector<int> result(softmax_output.size());
  vector<int> possible_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (size_t i = 0; i < softmax_output.size(); i++) {
    double max_prob = -1.0;
    int best_number = 1;

    for (size_t j = 0; j < possible_numbers.size(); j++) {
      if (softmax_output[i] > max_prob) {
        max_prob = softmax_output[i];
        best_number = possible_numbers[j];
      }
    }

    result[i] = best_number;
  }
  return result;
}