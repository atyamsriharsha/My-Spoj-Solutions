#include <iostream>
#include <stdio.h>
using namespace std;
 
struct b {
	int color; //color value
	int smoke; // to make them
};
 
int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) != -1) {
		struct b bottles[100][100] = { { 0, 0 } };
		for (int i = 0; i < n; i++) {
			cin >> bottles[i][i].color;
			bottles[i][i].smoke = 0;
		}
 
		for (int len = 2; len <= n; len++) 
		{
			for (int i = 0; i < n - len + 1; i++) 
			{
				int min = 1 << 30;
				int sum = 0;
				for (int j = i; j <= i + len - 2; j++)
				 {
					if(min> (bottles[i][j].smoke
									+ bottles[j + 1][i + len - 1].smoke
									+ bottles[i][j].color
											* bottles[j + 1][i + len - 1].color))
					{
						min = (bottles[i][j].smoke
								+ bottles[j + 1][i + len - 1].smoke
								+ bottles[i][j].color
										* bottles[j + 1][i + len - 1].color);
					}
				}
				bottles[i][i + len - 1].smoke = min;
				bottles[i][i + len - 1].color = bottles[i][i].color
						+ bottles[i + 1][i + len - 1].color;
				bottles[i][i + len - 1].color %= 100;
			}
		}
 
		cout << bottles[0][n - 1].smoke << endl;
		}
	return 0;
}