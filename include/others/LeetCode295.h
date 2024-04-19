#ifndef _LEETCODE_295_H_
#define _LEETCODE_295_H_

#include <queue>
#include <iostream>

using namespace std;

class MedianFinder {
 private:
  priority_queue<int> pri_que;
  int num_elements;

 public:
  MedianFinder() : num_elements(0) {}

  void addNum(int num) {
    num_elements++;
    pri_que.push(num);
  }

  double findMedian() {
    if (num_elements == 1) {
      return (double)pri_que.top();
    }

    vector<int> rights;

    double ans = 0;

    int left = 0, right = 0;
    for (int i = 0; i < num_elements / 2; ++i) {
      rights.push_back(pri_que.top());
      pri_que.pop();
    }
    right = rights.back();

    if (!(num_elements % 2)) {
      left = pri_que.top();
      ans = (left + right) / 2.0;
    } else {
      ans = pri_que.top();
    }

    for (int x : rights) {
      pri_que.push(x);
    }

    return ans;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 // ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"]
 // [[],[-1],[],[-2],[],[-3],[],[-4],[],[-5],[]]
void test295() {
    MedianFinder test;
  test.addNum(-1);
cout << test.findMedian() << endl;
  test.addNum(-2);
cout << test.findMedian() << endl;
  test.addNum(-3);
cout << test.findMedian() << endl;
  test.addNum(-4);
cout << test.findMedian() << endl;
  test.addNum(-5);
cout << test.findMedian() << endl;

 }


 #endif // _LEETCODE_295_H_