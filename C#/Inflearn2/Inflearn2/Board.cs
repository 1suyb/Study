using System;
using System.Collections.Generic;
using System.Text;

namespace Inflearn2
{
   class Board
    {
        const char CIRCLE = '\u25cf';
        public void Render()
        {
            ConsoleColor prevColor = Console.ForegroundColor;

            for(int y = 0; y < 25; y++)
            {
                for(int x = 0; x < 25; x++)
                {
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write(CIRCLE);
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = prevColor;
        }
    }
}
