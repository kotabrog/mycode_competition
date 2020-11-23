#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <random>
#include <chrono>
#include <memory>
#include <queue>

using namespace std;

#define REST_ID -2
#define OPPONENT_CAST_S "OPPONENT_CAST"
#define CAST_S "CAST"
#define BREW_S "BREW"
#define LEARN_S "LEARN"
#define REST_S "REST"
#define ERROR_S "ERROR"

#define OPPONENT_CAST 'o'
#define CAST 'c'
#define BREW 'b'
#define LEARN 'l'
#define REST 'r'
#define ERROR 'e'


// ----------------------------
// class


class ch_time
{
public:
	vector<chrono::system_clock::time_point> time_line;
	vector<string> point_string;

	ch_time();
	void record();
	void record(string s);
	void show();
	void show(const int &n);
	void show(const int &start, int end);
	double measur(const int n);
	double measur();
};

class ingred
{
public:
	static int count;
	static int check_insufficient(const vector<int>& plus_vec, const vector<int>& minus_vec, bool plus_mode=false);
	static void plus_vec(vector<int>& dist, const vector<int>& src);
	static void minus_vec(vector<int>& dist, const vector<int>& src);
	static int sum_vec(const vector<int>& a);
	static int sum_vec(const vector<int>& a, const vector<int>& b);
};

class output
{
public:
	char type;
	int times;
	int index;

	output();
	output(const output &act);
	void set_output(char type, int index = 0, int times = 1);
	void set_output(const output &act);
	void put_action();
	void put_action(const int &n);
	string type_c_to_s();
	int put_id();
};

class config
{
public:
	static int turn;
	static int max_turn;
	static int max_ingred;
	static ch_time time;
	static int last_time_point;
	static int action_count;
	static int max_order_point;

	static int potion_ratio;
	static vector<int> ingred_ratio;
	static vector<int> order_bonus;
	static vector<int> max_order_bonus;
	
	static vector<vector<int>> spells;
	static vector<vector<int>> orders;

	static char type_s_to_c(const string &s);
	static string type_c_to_s(const char c);

	static int search_order(vector<int> &ingred);
	static int search_spell(vector<int> &ingred);
};

class player
{
public:
	int id;
	vector<int> ingred;
	int sum_ingred;
	int emp_ingred;
	int score;
	int potion;

	player();
	player(int id);

	void show();
};

class action
{
public:
	int action_id;
	char action_type;
	int tax_count;
	int tome_index;
	bool is_called;
	int index;

	action();

	void show();
};

class order : public action
{
public:
	int price;

	order();

	void show();
};

class spell : public action
{
public:
	bool castable;
	bool repeatable;

	spell();

	void show();
};

// breadth_first_search not learn
class bfs_nl
{
public:
	vector<int> ingred;
	int sum_ingred;
	int emp_ingred;
	vector<int> spells;
	vector<int> castable;
	vector<int> orders;
	// vector<int> learns;
	// vector<int> tax;
	output first_act;
	int score;
	int turn;
	int point;

	bfs_nl();
	bfs_nl(const bfs_nl & bfs);
	
	int can_brew();
	bool can_cast(int index);
	bool can_learn(int index);
	int can_cast_times(int index);

	void play(output &act);
};

class evaluation
{
public:
	int point;
	int turn;
	int max_point;
	output max_act;

	evaluation();
	void evaluate(bfs_nl &bfs);
};

class gamedata
{
public:
	vector<order> orders;
	vector<player> players;
	vector<vector<spell>> spells;

	gamedata();
	void input_data();
	void show();

	void turn_is_called(const bool flag=false);
	void check_is_called();

	int search_order_index(int index);
	int search_spell_index(int index, int k);

	void bfs_nl_play(evaluation &eval, bool mode=false);
};



// ------------------------------

mt19937 mt{random_device{}()};
ch_time config::time;
int last_time_point = 0;

int config::turn = 0;
int config::max_turn = 100;
int config::max_ingred = 10;
int config::action_count = 0;
int config::max_order_point = 21;
int ingred::count = 4;

vector<int> config::ingred_ratio = {1, 2, 2, 2};
vector<int> config::order_bonus = {3, 1, 0, 0, 0};
vector<int> config::max_order_bonus = {4, 4, 0, 0, 0};

