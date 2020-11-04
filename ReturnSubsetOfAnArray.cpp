#include<bits/stdc++.h>
using namespace std;

int subset(int *input, int n, int output[100][100]) {
	if(n == 0) {
		output[0][0] = 0;
		return 1;
	}
	int ans = subset(input+1, n-1, output);
	for(int i=0;i<ans;i++) {
		output[i+ans][0] = 1 + output[i][0];
		output[i+ans][1] = input[0];
	}
	int k = 0;
	for(int i=0;i<ans;i++) {
		for(int j=2;j<=output[i+ans][0];j++) {
			output[i+ans][j] = output[k][j-1];
		}
		k++;
	}
	return 2 * ans;
}

int main() {
	int n, input[20], output[100][100];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>input[i];
	}
	int ans = subset(input, n, output);
	for(int i=0;i<ans;i++) {
		for(int j=1;j<=output[i][0];j++) {
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
