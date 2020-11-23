#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

#define REST_ID -2
#define OPPONENT_CAST "OPPONENT_CAST"
#define CAST "CAST"
#define BREW "BREW"

// ----------------------------
// class

class ingredient
{
public:
	static int count;
	static int check_insufficient(vector<int>& plus, vector<int>& minus);
	static void copy(vector<int>& dist, vector<int>& src);
	static void plus(vector<int>& dist, vector<int>& src);
};

class player
{
public:
	int id;
	vector<int> ingredient;
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
	string action_type;
	vector<int> ingredient;
	bool is_called;

	action();

	void show();
};

class order : public action
{
public:
	int prise;

	order();

	void show();
};

class spell : public action
{
public:
	bool castable;
	bool opponent;

	spell();

	void show();
};

class gamedata
{
public:
	int action_count;
	map<int, order> orders;
	vector<player> players;
	vector<vector<spell>> spells; 

	gamedata();

	int search_action(int id, string type);
	void turn_is_called(bool flag);
	void check_is_called();
	void input_data();
	void show();
	void play();

	bool can_order(int p_id, int o_id);
	bool can_order(int p_id, vector<int> o_ids);
	int calc_order_count(int p_id, int o_id, int &act_id);
};

// ----------------------

gamedata game;
int turn;
const int max_turn = 100;
int ingredient::count = 4;

// ----------------------
// class function
// gamedata

gamedata::gamedata()
	: players({0, 1})
{
	for (int i = 0; i < 2; ++i)
	{
		vector<spell> s;
		spells.push_back(s);
	}
}

int gamedata::search_action(int id, string type)
{
	int p;
	if (type == BREW)
	{
		auto it = orders.find(id);
		if (it == orders.end())
			return (-1);
		return (id);
	}
	p = (type == OPPONENT_CAST);
	if (spells[p].size() == 0)
		return (-1);
	for (int i = 0; i < spells[p].size(); i++)
		if (spells[p][i].action_id == id)
			return (i);
	return (-1);
}

void gamedata::turn_is_called(bool flag = false)
{
	for (auto& [key, order] : orders)
		order.is_called = flag;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < spells[i].size(); ++j)
			spells[i][j].is_called = flag;
	}
}

void gamedata::check_is_called()
{
	vector<int> erase_kye;

	for (auto& [key, order] : orders)
		if (!order.is_called)
			erase_kye.push_back(key);
	for (int i = 0; i < erase_kye.size(); i++)
		orders.erase(erase_kye[i]);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < spells[i].size(); ++j)
			if (!spells[i][j].is_called)
				spells[i].erase(spells[i].begin() + j--);
	}
}

void gamedata::input_data()
{
	int index;
	int temp;
	int id;
	string type;

	turn_is_called();
	cin >> action_count;
	for (int i = 0; i < action_count; ++i)
	{
		cin >> id
			>> type;
		if (type == BREW)
		{
			order ord;
			ord.action_id = id;
			ord.action_type = type;
			for (int j = 0; j < ingredient::count; ++j)
				cin >> ord.ingredient[j];
			cin >> ord.prise
				>> temp >> temp >> temp >> temp;
			if (search_action(ord.action_id, type) == -1)
				orders[ord.action_id] = ord;
			else
				orders[ord.action_id].is_called = true;
		}
		else
		{
			spell spe;
			spe.action_id = id;
			spe.action_type = type;
			for (int j = 0; j < ingredient::count; ++j)
				cin >> spe.ingredient[j];
			cin >> temp >> temp >> temp;
			cin >> spe.castable; 
			cin >> temp;
			spe.opponent = (type == OPPONENT_CAST);
			if ((index = search_action(spe.action_id, type)) == -1)
				spells[spe.opponent].push_back(spe);
			else
			{
				spells[spe.opponent][index].castable = spe.castable;
				spells[spe.opponent][index].is_called = true;
			}
		}
		cerr << i << " " << type << endl;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < ingredient::count; ++j)
			cin >> players[i].ingredient[j];
		cin >> players[i].score;
	}
	check_is_called();
}

void gamedata::show()
{
	cerr << "action_count: " << action_count << '\n'
		<< "ingredient::count: " << ingredient::count << endl;
	cerr << "players----------------------" << endl;
	for (int i = 0; i < 2; ++i)
		players[i].show();
	cerr << "orders--------------------------" << endl;
	for (auto& [key, order] : orders)
        order.show();
	cerr << "my_spells----------------------" << endl;
	for (int i = 0; i < spells[0].size(); ++i)
		spells[0][i].show();
	cerr << "opponent_spells----------------------" << endl;
	for (int i = 0; i < spells[1].size(); ++i)
		spells[1][i].show();
}