gamedata game;

// ing1, ing2, ing3, ing4, sum
vector<vector<int>> config::spells = {
	{2,0,0,0,2},
	{-1,1,0,0},
	{0,-1,1,0,0},
	{0,0,-1,1,0},
	{-3,0,0,1,-2},
	{3,-1,0,0,2},
	{1,1,0,0,2},
	{0,0,1,0,1},
	{3,0,0,0,3},
	{2,3,-2,0,3},
	{2,1,-2,1,2},
	{3,0,1,-1,3},
	{3,-2,1,0,2},
	{2,-3,2,0,1},
	{2,2,0,-1,3},
	{-4,0,2,0,-2},
	{2,1,0,0,3},
	{4,0,0,0,4},
	{0,0,0,1,1},
	{0,2,0,0,2},
	{1,0,1,0,2},
	{-2,0,1,0,-1},
	{-1,-1,0,1,-1},
	{0,2,-1,0,1},
	{2,-2,0,1,1},
	{-3,1,1,0,-1},
	{0,2,-2,1,1},
	{1,-3,1,1,0},
	{0,3,0,-1,2},
	{0,-3,0,2,-1},
	{1,1,1,-1,2},
	{1,2,-1,0,2},
	{4,1,-1,0,4},
	{-5,0,0,2,-3},
	{-4,0,1,1,-2},
	{0,3,2,-2,3},
	{1,1,3,-2,3},
	{-5,0,3,0,-2},
	{-2,0,-1,2,-1},
	{0,0,-3,3,0},
	{0,-3,3,0,0},
	{-3,3,0,0,0},
	{-2,2,0,0,0},
	{0,0,-2,2,0},
	{0,-2,2,0,0},
	{0,0,2,-1,1},
};

// ing1, ing2, ing3, ing4, price, sum
vector<vector<int>> config::orders = {
	{2,2,0,0,6,4},
	{3,2,0,0,7,5},
	{0,4,0,0,8,4},
	{2,0,2,0,8,4},
	{2,3,0,0,8,5},
	{3,0,2,0,9,5},
	{0,2,2,0,10,4},
	{0,5,0,0,10,5},
	{2,0,0,2,10,4},
	{2,0,3,0,11,5},
	{3,0,0,2,11,5},
	{0,0,4,0,12,4},
	{0,2,0,2,12,4},
	{0,3,2,0,12,5},
	{0,2,3,0,13,5},
	{0,0,2,2,14,4},
	{0,3,0,2,14,5},
	{2,0,0,3,14,5},
	{0,0,5,0,15,5},
	{0,0,0,4,16,4},
	{0,2,0,3,16,5},
	{0,0,3,2,17,5},
	{0,0,2,3,18,5},
	{0,0,0,5,20,5},
	{2,1,0,1,9,4},
	{0,2,1,1,12,4},
	{1,0,2,1,12,4},
	{2,2,2,0,13,6},
	{2,2,0,2,15,6},
	{2,0,2,2,17,6},
	{0,2,2,2,19,6},
	{1,1,1,1,12,4},
	{3,1,1,1,14,6},
	{1,3,1,1,16,6},
	{1,1,3,1,18,6},
	{1,1,1,3,20,6},
};

// -------------------------------
// gamedata

gamedata::gamedata()
	: players({0, 1})
{
	for (int i = 0; i < 3; ++i)
	{
		vector<spell> s;
		spells.push_back(s);
	}
}

