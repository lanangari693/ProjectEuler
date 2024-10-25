#include "answer.hpp"

void answer_1() {
	int sum = 0;
	for (int i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) sum += i;
	}
	cout << sum;
}
void answer_2() {
	int fibo1 = 1, fibo2 = 2;
	int sum = 0;
	while (fibo1 < 4000000) {
		if (fibo1 % 2 == 0) sum += fibo1;
		if (fibo2 % 2 == 0) sum += fibo2;
		fibo1 += fibo2;
		fibo2 += fibo1;
	}
	cout << sum;
}
void answer_3() {
	long long n = 600851475143;
	long long prime_div = 3;
	while (!is_prime(n)) {
		while (n % prime_div == 0) {
			n /= prime_div;
		}
		prime_div = next_prime(prime_div);
	}
	cout << n;
}
void answer_4() {
	//smallest product of 3 digit numbers = 100*100 = 10000
	//largest product of 3 digit numbers = 999*999 = 998001
	int max_val = 0;
	for (int a = 999; a >= 100; a--) {
		for (int b = 999; b >= 100; b--) {
			int val = a * b;
			if (max_val > val) break;
			if (is_palindrome(val)) max_val = val;
		}
	}
	cout << max_val;
}
void answer_5() {
	vector<Exponent> val;
	Exponent exp;
	for (int i = 2; i <= 20; i++) {
		if (is_prime(i)) {
			exp.base = i;
			exp.power = 1;
			val.push_back(exp);
		}
		else {
			vector<Exponent> val_res = prime_decomposition(i);
			for (int j = 0; j < val_res.size(); j++) {
				for (int k = 0; k < val.size(); k++) {
					if (val_res[j].base == val[k].base && val_res[j].power > val[k].power) val[k] = val_res[j];
				}
			}
		}
	}
	long long product = 1;
	for (int i = 0; i < val.size(); i++) {
		product *= pow(val[i].base, val[i].power);
	}
	cout << product;
}
void answer_6() {
	//arithmatic sum 1+2+3+...+100 = (1+100)*100/2
	int art_sum = (1 + 100) * 100 / 2;
	int val = art_sum * art_sum;
	for (int i = 1; i <= 100; i++) {
		val -= i * i;
	}
	cout << val;
}
void answer_7() {
	int prime_idx = 1;
	long long prime_val = 2;
	while (prime_idx < 10001) {
		prime_val = next_prime(prime_val);
		prime_idx++;
	}
	cout << prime_val;
}
void answer_8() {
	string big_num = R"(73167176531330624919225119674426574742355349194934
		96983520312774506326239578318016984801869478851843
		85861560789112949495459501737958331952853208805511
		12540698747158523863050715693290963295227443043557
		66896648950445244523161731856403098711121722383113
		62229893423380308135336276614282806444486645238749
		30358907296290491560440772390713810515859307960866
		70172427121883998797908792274921901699720888093776
		65727333001053367881220235421809751254540594752243
		52584907711670556013604839586446706324415722155397
		53697817977846174064955149290862569321978468622482
		83972241375657056057490261407972968652414535100474
		82166370484403199890008895243450658541227588666881
		16427171479924442928230863465674813919123162824586
		17866458359124566529476545682848912883142607690042
		24219022671055626321111109370544217506941658960408
		07198403850962455444362981230987879927244284909188
		84580156166097919133875499200524063689912560717606
		05886116467109405077541002256983155200055935729725
		71636269561882670428252483600823257530420752963450)";

	long long res_product = 1;
	long long max_val = 0;
	
	int val[1000];
	int i = 0;
	int idx = 0;
	while (i < 1000) {
		int b = char(big_num[idx]) - '0';
		idx++;
		//cek valid
		if (b < 0 || b>9) {
			continue;
		}
		val[i] = b;
		i++;
	}
	for (int i = 12; i < 1000; i++) {
		for (int j = i - 12; j <= i; j++) {
			res_product *= val[j];
		}
		if (res_product > max_val) max_val = res_product;
		res_product = 1;
	}
	cout << max_val;
	cout << endl;
}
void answer_9() {
	//rearange equation to a^2 = c^2 - b^2 => a^2 = (c-b)*(c+b)

	long long res = 1;
	for (int c = 5; c < 1000; c++) {
		for (int b = 1; b < c; b++) {
			int a = sqrt((c - b) * (c + b));
			if (a * a == (c - b) * (c + b)) {
				int sum = a + b + c;
				if (1000 % sum == 0) {
					res = a * b * c * pow(1000, 3) / pow(sum, 3);
				}
			}
		}
	}
	cout << res;
}


bool is_prime(long long n) {
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	int limit = sqrt(n) + 1;
	for (int i = 3; i <= limit; i+=2) {
		if (n % i == 0) return false;
	}
	return true;
}
long long next_prime(int n) {
	if (n == 2) return 3;
	//else
	n += 2;
	while (!is_prime(n)) {
		n += 2;
	}
	return n;
}
bool is_palindrome(long long n) {
	vector<int> digit;
	while (n != 0) {
		digit.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < digit.size() / 2; i++) {
		if (digit[i] != digit[digit.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
vector<Exponent> prime_decomposition(long long n) {
	vector<Exponent> result;
	Exponent exp;
	long long prime_div = 2;
	int cnt_pow = 0;
	while (n != 1) {
		while (n % prime_div == 0) {
			n /= prime_div;
			cnt_pow++;
		}
		exp.base = prime_div;
		exp.power = cnt_pow;
		result.push_back(exp);
		prime_div = next_prime(prime_div);
		cnt_pow = 0;
	}
	return result;
}