void gamedata::play()
{
	int min_count = INT_MAX;
	int max_id = -1;
	int temp_count;

	for (auto& [id, order] : orders)
	{
		if (max_id == -1)
			max_id = id;
		int act_id = -1;
		temp_count = calc_order_count(0, id, act_id);
		// cerr << id << ": " << temp_count << endl;
		if (min_count < temp_count)
			continue ;
		min_count = temp_count;
		max_id = act_id;
	}
	if (max_id == REST_ID)
	{
		cout << "REST" << endl;
		return ;
	}
	auto it = orders.find(max_id);
	if (it != orders.end())
	{
		cout << "BREW " << max_id << endl;
		return ;
	}
	cout << "CAST " << max_id << endl;
}

bool gamedata::can_order(int p_id, int o_id)
{
	return (ingredient::check_insufficient(players[p_id].ingredient, 
											orders[o_id].ingredient) == -1);
}

bool gamedata::can_order(int p_id, vector<int> o_ids)
{
	int temp;
	for (int i = 0; i < ingredient::count; ++i)
	{
		temp = 0;
		for (int j = 0; j < o_ids.size(); ++j)
			temp += orders[o_ids[j]].ingredient[i];
		if (players[p_id].ingredient[i] < - temp)
			return (false);
	}
	return (true);
}

int gamedata::calc_order_count(int p_id, int o_id, int &act)
{
	int t = 0, insufficient_index, temp_index;
	vector<int> ingred(ingredient::count, 0);
	vector<bool> castable(ingredient::count);
	bool flag;

	ingredient::copy(ingred, players[p_id].ingredient);
	for (int i = 0; i < ingredient::count; ++i)
		castable[i] = spells[p_id][i].castable;
	while (t < max_turn - turn)
	{
		insufficient_index = ingredient::check_insufficient(ingred, orders[o_id].ingredient);
		if (insufficient_index == -1)
			break ;
		flag = true;
		for (int i = 0; i < spells[p_id].size(); ++i)
		{
			for (int j = 0; j < spells[p_id].size(); ++j)
			{
				if (!castable[j] || spells[p_id][j].ingredient[insufficient_index] <= 0)
					continue ;
				cerr << i << " " << j << " " << t << endl;
				temp_index = ingredient::check_insufficient(ingred, spells[p_id][j].ingredient);
				if (temp_index != -1)
					insufficient_index = temp_index;
				else
				{
					if (t == 0)
						act = spells[p_id][j].action_id;
					ingredient::plus(ingred, spells[p_id][j].ingredient);
					for (int k = 0; k < 4; k++)
						cerr << ingred[k] << " ";
					cerr << endl;
					castable[j] = false;
					flag = false;
				}
				break ;
			}
			if (temp_index == -1)
				break ;
		}
		if (flag)
		{
			if (t == 0)
				act = REST_ID;
			for (int i = 0; i < ingredient::count; ++i)
				castable[i] = true;
		}
		++t;
	}
	if (t == 0)
		act = o_id;
	cerr << t << " " << act << endl;
	return (t);
}

// ------------------------
// player

player::player(int id)
	: ingredient({0, 0, 0, 0}), id(id), potion(0) {}

player::player()
	: player(0) {}

void player::show()
{
	cerr << "player: " << id << '\n'
		<< "potion: " << potion << '\n'
		<< "ingredient\n";
	for (int i = 0; i < ingredient::count; ++i)
		cerr << i << ": " << ingredient[i] << '\n';
	cerr << "score: " << score << endl;
}

// -------------------------
// action

action::action()
	: ingredient({0, 0, 0, 0}), is_called(true) {}

void action::show()
{
	cerr << "action: " << action_id << '\n'
		<< "action_type: " << action_type << '\n';
	for (int i = 0; i < ingredient::count; ++i)
		cerr << i << ": " << ingredient[i] << '\n';
}

// ---------------------------------
// order

order::order()
	: action() {}

void order::show()
{
	cerr << "order: " << action_id << '\n'
		<< "action_type: " << action_type << '\n';
	for (int i = 0; i < ingredient::count; ++i)
		cerr << i << ": " << ingredient[i] << '\n';
	cerr << "price: " << prise << endl;
}

// ---------------------------------
// spell

spell::spell()
	: action() {}

void spell::show()
{
	cerr << "spell: " << action_id << '\n'
		<< "action_type: " << action_type << '\n'
		<< "castable: " << castable << '\n';
	for (int i = 0; i < ingredient::count; ++i)
		cerr << i << ": " << ingredient[i] << '\n';
	
}

// -----------------------------
// ingredient

int ingredient::check_insufficient(vector<int>& plus, vector<int>& minus)
{
	for (int i = 0; i < count; ++i)
		if (plus[i] < - minus[i])
			return (i);
	return (-1);
}

void ingredient::copy(vector<int>& dist, vector<int>& src)
{
	for (int i = 0; i < count; ++i)
		dist[i] = src[i];
}

void ingredient::plus(vector<int>& dist, vector<int>& src)
{
	for (int i = 0; i < count; ++i)
		dist[i] += src[i];
}


// ----------------------
// main

int main()
{
	turn = 0;
	while (1)
	{
		game.input_data();
		game.show();
		game.play();
		++turn;
	}
}