void gamedata::input_data()
{
	int index;
	int temp;
	int id;
	string s_type;
	char type;
	vector<int> ingred(4);
	int col;

	turn_is_called();
	cin >> config::action_count;
	config::time.record("input start");
	for (int i = 0; i < config::action_count; ++i)
	{
		cin >> id
			>> s_type;
		type = config::type_s_to_c(s_type);
		if (type == BREW)
		{
			order ord;
			ord.action_id = id;
			ord.action_type = type;
			for (int j = 0; j < ingred::count; ++j)
				cin >> ingred[j];
			cin >> ord.price
				>> ord.tome_index
				>> ord.tax_count >> temp >> temp;
			ord.index = config::search_order(ingred);
			// cerr << ord.index << ' ';
			if ((index = search_order_index(ord.index)) == -1)
				orders.push_back(ord);
			else
			{
				orders[index].is_called = true;
				orders[index].tome_index = ord.tome_index;
				orders[index].tax_count = ord.tax_count;
				orders[index].price = ord.price;
			}
		}
		else
		{
			spell spe;
			spe.action_id = id;
			spe.action_type = type;
			for (int j = 0; j < ingred::count; ++j)
				cin >> ingred[j];
			cin >> temp
			>> spe.tome_index
			>> spe.tax_count
			>> spe.castable
			>> spe.repeatable;
			col = (type == CAST ? 0 : type == OPPONENT_CAST ? 1 : 2);
			spe.index = config::search_spell(ingred);
			if ((index = search_spell_index(spe.index, col)) == -1)
				spells[col].push_back(spe);
			else
			{
				if (spe.action_type == LEARN)
				{
					spells[2][index].is_called = true;
					spells[2][index].tax_count = spe.tax_count;
				}
				else
				{
					spells[col][index].action_id = spe.action_id;
					spells[col][index].action_type = spe.action_type;
					spells[col][index].castable = spe.castable;
					spells[col][index].is_called = true;
				}
			}
		}
		// std::cerr << i << " " << type << endl;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < ingred::count; ++j)
			cin >> players[i].ingred[j];
		cin >> temp;
		if (temp != players[i].score)
		{
			++(players[i].potion);
			players[i].score = temp;
		}
		players[i].sum_ingred = ingred::sum_vec(players[i].ingred);
		players[i].emp_ingred = config::max_ingred - players[i].sum_ingred;
	}
	check_is_called();
}

void gamedata::show()
{
	std::cerr << "players----------------------" << endl;
	for (int i = 0; i < 2; ++i)
		players[i].show();
	std::cerr << "orders--------------------------" << endl;
	for (int i = 0; i < orders.size(); ++i)
        orders[i].show();
	std::cerr << "my_spells----------------------" << endl;
	for (int i = 0; i < spells[0].size(); ++i)
		spells[0][i].show();
	std::cerr << "opponent_spells----------------------" << endl;
	for (int i = 0; i < spells[1].size(); ++i)
		spells[1][i].show();
	std::cerr << "learn_spells----------------------" << endl;
	for (int i = 0; i < spells[2].size(); ++i)
		spells[2][i].show();
}


void gamedata::turn_is_called(const bool flag)
{
	for (int i = 0; i < orders.size(); ++i)
		orders[i].is_called = flag;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < spells[i].size(); ++j)
			spells[i][j].is_called = flag;
	}
}

void gamedata::check_is_called()
{
	for (int i = 0; i < orders.size(); ++i)
		if (!orders[i].is_called)
			orders.erase(orders.begin() + i--);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < spells[i].size(); ++j)
			if (!spells[i][j].is_called)
				spells[i].erase(spells[i].begin() + j--);
	}
}

int gamedata::search_order_index(int index)
{
	for (int i = 0; i < orders.size(); ++i)
	{
		if (orders[i].index == index)
			return (i);
	}
	return (-1);
}

int gamedata::search_spell_index(int index, int k)
{
	for (int i = 0; i < spells[k].size(); ++i)
	{
		if (spells[k][i].index == index)
			return (i);
	}
	return (-1);
}

