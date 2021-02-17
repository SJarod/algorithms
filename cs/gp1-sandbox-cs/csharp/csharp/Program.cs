using System;
using System.Collections.Generic;

namespace csharp
{
    struct Vector2
    {
        public double x, y;

        public Vector2(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public double Magnitude()
        {
            return Math.Sqrt(x * x + y * y);
        }

        public override string ToString()
        {
            string str;

            str = "x : " + x.ToString() + ", y : " + y.ToString();

            return str;
        }
    }

    class Vector2MagCompare : IComparer<Vector2>
    {
        public int Compare(Vector2 x, Vector2 y)
        {
            double xmag = x.Magnitude(), ymag = y.Magnitude();

            if (xmag > ymag)
                return 1;
            else if (xmag < ymag)
                return -1;
            else
                return 0;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            {
                // InvertStr
                // ---------
                string a = "Hello World!";
                InvertStr(ref a);
                Console.WriteLine(a);
            }

            {
                // Swap
                // ----
                dynamic a = 10;
                dynamic b = 4;
                Console.WriteLine(a);
                Console.WriteLine(b);
                Swap(ref a, ref b);
                Console.WriteLine(a);
                Console.WriteLine(b);
            }

            {
                // Sort List
                // ---------
                List<Vector2> myList = new List<Vector2>();
                for (int i = 0; i < 10; ++i)
                {
                    Random rand = new Random();
                    myList.Add(new Vector2(rand.NextDouble(), rand.NextDouble()));
                }

                for (int i = 0; i < 10; ++i)
                {
                    Console.WriteLine(myList[i].ToString() + " , mag : " + myList[i].Magnitude());
                }

                myList.Sort(new Vector2MagCompare());
                Console.WriteLine("sort");

                for (int i = 0; i < 10; ++i)
                {
                    Console.WriteLine(myList[i].ToString() + " , mag : " + myList[i].Magnitude());
                }
            }
        }

        static string InvertStr(string str)
        {
            string result = "";

            for (int i = str.Length; i > 0; --i)
            {
                result += str.ToCharArray()[i - 1];
            }

            return result;
        }

        static void InvertStr(ref string str)
        {
            string temp = str;
            str = "";

            for (int i = temp.Length; i > 0; --i)
            {
                str += temp.ToCharArray()[i - 1];
            }
        }

        static void Swap(ref int a, ref int b)
        {
            int c = b;
            b = a;
            a = c;
        }

        static void Swap(ref dynamic a, ref dynamic b)
        {
            dynamic c = b;
            b = a;
            a = c;
        }

        static void printList(List<dynamic> list)
        {
            for (int i = 0; i < list.Count; ++i)
            {
                Console.WriteLine(list[i]);
            }
        }
    }
}