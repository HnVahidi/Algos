#include<bits/stdc++.h>

using namespace std;
const int maxN=1e6+100;
int n,k;
int a[maxN],swm[maxN];

void input()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>a[i];
}

//SWM =Sliding Window Minimum
void sliding_window(int k) {
  // pair<int, int> represents the pair (ARR[i], i)
  std::deque<pair<int, int> > window;
  for (int i = 0; i < n; i++) {
     while (!window.empty() && window.back().first >= a[i])
       window.pop_back();
     window.push_back(std::make_pair(a[i], i));

     while(window.front().second <= i - k)
       window.pop_front();
     swm[i]=window.front().first;
     cout << swm[i] << ' ';
  }
}
int main()
{
  input();
  sliding_window(k);
}