void gamedata::bfs_nl_play(evaluation &eval, bool mode)
{
	vector<bfs_nl> bfses;
	int bfses_index = 0;
	int index;
	int times;
	int eval_start_point = 0;
	int eval_end_point = 1;
	int stop_time = 26;
	int max_point = -1000;

	if (mode)
	{
		stop_time = 12;
		game.spells[0].push_back(game.spells[2][0]);
		bfses.push_back(bfs_nl());
		++(bfses[0].turn);
		bfses[0].first_act.set_output(LEARN, 0);
		bfses[0].ingred[0] += min(bfses[0].emp_ingred, game.spells[2][0].tax_count);
		eval.evaluate(bfses[0]);
		bfses[0].point += eval.point - 10;
		eval.turn = 1;
	}
	else
		bfses.push_back(bfs_nl());
	while (config::time.measur() < stop_time && bfses_index < bfses.size())
	{
		if (bfses[bfses_index].turn > eval.turn)
		{
			eval.turn = bfses[bfses_index].turn;
			eval_start_point = eval_end_point;
			eval_end_point = bfses_index;
		}
		if (eval.turn > 2 + mode && bfses[bfses_index].point < max_point && mt() % 100 < 30)
		{
			bfses_index++;
			continue;
		}
		index = bfses[bfses_index].can_brew();
		if (index >= 0)
		{
			output act;
			bfs_nl temp_bfs(bfses[bfses_index]);
			++temp_bfs.turn;
			act.set_output(BREW, index);
			temp_bfs.play(act);
			eval.evaluate(temp_bfs);
			temp_bfs.point += eval.point;
			max_point = max(temp_bfs.point, max_point);
			bfses.push_back(temp_bfs);
		}
		for (int i = 0; i < bfses[bfses_index].spells.size(); ++i)
		{
			if (bfses[bfses_index].can_cast(i))
			{
				times = bfses[bfses_index].can_cast_times(i);
				for (int j = 1; j <= times; ++j)
				{
					bfs_nl temp_bfs(bfses[bfses_index]);
					output act;
					++temp_bfs.turn;
					act.set_output(CAST, i, j);
					temp_bfs.play(act);
					eval.evaluate(temp_bfs);
					temp_bfs.point += eval.point;
					max_point = max(temp_bfs.point, max_point);
					bfses.push_back(temp_bfs);
				}
				if (config::time.measur() > stop_time)
					break ;
			}
		}
		// for (int i = 0; i < bfses[bfses_index].learns.size(); ++i)
		// {
		// 	if (bfses[bfses_index].can_learn(i))
		// 	{
		// 		bfs_nl temp_bfs(bfses[bfses_index]);
		// 		output act;
		// 		++temp_bfs.turn;
		// 		act.set_output(LEARN, i);
		// 		temp_bfs.play(act);
		// 		eval.evaluate(temp_bfs);
		// 		temp_bfs.point += eval.point;
		// 		bfses.push_back(temp_bfs);
		// 		if (config::time.measur() > stop_time)
		// 			break ;
		// 	}
		// }
		bool flag = false;
		for (int i = 0; i < bfses[bfses_index].castable.size(); ++i)
		{
			if (!bfses[bfses_index].castable[i])
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			bfs_nl temp_bfs(bfses[bfses_index]);
			++temp_bfs.turn;
			output act;
			act.set_output(REST);
			temp_bfs.play(act);
			eval.evaluate(temp_bfs);
			temp_bfs.point += eval.point;
			max_point = max(temp_bfs.point, max_point);
			bfses.push_back(temp_bfs);
		}
		++bfses_index;
	}
	// std::cerr << endl;
	std::cerr << eval_start_point << ' ' << eval_end_point << endl;
	config::time.record("after bfs");
	for (int i = eval_start_point; i < eval_end_point; ++i)
	{
		if (eval.max_point < bfses[i].point)
		{
			eval.max_point = bfses[i].point;
			eval.max_act = bfses[i].first_act;
			std::cerr << eval.max_act.type << ',' << i << ' ';
		}
	}
	std::cerr << endl;
	std::cerr << eval.max_act.type << ' ' << eval.max_point << ' ' << eval.turn << endl;
	config::time.record("after eval");
}


// -------------------------
// action

action::action()
	: is_called(true) {}

void action::show()
{
	std::cerr << "action: " << action_id << '\n'
		<< "action_type: " << action_type << '\n'
		<< "is_called: " << is_called << '\n'
		<< "tax_count: " << tax_count << '\n'
		<< "tome_index: " << tome_index << '\n'
		<< "index: " << index << '\n';
}

// ---------------------------------
// order

order::order()
	: action() {}

void order::show()
{
	std::cerr << "order: " << action_id << '\n'
		<< "action_type: " << action_type << '\n'
		<< "is_called: " << is_called << '\n'
		<< "tax_count: " << tax_count << '\n'
		<< "tome_index: " << tome_index << '\n';
	for (int i = 0; i < ingred::count; ++i)
		std::cerr << config::orders[index][i] << ", ";
	std::cerr << '\n';
	std::cerr << "price: " << price << endl;
}

// ---------------------------------
// spell

spell::spell()
	: action(), repeatable(0) {}

