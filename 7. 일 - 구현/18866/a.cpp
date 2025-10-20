#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000005
#define L 1000005

using namespace std;

struct day {
	int happy;
	int tired;
};

day days[L]; //happy, tired
day youth[L]; //minHappy, maxTired
day old[L]; //maxHappy, minTired

int main() {
	int maxHappy = -1;
	int minHappy = INF;
	int maxTired = -1;
	int minTired = INF;
	
	int n; 
	cin>>n;
	for (int i = 1; i <= n; i++) {
		int n1,n2;
		cin>>n1>>n2;
		days[i].happy=n1;
		days[i].tired=n2;
	}

	//youth
	for (int i = 1; i <= n; i++) {
		if (days[i].happy != 0 && days[i].happy < minHappy) {
			minHappy = days[i].happy;
		}
		if (days[i].tired != 0 && days[i].tired > maxTired) {
			maxTired = days[i].tired;
		}
		youth[i].happy = minHappy;
		youth[i].tired = maxTired;
	}
	//old
	for (int i = n; i >= 0; i--) {
		if (days[i].happy != 0 && days[i].happy > maxHappy) {
			maxHappy = days[i].happy;
		}
		if (days[i].tired != 0 && days[i].tired < minTired) {
			minTired = days[i].tired;
		}
		old[i].happy = maxHappy;
		old[i].tired = minTired;
	}

	int ret = -1;
	for (int k = n - 1; k >= 0; k--) {
		int youth_happy = youth[k].happy;
		int youth_sleepy = youth[k].tired;
		int old_happy = old[k+1].happy;
		int old_sleepy = old[k+1].tired;
		if (youth_happy > old_happy && youth_sleepy < old_sleepy) {
			ret = max(ret, k);
		}
	}
	cout<<ret<<"\n";

	return 0;
}