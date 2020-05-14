#include "Game.h"
Game::Game()
{
	exit(1);
};

Game::Game(char* character_filename, char* monster_filename, char* debug_code)
{
	ifstream character_file;
	character_file.open(character_filename, ios::in);
	character_file.close();
};

Game::Game(const char* character_filename, const char* monster_filename, const char* debug_code)
{
	//富丞_腳色讀取
	ifstream character_file;
	character_file.open(character_filename, ios::in);
	int character_number;
	bool checkrole = true;
	character_file >> character_number; // role numbers
	for (; character_number > 0; character_number--)
	{
		static string card_id_action;
		int	card_speed_value;
		string comparedata = "attack range move shield heal";
		string character_name;
		int character_hp;
		int character_alpha_card;
		if (checkrole) // check whether first save
		{
			character_file >> character_name >> character_hp >> character_alpha_card; // role data
			checkrole = false;
		}
		else
		{
			character_name = card_id_action;
			character_file >> character_hp >> character_alpha_card; // role data
		}
		Character newrole(character_name, character_hp, character_alpha_card);// create role
		int character_card_number;
		character_file >> character_card_number;// newrole's card number 
		bool check = true;
		for (; character_card_number > 0; character_card_number--)// save newrole's card 
		{
			// use string deal with card data
			if (check)//because fstream will continue get and one content not includeing one action
				character_file >> card_id_action >> card_speed_value;// card data id speed
			else
			{
				character_file >> card_speed_value;// card data speed
				check = true;
			}
			CharacterCard newcard(card_id_action, card_speed_value); // card data action value
			while (character_file >> card_id_action)
			{
				if (card_id_action == "-")
				{
					check = false;
					continue;
				}
				if (check)
				{
					character_file >> card_speed_value;
					newcard.AddTop({ card_id_action ,card_speed_value });
				}
				else if (check == false && comparedata.find(card_id_action, 0) != -1)
				{
					character_file >> card_speed_value;
					newcard.AddUnder({ card_id_action ,card_speed_value });
				}
				else
				{
					break;
				}
			}
			newrole.AddCard(newcard);
		}
		character_list.push_back(newrole);
	}
	character_file.close();
	//end

	//原慶_怪物讀取
	ifstream monster_file;
	monster_file.open(monster_filename, ios::in);
	int monster_size = 0;
	monster_file >> monster_size;
	for (int count = 0; count < monster_size; count++)
	{
		string name;
		int hp;
		int attack;
		int range;
		monster_file >> name;
		monster_file >> hp;
		monster_file >> attack;
		monster_file >> range;
		Monster one(name);
		one.set_ordinary(hp, attack, range);
		monster_file >> hp;
		monster_file >> attack;
		monster_file >> range;
		one.set_elite(hp, attack, range);
		for (int i = 0; i < 6; i++)
		{
			monster_file >> name;
			vector<string> action_order;
			string str;
			string move_;
			int no = 0;
			int shield = 0;
			int speed = 0;
			hp = 0;
			attack = 0;
			range = 0;
			monster_file >> no;
			monster_file >> speed;
			while (monster_file >> str)
			{
				if (str == "d" || str == "r")
				{
					one.getcard(no, speed, move_, attack, range, hp, shield, str[0], action_order);
					break;
				}
				else if (str == "move")
				{
					monster_file >> move_;
					action_order.push_back(str);
				}
				else if (str == "attack")
				{
					monster_file >> attack;
					action_order.push_back(str);
				}
				else if (str == "heal")
				{
					monster_file >> hp;
					action_order.push_back(str);
				}
				else if (str == "range")
				{
					monster_file >> range;
					action_order.push_back(str);
				}
				else if (str == "shield")
				{
					monster_file >> shield;
					action_order.push_back(str);
				}
			}
		}
		monster_list.push_back(one);
	}
	monster_file.close();
	//end
};

void Game::Play()
{
	//富丞處理遊戲當中角色
	vector<PlayCharacter> playcharacterlist;
	int playernumber;
	cout << "請輸入出場角色數量:" << '\n';
	while (cin >> playernumber)
	{
		if (playernumber < 2 || playernumber > 4)
		{
			cout << "輸入錯誤，請輸入出場角色數量:" << '\n';
		}
		else
			break;
	}
	string name;
	for (; playernumber > 0; playernumber--)
	{
		cin >> name;
		int index = 0;
		while (character_list[index].getname() != name && index != (int)character_list.size())
			index++;
		if ( index == (int)character_list.size())
		{
			continue;
			playernumber++;
			cout << "查無此角色請重新輸入" << endl;
		}
		else
		{
			PlayCharacter reg( name , character_list[index].gethp());
			string id;
			for (int i = 0; i < character_list[index].getalpha_card(); i++)
			{
				cin >> id;
				reg.AddCard(character_list[index].getCard(id));
			}
			playcharacterlist.push_back(reg);
		}
	}
	

	string Map_name;
	cin >> Map_name;
	ifstream mapinput(Map_name) ;
	char** regmap; int wide; int length; mapinput >> length >> wide ;//地圖大小
	regmap = new char*[length];
	for ( int count = 0 ; count < length ; count++ )
	{
		string str;
		regmap[count] = new char[wide];
		mapinput >> str;
		for (int index = 0 ; index < wide ; index++ )
		{
			regmap[count][index] = str[index];
		}
	}
	Map game_map(regmap , length , wide);
	for (int count = 0; count < 4; count++)
	{
		int x, y;
		mapinput >> x >> y;
		game_map.totalmap[y][x] = '_';
		if (count == 3)
		{
			game_map.display_min_x = x;
			game_map.display_max_x = x;
			game_map.display_min_y = y;
			game_map.display_max_y = y;
			game_map.dealmap(x, y);
		}
	}
	//原慶處理遊戲當中怪物
	allmonster = AllMonster(monster_list);
	//原慶處理遊戲當中角怪物
	mapinput.close();
	//富丞處理遊戲當中角色
	game_map.check_initial();
	game_map.Printmap();
	//富丞角色配置位置
	for (int count = 0; count < (int)playcharacterlist.size(); count++)
	{
		string str;
		cin >> str;
		game_map.InitialMove(game_map.initial_x, game_map.initial_y, str, playcharacterlist[count]);
		game_map.totalmap[playcharacterlist[count].location.y][playcharacterlist[count].location.x] = (char) (count + 'A') ;
		if ( count == (int)playcharacterlist.size() - 1)
			game_map.clearinitial();
		game_map.Printmap();
	}
	//富丞角色配置位置
	return;
};