void spell::show()
{
	std::cerr << "spell: " << action_id << '\n'
		<< "action_type: " << action_type << '\n'
		<< "castable: " << castable << '\n'
		<< "repeatable: " << repeatable << '\n'
		<< "tome_index: " << tome_index << '\n'
		<< "tax_count: " << tax_count << '\n';
	for (int i = 0; i < ingred::count; ++i)
		std::cerr << config::spells[index][i] << ", ";
	std::cerr << '\n';
}

// ------------------------
// player

player::player(int id)
	: ingred({0, 0, 0, 0}), sum_ingred(0), emp_ingred(config::max_ingred), id(id), potion(0), score(0) {}

player::player()
	: player(0) {}

void player::show()
{
	std::cerr << "player: " << id << '\n'
		<< "potion: " << potion << '\n'
		<< "ingredient\n";
	for (int i = 0; i < ingred::count; ++i)
		std::cerr << i << ": " << ingred[i] << '\n';
	std::cerr << "score: " << score << endl;
}



// ------------------------
// output

output::output() : type('e'), times(0), index(0) {}

output::output(const output &act) 
	: type(act.type), times(act.times), index(act.index) {}

void output::set_output(char type, int index, int times)
{
	this->type = type;
	this->index = index;
	this->times = times;
}

void output::set_output(const output &act)
{
	set_output(act.type, act.index, act.times);
}

void output::put_action(const int &n)
{
	if (n == 1)
		cout << type_c_to_s() << endl;
	else if (n == 2)
		cout << type_c_to_s() << ' ' << put_id() << endl;
	else if (n == 3)
		cout << type_c_to_s() << ' ' << put_id() << ' ' << times << endl;
	else
		std::cerr << "put_action error" << endl;
}

void output::put_action()
{
	if (type == CAST && times >= 2)
		put_action(3);
	else if (type == REST)
		put_action(1);
	else
		put_action(2);
}

string output::type_c_to_s()
{
	return (config::type_c_to_s(type));
}

int output::put_id()
{
	if (type == OPPONENT_CAST)
		return game.spells[1][index].action_id;
	if (type == CAST)
		return game.spells[0][index].action_id;
	if (type == BREW)
		return game.orders[index].action_id;
	if (type == LEARN)
		return game.spells[2][index].action_id;
	if (type == REST)
		return REST_ID;
	if (type == ERROR)
		return -1;
}


// ----------------------------
// config

char config::type_s_to_c(const string &s)
{
	if (s == OPPONENT_CAST_S)
		return OPPONENT_CAST;
	if (s == CAST_S)
		return CAST;
	if (s == BREW_S)
		return BREW;
	if (s == LEARN_S)
		return LEARN;
	if (s == REST_S)
		return REST;
	if (s == ERROR_S)
		return ERROR;
}

string config::type_c_to_s(const char c)
{
	if (c == OPPONENT_CAST)
		return OPPONENT_CAST_S;
	if (c == CAST)
		return CAST_S;
	if (c == BREW)
		return BREW_S;
	if (c == LEARN)
		return LEARN_S;
	if (c == REST)
		return REST_S;
	if (c == ERROR)
		return ERROR_S;
}

