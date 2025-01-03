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
void answer_10(){
	unsigned long sum_prime = 2;
	for(int p=3;p<2000000;p+=2){
		if(is_prime(p)) sum_prime+=p;
	}
	cout<<sum_prime<<endl;
}
void answer_11(){
	string num_string = R"(08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48)";

	//make num_list to array 2 dim
	int num_arr[20][20];
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			int idx = i*20*3 + j*3;
			int num = (char(num_string[idx]) - '0')*10 +  (char(num_string[idx+1]) - '0');

			num_arr[i][j] = num;
			//cout<<num<<" ";
		}
		//cout<<endl;
	}

	int largest_mult = 0;
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			int horizontal_mult = 0;
			int vertical_mult = 0;
			int diag_right_mult = 0;
			int diag_left_mult = 0;

			//check horizontal
			if(j<=16){
				horizontal_mult = num_arr[i][j] * num_arr[i][j+1] * num_arr[i][j+2] * num_arr[i][j+3];

				if(horizontal_mult > largest_mult) largest_mult = horizontal_mult;
			}
			//check vertical
			if(i<=16){
				vertical_mult = num_arr[i][j] * num_arr[i+1][j] * num_arr[i+2][j] * num_arr[i+3][j];

				if(vertical_mult > largest_mult) largest_mult = vertical_mult;
			}
			//check right diagonal
			if(i<=16 && j<=16){
				diag_right_mult = num_arr[i][j] * num_arr[i+1][j+1] * num_arr[i+2][j+2] * num_arr[i+3][j+3];

				if(diag_right_mult > largest_mult) largest_mult = diag_right_mult;
			}
			//check left diagonal
			if(i<=16 && j>=3){
				diag_left_mult = num_arr[i][j] * num_arr[i+1][j-1] * num_arr[i+2][j-2] * num_arr[i+3][j-3];

				if(diag_left_mult > largest_mult) largest_mult = diag_left_mult;
			}
		}
	}
	cout<<largest_mult<<endl;
}
void answer_12(){
	int triangle_num = 1;
	int add_num = 2;
	while(true){
		if(count_devisors(triangle_num) > 500){
			cout<<triangle_num<<endl;
			break;
		}
		triangle_num += add_num;
		add_num++;
	}
	cout<<"count "<<count_devisors(triangle_num)<<endl;
}
void answer_13(){
	string big_num = R"(37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676
89261670696623633820136378418383684178734361726757
28112879812849979408065481931592621691275889832738
44274228917432520321923589422876796487670272189318
47451445736001306439091167216856844588711603153276
70386486105843025439939619828917593665686757934951
62176457141856560629502157223196586755079324193331
64906352462741904929101432445813822663347944758178
92575867718337217661963751590579239728245598838407
58203565325359399008402633568948830189458628227828
80181199384826282014278194139940567587151170094390
35398664372827112653829987240784473053190104293586
86515506006295864861532075273371959191420517255829
71693888707715466499115593487603532921714970056938
54370070576826684624621495650076471787294438377604
53282654108756828443191190634694037855217779295145
36123272525000296071075082563815656710885258350721
45876576172410976447339110607218265236877223636045
17423706905851860660448207621209813287860733969412
81142660418086830619328460811191061556940512689692
51934325451728388641918047049293215058642563049483
62467221648435076201727918039944693004732956340691
15732444386908125794514089057706229429197107928209
55037687525678773091862540744969844508330393682126
18336384825330154686196124348767681297534375946515
80386287592878490201521685554828717201219257766954
78182833757993103614740356856449095527097864797581
16726320100436897842553539920931837441497806860984
48403098129077791799088218795327364475675590848030
87086987551392711854517078544161852424320693150332
59959406895756536782107074926966537676326235447210
69793950679652694742597709739166693763042633987085
41052684708299085211399427365734116182760315001271
65378607361501080857009149939512557028198746004375
35829035317434717326932123578154982629742552737307
94953759765105305946966067683156574377167401875275
88902802571733229619176668713819931811048770190271
25267680276078003013678680992525463401061632866526
36270218540497705585629946580636237993140746255962
24074486908231174977792365466257246923322810917141
91430288197103288597806669760892938638285025333403
34413065578016127815921815005561868836468420090470
23053081172816430487623791969842487255036638784583
11487696932154902810424020138335124462181441773470
63783299490636259666498587618221225225512486764533
67720186971698544312419572409913959008952310058822
95548255300263520781532296796249481641953868218774
76085327132285723110424803456124867697064507995236
37774242535411291684276865538926205024910326572967
23701913275725675285653248258265463092207058596522
29798860272258331913126375147341994889534765745501
18495701454879288984856827726077713721403798879715
38298203783031473527721580348144513491373226651381
34829543829199918180278916522431027392251122869539
40957953066405232632538044100059654939159879593635
29746152185502371307642255121183693803580388584903
41698116222072977186158236678424689157993532961922
62467957194401269043877107275048102390895523597457
23189706772547915061505504953922979530901129967519
86188088225875314529584099251203829009407770775672
11306739708304724483816533873502340845647058077308
82959174767140363198008187129011875491310547126581
97623331044818386269515456334926366572897563400500
42846280183517070527831839425882145521227251250327
55121603546981200581762165212827652751691296897789
32238195734329339946437501907836945765883352399886
75506164965184775180738168837861091527357929701337
62177842752192623401942399639168044983993173312731
32924185707147349566916674687634660915035914677504
99518671430235219628894890102423325116913619626622
73267460800591547471830798392868535206946944540724
76841822524674417161514036427982273348055556214818
97142617910342598647204516893989422179826088076852
87783646182799346313767754307809363333018982642090
10848802521674670883215120185883543223812876952786
71329612474782464538636993009049310363619763878039
62184073572399794223406235393808339651327408011116
66627891981488087797941876876144230030984490851411
60661826293682836764744779239180335110989069790714
85786944089552990653640447425576083659976645795096
66024396409905389607120198219976047599490197230297
64913982680032973156037120041377903785566085089252
16730939319872750275468906903707539413042652315011
94809377245048795150954100921645863754710598436791
78639167021187492431995700641917969777599028300699
15368713711936614952811305876380278410754449733078
40789923115535562561142322423255033685442488917353
44889911501440648020369068063960672322193204149535
41503128880339536053299340368006977710650566631954
81234880673210146739058568557934581403627822703280
82616570773948327592232845941706525094512325230608
22918802058777319719839450180888072429661980811197
77158542502016545090413245809786882778948721859617
72107838435069186155435662884062257473692284509516
20849603980134001723930671666823555245252804609722
53503534226472524250874054075591789781264330331690)";

	int save_ans[10];
	int add_to_next_digit = 0;
	for(int digit_idx = 49;digit_idx>=0;digit_idx--){
		int sum_digit = add_to_next_digit;
		for(int i=0;i<100;i++){
			int idx = i*50 + digit_idx + i;
			int num = char(big_num[idx]) - '0';
			sum_digit += num;
		}
		add_to_next_digit = sum_digit/10;
		if(digit_idx <10 && digit_idx!=0) save_ans[digit_idx] = sum_digit%10;
		if(digit_idx == 0) save_ans[0] = sum_digit;
	}

	//show the first 10 digits;
	int cek = save_ans[0];
	int cnt_digits = 0;
	while(cek != 0){
		cek /= 10;
		cnt_digits++;
	}
	for(int i=0;i<10 - cnt_digits + 1;i++){
		cout<<save_ans[i];
	}
	cout<<endl;

}
void answer_14(){
	int cnt_collatz_arr[1000000];
	for(int i = 0; i<1000000;i++){
		cnt_collatz_arr[i] = 0;
	}
	cnt_collatz_arr[1] = 1;

	int longest_chain = 0;
	int ans = 0;
	for(int i=2;i<1000000;i++){
		unsigned long check = i;
		int cnt_collatz = 0;
		while(true){
			check = check%2==0 ? check/2 : check*3 + 1;
			cnt_collatz++;
			
			if(check < 1000000){
				if(cnt_collatz_arr[check] != 0) break;
			}
			if(check==1) break;
		}
		int val = cnt_collatz + cnt_collatz_arr[check];
		cnt_collatz_arr[i] =val;
		
		if(val > longest_chain){
			longest_chain = val;
			ans = i;
		}
	}
	cout<<ans<<endl;
}
void answer_15(){
	//move right -> 0
	//move down -> 1
	//so the problem became how many arrangement for 40 digits 1 and 0
	//the answer is 40C20 = 40!/((40-20)!20!)
	unsigned long ans = 1;
	for(int i=20;i>=1;i--){
		ans *= (i+20);
		ans /= (20 - i + 1);
	}
	cout<<ans<<endl;
}
void answer_16(){
	string num = "2";
	for(int i=2;i<1001;i++){
		int add_val = 0;
		for(int j=num.size()-1;j>=0;j--){
			int val = (char(num[j]) - '0');
			val *= 2;
			val += add_val;
			add_val = val/10;
			val %= 10;
			num[j] = char(val + int('0'));
		}
		if(add_val > 0){
			num.insert(num.begin(), char(add_val + int('0')));
		}
	}
	cout<<"2^1000 = "<<num<<endl;
	//count sum digits
	int sum_digits = 0;
	for(int i=0;i<num.size();i++){
		sum_digits += char(num[i]) - '0';
	}
	cout<<sum_digits<<endl;
}
void answer_17(){
	vector<string> ones = {"zero","one", "two","three", "four", "five", "six", "seven", "eight", "nine"};
	vector<string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	vector<string> tens = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string hundreds_s = "hundred";
	string thousand_s = "thousand";
	string and_s = "and";
	int cnt_length = 0;
	
	for(int i=1;i<1000;i++){
		string res;
		int check = i;
		int hundreds_n = check/100;
		check %= 100;
		int tens_n = check/10;
		check %= 10;
		int ones_n = check;

		//check
		if(hundreds_n > 0) res += ones[hundreds_n] + " " + hundreds_s + " ";
		if(hundreds_n > 0 && (tens_n > 0 || ones_n > 0)) res += and_s + " ";
		if(tens_n == 1) res += teens[ones_n];
		if(tens_n > 1) res += tens[tens_n] + " ";
		if(tens_n != 1 && ones_n > 0) res += ones[ones_n];
		cout<<res;

		res="";
		if(hundreds_n > 0) res += ones[hundreds_n] + hundreds_s;
		if(hundreds_n > 0 && (tens_n > 0 || ones_n > 0)) res += and_s;
		if(tens_n == 1) res += teens[ones_n];
		if(tens_n > 1) res += tens[tens_n];
		if(tens_n != 1 && ones_n > 0) res += ones[ones_n];
		cout<<"  = "<<res.size()<<endl;
		cnt_length += res.size();
	}
	string one_thousand_s = ones[1] + thousand_s;
	cnt_length += (one_thousand_s).size();
	cout<<cnt_length<<endl;
}
void answer_18(){
	string triangle_string = R"(75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23)";

	int triangle_val[15][15];
	int idx = 0;
	for(int i=0;i<15;i++){
		int val = 0;
		for(int j=0;j<15;j++){
			if(j>i) val = 0;
			else{
				val = (char(triangle_string[idx])-'0')*10 + (char(triangle_string[idx+1])-'0');
				idx += 3;
			}
			triangle_val[i][j] = val;
		}
	}

	for(int i=0;i<15;i++){
		for(int j=0;j<i+1;j++){
			cout<<triangle_val[i][j]<<" ";
		}
		cout<<endl;
	}

	//idea is to check from up to down, and add current triangle value to adjecent below triangle value. 
	//If the triangle below is affected by 2 value, then choose the bigger one
	for(int i=1;i<15;i++){
		for(int j=0;j<i+1;j++){
			//boundary triangle
			if(j==0 || j==i){
				if(j==0) triangle_val[i][j] += triangle_val[i-1][0];
				if(j==i) triangle_val[i][j] += triangle_val[i-1][j-1];
			}
			//middle triangle
			else{
				triangle_val[i][j] += (triangle_val[i-1][j-1] > triangle_val[i-1][j]) ? triangle_val[i-1][j-1] : triangle_val[i-1][j];
			}
		}
	}

	//check the largest sum
	int largest_sum = 0;
	for(int i=0;i<15;i++){
		if(triangle_val[14][i] > largest_sum) largest_sum = triangle_val[14][i];
	}
	cout<<largest_sum<<endl;
}
void answer_19(){
	//0 for sunday, then 1 jan 1900 -> 1
	//1900 not a leap year, so there was 355 days
	int start_day_of_this_month = (1 + 365%7)%7; //first day of 1st jan 1901
	int start_day_of_next_month = 0;
	int cnt_sunday = 0;

	int days_month[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

	for(int year=1901;year<2001;year++){
		for(int month = 1;month <=12;month++){
			if(start_day_of_this_month == 0) cnt_sunday++;

			start_day_of_next_month = start_day_of_this_month + days_month[month];
			if(month == 2 && is_leap_year(year)) start_day_of_next_month++;
			start_day_of_next_month %= 7;

			start_day_of_this_month = start_day_of_next_month;
		}
	}
	cout<<cnt_sunday<<endl;
}
void answer_20(){
	string num = "1";
	int n_factorial = 100;
	for(int i=2;i<n_factorial+1;i++){
		string num_i = num;
		//calc num * i
		for(int j=1;j<i;j++){
			num_i = add_num_string(num_i, num);
		}
		num = num_i;
	}
	cout<<"100! = "<<num<<endl;

	//count sum digits
	int sum_digits = 0;
	for(int i=0;i<num.size();i++){
		sum_digits += char(num[i]) - '0'; 
	}
	cout<<"sum digits = "<<sum_digits<<endl;
}
void answer_21(){
	int sum_amicable = 0;
	for(int i=2;i<10000;i++){
		int sum_pd = sum_of_proper_devisors(i);
		if(sum_pd == i) continue;
		if(sum_of_proper_devisors(sum_pd) == i){
			sum_amicable += i;
		} 
	}
	cout<<sum_amicable<<endl;
}
void answer_22(){
	//read txt file
	string file_name = "../0022_names.txt";
	ifstream input_file(file_name);
	if(!input_file.is_open()){
		cerr<<"failed to open the file"<<endl;
	}
	string line;
	getline(input_file, line);

	vector<string> names;
	int start_name_idx = 1;
	for(int i=0;i<line.size();i++){
		if(line[i] == ','){
			string name = line.substr(start_name_idx, i-1-start_name_idx);
			names.push_back(name);
			start_name_idx = i+2;
		}
	}
	//add last name
	for(int i=line.size()-2;i>=0;i--){
		if(line[i] == ','){
			string name = line.substr(i+2, line.size()-1-(i+2));
			cout<<name<<endl;
			names.push_back(name);
			break;
		}
	}

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
int count_devisors(int n){
	int cnt = 0;
	for(int i=1;i<sqrt(n);i++){
		if(n%i==0) cnt+=2;
	}
	//check if the number is square number
	if(sqrt(n) * sqrt(n) == n) cnt++;
	return cnt;
}
bool is_leap_year(int year){
	if(year%4==0){
		if(year%400 == 0) return true;
		if(year%100 == 0) return false;
		return true;
	}
	return false;
}
string add_num_string(string a, string b){
	if(a.size() < b.size()){
		string c=b;
		b=a;
		a=c;
	}

	string res = "";
	int add_next = 0;
	for(int i=0;i<a.size();i++){
		int val_a = char(a[a.size()-1-i]) - '0';
		int val_b = i < b.size() ? char(b[b.size()-1-i]) - '0' : 0;

		int sum = val_a + val_b + add_next;
		add_next = sum/10;
		sum %= 10;
		res.insert(res.begin(), char(sum + int('0')));
	}
	if(add_next > 0) res.insert(res.begin(), char(add_next + int('0')));
	
	return res;
}
int sum_of_proper_devisors(int n){
	int sum = 0;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			int add = n/i;
			if(add != n && add != i) sum += add;
			sum += i;
		}
	}
	return sum;
}
