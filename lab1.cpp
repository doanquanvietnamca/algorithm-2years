#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <ctime>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <pair <int, string> > v; // main vector to data save
long checkNumber(const string &s); // check valid numbernumber
int checkString(const string &s); // check valid stringstring
bool com_pair(pair <int, string> x, pair <int, string> y); // check to swap elementelement

void heapify(int i,int N) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && com_pair(v[left],v[largest]))
        largest = left;
    if (right < N && com_pair(v[right], v[largest]))
        largest = right;
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(largest, N);
    }
}
void sortArray( int len) {
    for (int i = len / 2; i >= 0; --i) {
        heapify( i, len);
    }
    for (int i = len - 1; i >= 0; --i) {
        swap(v[0], v[i]);
        heapify( 0, i);
    }
}

int main(int argc, char *argv[]) {
	if (argc != 3)return 1;
	clock_t tStart = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	ifstream ifs(argv[1], ifstream::in);
	if (!ifs.is_open())
		return 2;
	if (!freopen(argv[2], "w", stdout)) 
		return 2;
	string input_str;
	getline(ifs, input_str);
	
	long number(0), N = checkNumber(input_str), count{ 0 };
	if (N == -1)
		return 3;

	while (!(ifs.eof())) {
		getline(ifs, input_str);
		int x = checkString(input_str);
		if (x == -1)return 3;
		++count;
	}
	sortArray(N);
	cout << N << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i].second << "\n";
	return 0;
}
long checkNumber(const string &s) {
	if (s.size() == 0) return -1;
	long N = 0, step = 1;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (isdigit(s[i])) {
			N += (s[i] - 48) * step;
			step *= 10;
		}
		else {
			return -1;
		}
	}

	return N;
}

int checkString(const string &s) {
	long current = -1;
	string new_s{};
	for (int i = 0; i < s.size(); ++i) {
		if (isdigit(s[i])) {
			new_s += s[i];
		}
		else {
			current = checkNumber(new_s);
			if (current >= 0 && s[i] == ' ') {
				v.push_back({ i, s });
				return 0;
			}
			else return -1;
		}
	}
}
bool com_pair(pair <int, string> x, pair <int, string> y) {
	if (x.first > y.first) return true;
	if (x.first < y.first) return false;
	int min;
	if (x.second.size() >= y.second.size())
		min = y.second.size();
	else
		min = x.second.size();
	for (int i = 0; i < min; ++i) {
		if (x.second[i] > y.second[i]) return true;
		if (x.second[i] < y.second[i]) return false;
	}
	if (x.second.size() > y.second.size()) return true;
	else return false;
}