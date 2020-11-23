#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// ----------------------------
// class

class player
{
public:
	int id;
	vector<int> ingredient;
	int score;

	player();
	player(int id);

	void show();
};

class order
{
public:
	int action_id;
	string action_type;
	vector<int> ingredient;
	int prise;

	order();

	void show();
};

class gamedata
{
public:
	int action_count;
	int ingredient_count;
	map<int, order> orders;
	vector<player> players;

	gamedata();

	int search_order(int id);
	void input_data();
	void show();
	void play();

	bool can_order(int p_id, int o_id);
	bool can_order(int p_id, vector<int> o_ids);
};

// ----------------------

gamedata game;
int turn;

// ----------------------
// class function
// gamedata

gamedata::gamedata()
	: ingredient_count(4), players({0, 1}) {}

int gamedata::search_order(int id)
{
	auto it = orders.find(id);
	if (it == orders.end())
		return (-1);
	return (it->first);
}

void gamedata::input_data()
{
	int index;
	order ord;
	int temp;

	cin >> action_count;
	for (int i = 0; i < action_count; ++i)
	{
		cin >> ord.action_id
			>> ord.action_type;
		for (int j = 0; j < ingredient_count; ++j)
			cin >> ord.ingredient[j];
		cin >> ord.prise
			>> temp >> temp >> temp >> temp;
		if ((index = search_order(ord.action_id)) == -1)
			orders[ord.action_id] = ord;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < ingredient_count; ++j)
			cin >> players[i].ingredient[j];
		cin >> players[i].score;
	}
}

void gamedata::show()
{
	cerr << "action_count: " << action_count << '\n'
		<< "ingredient_count: " << ingredient_count << endl;
	cerr << "players" << endl;
	for (int i = 0; i < 2; ++i)
		players[i].show();
	cerr << "orders" << endl;
	for (auto& [key, order] : orders)
        order.show();
}

// void gamedata::play()
// {
// 	int max_price = 0;
// 	int max_id = -1;

// 	for (auto& [key, order] : orders)
// 	{
// 		if (max_id == -1)
// 			max_id = order.action_id;
// 		if (order.prise < max_price)
// 			continue ;
// 		if (can_order(0, key))
// 		{
// 			max_price = order.prise;
// 			max_id = order.action_id;
// 		}
// 	}
// 	cout << "BREW " << max_id << endl;
// }

void gamedata::play()
{
	int max_price = 0;
	vector<int> max_id = {-1, -1};
	vector<int> ids;
	int temp_price;


	for (auto& [id, order] : orders)
		ids.push_back(id);
	for (int i = 0; i < action_count; ++i)
	{
		for (int j = i; j < action_count; ++j)
		{
			if (max_id[0] == -1)
				max_id[0] = orders[i].action_id;

			if (i == j || 1 <= turn)
			{
				temp_price = orders[i].prise;
				if (temp_price < max_price)
					continue ;
				int temp_id = orders[i].action_id;
				if (can_order(0, temp_id))
				{
					max_price = temp_price;
					max_id[0] = orders[i].action_id;
					max_id[1] = -1;
				}
			}
			else
			{
				temp_price = orders[i].prise + orders[j].prise;
				if (temp_price < max_price)
					continue ;
				vector<int> temp_id = {orders[i].action_id, orders[j].action_id};
				if (can_order(0, temp_id))
				{
					max_price = temp_price;
					max_id[0] = orders[i].action_id;
					max_id[1] = orders[j].action_id;
				}
			}
		}
	}
	cout << "BREW " << max_id[0] << endl;
}

bool gamedata::can_order(int p_id, int o_id)
{
	for (int i = 0; i < ingredient_count; ++i)
		if (players[p_id].ingredient[i] < - orders[o_id].ingredient[i])
			return (false);
	return (true);
}

bool gamedata::can_order(int p_id, vector<int> o_id)
{
	int temp;
	for (int i = 0; i < ingredient_count; ++i)
	{
		temp = 0;
		for (int j = 0; j < o_id.size(); ++j)
			temp += orders[o_id[j]].ingredient[i];
		if (players[p_id].ingredient[i] < - temp)
			return (false);
	}
	return (true);
}

// ------------------------
// player

player::player(int id)
	: ingredient({0, 0, 0, 0}), id(id) {}

player::player()
	: player(0) {}

void player::show()
{
	cerr << "player: " << id << '\n'
		<< "ingredient\n";
	for (int i = 0; i < game.ingredient_count; ++i)
		cerr << i << ": " << ingredient[i] << '\n';
	cerr << "score: " << score << endl;
}

// -------------------------
// order

order::order()
	: ingredient({0, 0, 0, 0}) {}

void order::show()
{
	cerr << "order: " << action_id << '\n'
		<< "action_type" << action_type << '\n';
	for (int i = 0; i < game.ingredient_count; ++i)
		cerr << i << ": " << ingredient[i] << '\n';
	cerr << "price: " << prise << endl;
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
