#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 999999;

int arr[100001][4];

int mymax(int x, int y, int z) {
	int arr[3] = { x,y,z };
	sort(arr, arr + 3);
	return arr[2];
}

int mymin(int x, int y, int z) {
	int arr[3] = { x,y,z };
	sort(arr, arr + 3);
	return arr[0];
}

int dp_max[2][5]; // dp_max[0][1], dp_max[1][1] ~ dp_max[0][3], dp_max[1][3]. dp_max[x][0] = 0, dp_max[x][4]=0
int dp_min[2][5];

void printDpMax() {
	cout << "dp max\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <=3; j++) {
			cout << dp_max[i][j] << ' ';
		}
		cout << '\n';
	}
}


void printDpMin() {
	cout << "dp min\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <=3; j++) {
			cout << dp_min[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main() {
	int n;
	cin >> n; // < 10^5

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	// max: dp인데 밑에서부터 올라와야 함.
	dp_max[n % 2][1] = arr[n][1];
	dp_max[n % 2][2] = arr[n][2];
	dp_max[n % 2][3] = arr[n][3];

	// min: 
	for (int i = 1; i <= n; i++) {
		dp_min[i % 2][0] = INF;
		dp_min[i % 2][4] = INF;
	}
	dp_min[n % 2][1] = arr[n][1];
	dp_min[n % 2][2] = arr[n][2];
	dp_min[n % 2][3] = arr[n][3];

	for (int i = n - 1; i >= 1; i--) {
		int curridx = i % 2;
		int previdx = (curridx == 0) ? 1 : 0;
		for (int j = 1; j <= 3; j++) {
			//cout << "MYMAX: " << mymax(dp_max[previdx][j - 1], dp_max[previdx][j], dp_max[previdx][j + 1]) << " + arr[i][j]: " << arr[i][j] << '\n';
			dp_max[curridx][j] = mymax(dp_max[previdx][j - 1], dp_max[previdx][j], dp_max[previdx][j + 1]) + arr[i][j];
			//cout << "MYMIN: " << mymin(dp_min[previdx][j - 1], dp_min[previdx][j], dp_min[previdx][j + 1]) << " + arr[i][j]: " << arr[i][j] << '\n';
			dp_min[curridx][j] = mymin(dp_min[previdx][j - 1], dp_min[previdx][j], dp_min[previdx][j + 1]) + arr[i][j];
		}
		//printDpMax();
		//printDpMin();
	}
	
	int maxscore = mymax(dp_max[1][1], dp_max[1][2], dp_max[1][3]);
	int minscore = mymin(dp_min[1][1], dp_min[1][2], dp_min[1][3]);
	cout << maxscore << ' ' << minscore << '\n';
	return 0;
}