int config::search_order(vector<int> &ingred)
{
	bool flag;
	for (int i = 0; i < orders.size(); ++i)
	{
		flag = true;
		for (int j = 0; j < ingred::count; ++j)
		{
			if (ingred[j] != - orders[i][j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return (i);
	}
}

int config::search_spell(vector<int> &ingred)
{
	bool flag;
	for (int i = 0; i < spells.size(); ++i)
	{
		flag = true;
		for (int j = 0; j < ingred::count; ++j)
		{
			if (ingred[j] != spells[i][j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return (i);
	}
}



// -----------------------------
// ingred

int ingred::check_insufficient(const vector<int>& plus_vec, const vector<int>& minus_vec, bool plus_mode)
{
	for (int i = 0; i < count; ++i)
		if (plus_vec[i] < (plus_mode ? 1 : -1) * minus_vec[i])
			return (i);
	return (-1);
}

void ingred::plus_vec(vector<int>& dist, const vector<int>& src)
{
	for (int i = 0; i < count; ++i)
		dist[i] += src[i];
}

void ingred::minus_vec(vector<int>& dist, const vector<int>& src)
{
	for (int i = 0; i < count; ++i)
		dist[i] -= src[i];
}

int ingred::sum_vec(const vector<int>& a)
{
	int temp = 0;

	for (int i = 0; i < count; ++i)
		temp += a[i];
	return (temp);
}

int ingred::sum_vec(const vector<int>& a, const vector<int>& b)
{
	return (sum_vec(a) + sum_vec(b));
}


// ---------------------------
// ch_time

ch_time::ch_time()
{
	record("start point");
}

void ch_time::record(string s)
{
	time_line.push_back(chrono::system_clock::now());
	point_string.push_back(s);
}

void ch_time::record()
{
	record("point: " + to_string(time_line.size()));
}

void ch_time::show(const int &n)
{
	auto time = (time_line[n + 1] - time_line[n]).count() / 1000000.0;
	std::cerr << point_string[n] << " to " << point_string[n + 1] << '\n'
		<< "              : " << time << " milli sec\n";
}

void ch_time::show(const int &start, int end)
{
	if (end == -1)
		end = time_line.size() - 1;
	for (int i = start; i < end; ++i)
		show(i);
}

void ch_time::show()
{
	show(0, time_line.size() - 1);
}

double ch_time::measur(const int n)
{
	return ((chrono::system_clock::now() - time_line[n]).count() / 1000000.0);
}

double ch_time::measur()
{
	return (measur(time_line.size() - 1));
}

// --------------------------------
// evaluation

evaluation::evaluation() : point(0), turn(0), max_point(-10000) {}

void evaluation::evaluate(bfs_nl &bfs)
{
	int temp = 0;
	if (game.players[0].potion == 5)
	{
		temp += bfs.score - game.players[1].score;
		for (int i = 1; i < ingred::count; ++i)
		{
			temp += bfs.ingred[i];
			temp -= game.players[1].ingred[i];
		}
	}

	point = 0;

	point += 100 * (bfs.score - game.players[0].score);

	int min_in_suf = 30;
	for (int i = 0; i < bfs.orders.size(); ++i)
	{
		int in_suf = 0;

		if (game.players[0].potion == 5)
		{
			int temp2 = config::orders[game.orders[bfs.orders[i]].index][4];
			for (int j = 1; j < ingred::count; ++j)
				temp2 -= config::orders[game.orders[bfs.orders[i]].index][j];
			if (temp + temp2 < 0)
				continue ;
		}

		for (int j = 0; j < ingred::count; ++j)
		{
			in_suf += max(0, config::orders[game.orders[bfs.orders[i]].index][j] - bfs.ingred[j]) * j;
			// in_suf += max(0, config::orders[game.orders[bfs.orders[i]].index][j] - bfs.ingred[j]);
		}
		min_in_suf = min(min_in_suf, in_suf);
		// min_in_suf = min(min_in_suf, in_suf) * (config::max_order_point - config::orders[game.orders[bfs.orders[i]].index][4]);
	}
	point -= min_in_suf;
	point -= bfs.emp_ingred;
	point /= max(turn, 1);
}




// ---------------------------------
// bfs_nl

bfs_nl::bfs_nl()
	: turn(0), score(game.players[0].score), 
	sum_ingred(game.players[0].sum_ingred), 
	emp_ingred(game.players[0].emp_ingred), 
	ingred(game.players[0].ingred), point(-1)
{
	for (int i = 0; i < game.spells[0].size(); ++i)
		spells.push_back(i);
	for (int i = 0; i < game.spells[0].size(); ++i)
		castable.push_back(game.spells[0][i].castable);
	for (int i = 0; i < game.orders.size(); ++i)
		orders.push_back(i);
	// for (int i = 0; i < game.spells[2].size(); ++i)
	// 	learns.push_back(i);
	// for (int i = 0; i < game.spells[2].size(); ++i)
	// 	tax.push_back(game.spells[2][i].tax_count);
}

bfs_nl::bfs_nl(const bfs_nl &bfs)
	: turn(bfs.turn), score(bfs.score),
	ingred(bfs.ingred), sum_ingred(bfs.sum_ingred),
	emp_ingred(bfs.emp_ingred), spells(bfs.spells),
	castable(bfs.castable), orders(bfs.orders),
	first_act(bfs.first_act), point(bfs.point)
	// learns(bfs.learns), tax(bfs.tax) 
{}

int bfs_nl::can_brew()
{
	int temp = 0;
	if (game.players[0].potion == 5)
	{
		temp += score - game.players[1].score;
		for (int i = 1; i < ingred::count; ++i)
		{
			temp += ingred[i];
			temp -= game.players[1].ingred[i];
		}
	}

	int index;
	for (int i = 0; i < orders.size(); ++i)
	{
		if (game.players[0].potion == 5)
		{
			int temp2 = config::orders[game.orders[orders[i]].index][4];
			for (int j = 1; j < ingred::count; ++j)
				temp2 -= config::orders[game.orders[orders[i]].index][j];
			if (temp + temp2 < 0)
				continue ;
		}
		if (ingred::check_insufficient(ingred, config::orders[game.orders[orders[i]].index], true) == -1)
			return (i);
	}
	return (-1);
}

bool bfs_nl::can_cast(int index)
{
	spell &spe = game.spells[0][spells[index]];
	vector<int> &spe_ingred = config::spells[game.spells[0][spells[index]].index];
	return (castable[index] &&
		ingred::check_insufficient(ingred, spe_ingred) == -1 &&
		spe_ingred[4] < emp_ingred);
}

bool bfs_nl::can_learn(int index)
{
	// if (ingred[0] < index)
	// 	return (false);
	// spell &spe = game.spells[2][learns[index]];
	// for (int i = 0; i < game.spells[0].size(); ++i)
	// 	if (game.spells[0][i].action_id == spe.action_id)
	// 		return (false);
	// return (true);
}

int bfs_nl::can_cast_times(int index)
{
	spell &spe = game.spells[0][spells[index]];
	if (!spe.repeatable)
		return (1);
	vector<int> temp_ingred = ingred;
	int temp_sum = sum_ingred;
	vector<int> &spe_ingred = config::spells[spe.index];

	for (int i = 0; i < 5; ++i)
	{
		temp_sum += spe_ingred[4];
		if (temp_sum > config::max_ingred)
			return (i);
		for (int j = 0; j < ingred::count; ++j)
		{
			temp_ingred[j] += spe_ingred[j];
			if (temp_ingred[j] < 0)
				return (i);
		}
	}
	return (5);
}

void bfs_nl::play(output &act)
{
	if (act.type == BREW)
	{
		int temp;
		score += config::order_bonus[act.index];
		temp = act.index;
		act.index = orders[temp];
		orders.erase(orders.begin() + temp);
		ingred::minus_vec(ingred, config::orders[game.orders[act.index].index]);
		score += config::orders[game.orders[act.index].index][4];
		sum_ingred -= config::orders[game.orders[act.index].index][5];
		emp_ingred += config::orders[game.orders[act.index].index][5];
	}
	else if (act.type == CAST)
	{
		castable[act.index] = false;
		act.index = spells[act.index];
		for (int i = 0; i < act.times; ++i)
			ingred::plus_vec(ingred, config::spells[game.spells[0][act.index].index]);
		sum_ingred += config::spells[game.spells[0][act.index].index][4];
		emp_ingred -= config::spells[game.spells[0][act.index].index][4];
	}
	// else if (act.type == LEARN)
	// {
		
	// }
	else if (act.type == REST)
	{
		for (int i = 0; i < castable.size(); ++i)
			castable[i] = true;
	}
	// cerr << turn << endl;
	if (turn == 1)
	{
		first_act = act;
		std::cerr << first_act.type << endl;
	}
}


// ---------------------------------------

int main()
{
	output act;
	while (1)
	{
		evaluation eval;
		game.input_data();
		config::time.record("after input");
		if (config::turn < 5)
			eval.max_act.set_output(LEARN, 0);
		else
		{
			game.bfs_nl_play(eval);
			game.bfs_nl_play(eval, true);
		}
		if (eval.max_point < 0 && 
			mt() % 100 < 75 - 5 * game.spells[0].size())
			eval.max_act.set_output(LEARN, 0);
		// config::time.show(last_time_point, -1);
		last_time_point = config::time.time_line.size();
		eval.max_act.put_action();
		++config::turn;
	}
}