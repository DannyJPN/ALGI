using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GameOfLife
{
    class Program
    {
        static void GenerateRandomArray(bool[,] matrix)
        {
            Random n = new Random(DateTime.Now.Millisecond);
            int row, column, count = 0;

            while (count < 50)
            {
                row = n.Next(matrix.GetLength(0));
                column = n.Next(matrix.GetLength(1));
                if (!matrix[row, column])
                {
                    matrix[row, column] = true;
                    count++;
                }
            }



        }
        static void NullArray(bool[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    matrix[i, j] = false;
                }
            }
        }
        static void WriteArray(bool[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    if (matrix[i, j] && CheckAround(matrix, i, j) == 2 || CheckAround(matrix, i, j) == 3)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        if (matrix[i, j])
                        {

                            Console.Write("1 ");
                        }
                        else
                        {
                            Console.Write("0 ");
                        }
                        Console.ForegroundColor = ConsoleColor.Gray;
                    }
                    else
                    {
                        if (matrix[i, j])
                        {

                            Console.Write("1 ");
                        }
                        else
                        {
                            Console.Write("0 ");
                        }
                    }



                }
                Console.WriteLine();
            }
        }
        static int CheckAround(bool[,] matrix, int row, int col)
        {
            int alivecount = 0;
            //if (row >= 0 && col >= 0 && col < matrix.GetLength(0) && row < matrix.GetLength(1))
            {
                for (int i = row - 1; i <= row + 1; i++)
                {
                    for (int j = col - 1; j <= col + 1; j++)
                    {

                        if ((!(i == row && j == col)) && i >= 0 && j >= 0 && j < matrix.GetLength(0) && i < matrix.GetLength(1))
                        {
                            if (matrix[i, j])
                            {
                                alivecount++;
                            }
                        }

                    }
                }

            }

            return alivecount;

        }
        static void GenerateNewGeneration(bool[,] matrix, bool[,] newmatrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    if (matrix[i, j] && CheckAround(matrix, i, j) == 2 || CheckAround(matrix, i, j) == 3)
                    {
                        newmatrix[i, j] = true;
                    }
                    else
                    {
                        newmatrix[i, j] = false;
                    }

                }

            }
        }
        static void Main(string[] args)
        {
            Console.Write("Zadejte pocet generaci: ");

            uint generations = Convert.ToUInt32(Console.ReadLine());
            const int N = 10;
            bool[,] matrix = new bool[N, N];
            bool[,] newmatrix = new bool[N, N];

            NullArray(matrix);

            GenerateRandomArray(matrix);


            for (int i = 0; i < generations; i++)
            {
                WriteArray(matrix);
                Console.WriteLine("____________________");
                GenerateNewGeneration(matrix, newmatrix);
                matrix = newmatrix;

            }




            Console.ReadLine();

        }
    }
}
