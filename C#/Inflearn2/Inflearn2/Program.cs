using System;

namespace Inflearn2
{
    class Program
    {
        static void Main(string[] args)
        {
            
            const int WAIT_TICK = 1000 / 30;
            int currentTick = System.Environment.TickCount;
            int deltaTick = 0;
            int lastTick = System.Environment.TickCount;
            Board board = new Board();
            Console.CursorVisible = false;
            while (true)
            {
                #region 프레임관리
                currentTick = System.Environment.TickCount;
                deltaTick = currentTick - lastTick;
                if (deltaTick < WAIT_TICK)
                    continue;
                lastTick = currentTick;
                #endregion

                // 입력

                // 로직

                // 랜더링
                Console.SetCursorPosition(0, 0);
                board.Render();

            }
        }
    }
}
