using System;

namespace Inflearn_1
{
    class Program
    {
        enum ClassType
        {
            NONE = 0,
            KNIGHT = 1,
            ARCHER = 2,
            WIZARD = 3
        }
        struct Player
        {
            public int hp;
            public int attack;
        }

        static ClassType ChooseClase()
        {
            ClassType choice = ClassType.NONE;

            Console.WriteLine("직업을 선택하세요. \n " +
                    "[{0}]기사 \n " +
                    "[{1}]궁수 \n " +
                    "[{2}]법사 \n ", (int)ClassType.KNIGHT, (int)ClassType.ARCHER, (int)ClassType.WIZARD);
            string input = Console.ReadLine();
            
            switch (input)
            {
                case "1":
                    choice = ClassType.KNIGHT;
                    break;
                case "2":
                    choice = ClassType.ARCHER;
                    break;
                case "3":
                    choice = ClassType.WIZARD;
                    break;
            }
            return choice;
        }
        static Player CreatePlayer(ClassType type)
        {
            Player player = new Player();
            switch (type)
            {
                case ClassType.KNIGHT:
                    player.hp = 100;
                    player.attack = 10;
                    break;
                case ClassType.ARCHER:
                    player.hp = 75;
                    player.attack = 12;
                    break;
                case ClassType.WIZARD:
                    player.hp = 60;
                    player.attack = 15;
                    break;
                default:
                    player.hp = 0;
                    player.attack = 0;
                    break;
            }
            return player;
        }
        static void Main(string[] args)
        {
            ClassType choice = ClassType.NONE;

            while (true)
            {
                choice = ChooseClase();
                if (choice != ClassType.NONE)
                {
                    Player player;
                    player = CreatePlayer(choice);
                    Console.WriteLine($"HP : {player.hp}, Attack {player.attack}");
                    break;
                }
            }
        }
    }
}
