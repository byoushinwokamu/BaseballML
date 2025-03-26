#include "bot.hh"

NBBbot::NBBbot() {
  number_freq[1] = 1;
  number_freq[2] = 1;
  number_freq[3] = 1;
  number_freq[4] = 1;
  number_freq[5] = 1;
  number_freq[6] = 1;
  number_freq[7] = 1;
  number_freq[8] = 1;
  number_freq[9] = 1;
  srand(time(0));
}

int NBBbot::weighted_random_pick(const vector<int> &exclude) {
  vector<pair<int, int>> candidates;

  // 이미 선택된 숫자(exclude)에 없는 숫자만 후보로 추가
  for (auto &[num, freq] : number_freq) {
    if (find(exclude.begin(), exclude.end(), num) == exclude.end()) {
      candidates.push_back({num, freq});
    }
  }

  // 가중치를 고려한 랜덤 선택
  int total_weight = 0;
  for (auto &[_, freq] : candidates) {
    total_weight += freq;
  }

  int rnd = (int)rand() % total_weight;
  for (auto &[num, freq] : candidates) {
    if (rnd < freq)
      return num;
    rnd -= freq;
  }

  return candidates.back().first; // 예외적으로 마지막 요소 반환
}

int NBBbot::makeSwing(void) {
  vector<int> guess;

  while (guess.size() < 3)
    guess.push_back(weighted_random_pick(guess));

  last_guess = guess;
  return guess[0] * 100 + guess[1] * 10 + guess[2];
}

void NBBbot::applyResult(BSdata dat) {
  if (dat.gameend) {
    number_freq[1] = 1;
    number_freq[2] = 1;
    number_freq[3] = 1;
    number_freq[4] = 1;
    number_freq[5] = 1;
    number_freq[6] = 1;
    number_freq[7] = 1;
    number_freq[8] = 1;
    number_freq[9] = 1;
    return;
  }
  for (int n : last_guess)
    number_freq[n] += dat.strike * 2 + dat.ball;
}
