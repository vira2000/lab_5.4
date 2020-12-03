// Лабораторна робота No 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 0;
	for (int k=1; k <= N; k++)
		s += (1+sqrt(1+k*k))/pow(k,2);
	return s;
}
double S1(const int K, const int N)
{
	if (K > N)
		return 0;
	else
		return (1 + sqrt(1 + K * K)) / pow(K, 2) + S1(N,K + 1);
}
double S2(const int K, const int N)
{
	if (K < 1)
		return 0;
	else
		return (1 + sqrt(1 + K * K)) / pow(K, 2) + S2(N, K - 1);
}
double S3(const int K, const int N, double t)
{
	t = t + (1 + sqrt(1 + K * K)) / pow(K, 2);
	if (K >= N)
		return t;
	else
		return S3(N, K + 1, t);
}
double S4(const int K, const int N, double t)
{
	t = t + (1 + sqrt(1 + K * K)) / pow(K, 2);
	if (K <= 1)
		return t;
	else
		return S4(N, K - 1, t);
}
int main()
{
	int K, N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(K, N) << endl;
	cout << "(rec up ++) S1 = " << S1(K, N) << endl;
	cout << "(rec up --) S2 = " << S2(K, N) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, K) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, N) << endl;
	return 0;
}