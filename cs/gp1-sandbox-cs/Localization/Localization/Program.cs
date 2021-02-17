using System;
using System.Collections.Generic;

using System.IO;
using System.Text;

namespace Localization
{
    class LanguageConfig
    {
        List<string> language = new List<string>();
        List<string> keyword = new List<string>();

        void getLanguages(StreamReader file)
        {
            string str = file.ReadLine();
            string[] splitStr = str.Split('|');

            for (int i = 0; i < splitStr.Length; ++i)
            {
                language.Add(splitStr[i]);
            }
        }

        void getKeyWords(StreamReader file)
        {
            string str = file.ReadLine();
            string[] splitStr = str.Split('|');

            for (int i = 0; i < splitStr.Length; ++i)
            {
                keyword.Add(splitStr[i]);
            }
        }

        public void initDictionary()
        {
            string path = Path.Combine(Environment.CurrentDirectory, @"..\..\..\dictionary\config.txt");

            if (!File.Exists(path))
            {
                Console.WriteLine("could not open config file " + path);
                return;
            }

            StreamReader file = new StreamReader(path);

            getLanguages(file);
            getKeyWords(file);

            file.Close();
            file.Dispose();
        }
    }

    class Language
    {
        string language;

        Dictionary<string, string> word = new Dictionary<string, string>();

        public Language(string l)
        {
            language = l;

            string path = Path.Combine(Environment.CurrentDirectory, @"..\..\..\dictionary\" + language + ".txt");

            if (!File.Exists(path))
            {
                Console.WriteLine("could not open config file " + path);
                return;
            }

            StreamReader file = new StreamReader(path);

            getWords(file);

            file.Close();
            file.Dispose();
        }

        void getWords(StreamReader file)
        {
            for (int i = 0; i < 3; ++i)
            {
                string str = file.ReadLine();
                string[] splitStr = str.Split('|');

                word.Add(splitStr[0], splitStr[1]);
            }
        }

        public string getName()
        {
            return language;
        }

        public string getContent(string key)
        {
            if (word.ContainsKey(key))
                return word[key];

            return "no keyword " + key + " found in " + language;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            bool windowShouldClose = false;

            LanguageConfig config = new LanguageConfig();
            config.initDictionary();

            Language english = new Language("english");

            while (!windowShouldClose)
            {
                Console.WriteLine("Make a choice");
                Console.WriteLine("Current dictionary : " + english.getName());
                Console.WriteLine("");
                Console.WriteLine("1) Select a dictionary");
                Console.WriteLine("2) Create a dictionary");
                Console.WriteLine("3) Display dictionary content");
                Console.WriteLine("4) Get a localisation");
                Console.WriteLine("5) Add a localisation");
                Console.WriteLine("6) Remove a localisation");
                Console.WriteLine("7) Save");
                Console.WriteLine("8) Exit");

                string s = Console.ReadLine();
                switch (s)
                {
                    case "1":
                        {
                            Console.Clear();
                            break;
                        }
                    case "2":
                        {
                            Console.Clear();
                            break;
                        }
                    case "3":
                        {
                            Console.Clear();
                            break;
                        }
                    case "4":
                        {
                            Console.Clear();
                            break;
                        }
                    case "5":
                        {
                            Console.Clear();
                            break;
                        }
                    case "6":
                        {
                            Console.Clear();
                            break;
                        }
                    case "7":
                        {
                            Console.Clear();
                            break;
                        }
                    case "8":
                        {
                            windowShouldClose = true;
                            break;
                        }
                    default:
                        {
                            Console.Clear();
                            Console.WriteLine("unavailable option");
                            Console.WriteLine("");
                            break;
                        }
                }
            }
        }
    }
}
