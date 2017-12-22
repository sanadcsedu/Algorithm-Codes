/*
Generates suffix array in O(n (lg n)^2). Finds LCP in O(lg n)
A[] is the target string with N length. base is the lowest character in A[].
S[i] holds the index of ith suffix when sorted lexicographically.
Change base as necessary and MAXLOG = log2(MAXLEN).
*/

int N, stp, P[MAXLOG][MAXLEN], S[MAXLEN];
char A[MAXLEN], base = 'a';
struct entry { int nr[2], p; } L[MAXLEN];

inline bool cmp(const entry &a, const entry &b) {
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

void generateSuffix() {
	register int i, cnt;
	for(i=0; i<N; i++) P[0][i] = A[i]-base;
	for(stp = cnt = 1; cnt>>1 < N; stp++, cnt<<=1) {
		for(i=0; i<N; i++) {
			L[i].nr[0] = P[stp-1][i];
			L[i].nr[1] = i+cnt<N ? P[stp-1][i+cnt] : -1;
			L[i].p = i;
		}
		sort(L, L+N, cmp);
		for(i=0; i<N; i++) {
			if(i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]) P[stp][L[i].p] = P[stp][L[i - 1].p];
			else P[stp][L[i].p] = i;
		}
	}
	for(i=0; i<N; i++) S[P[stp-1][i]] = i;
}

int lcp(int x, int y) {
	int k, ret = 0;
	if(x == y) return N - x;
	for(k = stp - 1; k >= 0 && x < N && y < N; k --)
		if(P[k][x] == P[k][y])
			x += 1 << k, y += 1 << k, ret += 1 << k;
	return ret;
}