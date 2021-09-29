using System;
using System.Collections.Generic;
using System.Text;

namespace Inflearn2
{
    /*
    class MyList<T>
    {
        const int DEFAULT_SIZE = 1;
        T[] _data = new T[DEFAULT_SIZE];

        public int Count = 0;   // 실제로 사용중인 데이터 개수
        public int Capacity { get { return _data.Length; } }    // 예약된 데이터 개수

        public void Add(T item)
        {
            // 1. 공간 확인
            if(Count >= Capacity)
            {
                // 공간을 늘려서 다시확보
                T[] newArray = new T[Count * 2];
                for(int i = 0; i < Count; i++)
                    newArray[i] = _data[i];
                _data = newArray;
            }

            // 2. 공간에 데이터를 넣어줌
            _data[Count] = item;
            Count++;
        }
        public T this[int index]
        {
            get { return _data[index]; }
            set { _data[index] = value; }
        }

        public void RemoveAt(int index)
        {
            for(int i = index; i < Count - 1; i++)
                _data[i] = _data[i + 1];
            _data[Count - 1] = default(T);
            Count--;
        }
    }
    class MyLinkedList<T>
    {
        public int Count = 0;
        public MyLinkedListNode<T> Head = null;
        public MyLinkedListNode<T> Tail = null;

        public MyLinkedListNode<T> AddLast(T data)
        {
            MyLinkedListNode<T> newNode = new MyLinkedListNode<T>();
            newNode.Data = data;

            if(Head == null)
            {
                Head = newNode;
            }

            if(Tail != null)
            {
                Tail._next = newNode;
                newNode._front = Tail;
            }

            Tail = newNode;
            Count++;
            return newNode;
        }
        public void Remove(MyLinkedListNode<T> node)
        {
            if(Head == node)
            {
                Head = Head._next;
            }
            if(Tail == node)
            {
                Tail = Tail._front;
            }
            if(node._front != null)
            {
                node._front._next = node._next;
            }
            if(node._next != null)
            {
                node._next._front = node._front;
            }
            Count--;
        }

    }
    class MyLinkedListNode<T>
    {
        public T Data;
        public MyLinkedListNode<T> _front;
        public MyLinkedListNode<T> _next;
    }
    */
    class Board
    {
        public TileType[,] _tile;
        public int _size;

        const char CIRCLE = '\u25cf';

        public enum TileType
        {
            Empty,
            Wall,
        }
        public void Initialize(int size)
        {
            _tile = new TileType[size, size];
            _size = size;
            
            for(int y = 0; y < _size; y++)
            {
                for(int x = 0; x < _size; x++)
                {
                    if (x == 0 || x == _size - 1 || y == 0 || y == _size - 1)
                        _tile[y, x] = TileType.Wall;
                    
                    else
                        _tile[y, x] = TileType.Empty;
                }
            }
        }
        public void Render()
        {
            ConsoleColor prevColor = Console.ForegroundColor;
            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    Console.ForegroundColor = GetTileColor(_tile[y,x]);
                    Console.Write(CIRCLE);
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = prevColor;
        }
        ConsoleColor GetTileColor(TileType type)
        {
            switch (type)
            {
                case TileType.Empty:
                    return ConsoleColor.Green;
                case TileType.Wall:
                    return ConsoleColor.Red;
                default:
                    return ConsoleColor.Green;
            }
        }
    }
    
}
