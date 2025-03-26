#ifndef __MLP_HH__
#define __MLP_HH__

#include <cmath>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

double random_weight();

vector<double> relu(const vector<double> &x);

vector<double> matmul(const vector<vector<double>> &W, const vector<double> &x);

vector<double> vecadd(const vector<double> &a, const vector<double> &b);

class MLP {
private:
  vector<vector<double>> W1, W2; // 가중치 행렬
  vector<double> b1, b2;         // 편향 벡터

public:
  MLP(int input_size, int hidden_size, int output_size);
  vector<double> forward(const vector<double> &x);
  vector<int> convert_output(const vector<double> &raw_output);
  vector<double> softmax(const vector<double> &x);
  vector<int> softmax_to_numbers(const vector<double> &softmax_output);
};

#endif