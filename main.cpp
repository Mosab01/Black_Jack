#include<iostream>

using namespace std;

int get_card();
int cpu_first_card();
int cpu_cards();
int hit_card();
bool check_ace();
bool check_cpu_ace();
void winner_loser();

int cards[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
int p_rv = 0, c_rv = 0, p_sum = 0, c_sum = 0;
bool hit = 0;

//this is main
int main()
{
	//this function so i get randomized numbers every time i run the program
	srand(time(0));

	cpu_first_card();
	get_card();
	hit_card();

	do
	{
		cpu_cards();
	} while (p_sum > c_sum && p_sum < 22);

	winner_loser();

	cout << "Cpu Sum = " << c_sum;


	return 0;
}

//to pick a random card
int get_card()
{
	int rv = 0;
	p_rv = rv = cards[rand() % 13];


	if (p_rv > 10)
		p_rv = 10;


	cout << endl << "the card you got " << rv << "\tits value " << p_rv << endl;
	check_ace();
	return p_rv;
}

//to check if number 1 accured 
bool check_ace()
{
	bool ace = 0;
	if (p_rv == 1)
	{
		cout << endl << "type [1] if you want the ace to value 11 [0] to value 1" << endl;
		cin >> ace;
		if (ace)
			p_sum += 10;
	}
	return p_rv;
}

bool check_cpu_ace()
{
	bool ace = 0;
	if (c_rv == 1)
	{
		if ((c_sum + 11) < 21)
			p_sum += 10;
	}
	return c_rv;
}

// to check if player wanna hit
int hit_card()
{
	p_sum += p_rv;

	cout << "If you want to hit type [1] , to fold type [0]" << endl;
	cin >> hit;

	do
	{
		get_card();
		p_sum += p_rv;
		cout << "Your cards sum = " << p_sum << endl;
		cin >> hit;
	} while (hit && p_sum < 22);
	return p_sum;
}


//shows the cpu first card
int cpu_first_card()
{
	int rv1 = 0;

	c_rv = rv1 = cards[rand() % 13];

	if (c_rv > 10)
		c_rv = 10;

	c_sum += c_rv;

	cout << endl << "the first computer card is " << rv1 << endl;
	check_cpu_ace();

	return c_rv;
}
int cpu_cards()
{
	int rv1 = 0;

	c_rv = rv1 = cards[rand() % 13];

	if (c_rv > 10)
		c_rv = 10;

	c_sum += c_rv;

	check_cpu_ace();

	return rv1;
}

//determin winner loser draw
void winner_loser()
{
	if (p_sum < 22 && p_sum > c_sum)
		cout << "YOU WON" << endl;

	else if (p_sum < 22 && (p_sum < c_sum && c_sum <22))
		cout << "YOU LOST" << endl;

	else if ((p_sum < 22 && p_sum == c_sum) || p_sum > 21 && c_sum > 21)
		cout << "DRAW" << endl;

	else if (p_sum > 21)
		cout << "BUSTED" << endl;

	else if (c_sum > 21)
		cout << "CPU BUSTED" << endl;
}