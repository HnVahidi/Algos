bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}

//more implemention on http://codeforces.com/blog/entry/9901
