#include"Character.h"
#include"Monster.h"
#include"Game.h"

int main(int argc, char *argv[]) {
	//讀取腳色檔案 敵人檔案 Debug_mode
	//Game game(argv[1], argv[2], argv[3]); //release用
	Game game("character1.txt","monster1.txt","1"); //DEBUG用
	string start;
	while (cin >> start)
	{
		if (start == "play")
		{
			game.Play();
		}
		else if (start == "exit")
		{
			exit(1);
		}
	}
	return 0;
}
