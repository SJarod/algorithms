using System;
using System.Collections.Generic;

using System.IO;
using System.Text;

using System.Linq;

namespace Localization
{
    class LanguageConfig
    {
        List<string> language = new List<string>();
        List<string> keyword = new List<string>();

        void initLanguages(StreamReader file)
        {
            string str = file.ReadLine();
            string[] splitStr = str.Split('|');

            for (int i = 0; i < splitStr.Length; ++i)
            {
                language.Add(splitStr[i]);
            }
        }

        void initKeyWords(StreamReader file)
        {
            string str = file.ReadLine();
            string[] splitStr = str.Split('|');

            for (int i = 0; i < splitStr.Length; ++i)
            {
                keyword.Add(splitStr[i]);
            }
        }

        public List<string> getLanguages()
        {
            return language;
        }

        public List<string> getKeyWords()
        {
            return keyword;
        }

        public void addLocalisation(string key)
        {
            if (!keyword.Contains(key))
                keyword.Add(key);
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

            initLanguages(file);
            initKeyWords(file);

            file.Close();
            file.Dispose();
        }
    }

    class Language
    {
        string language;

        Dictionary<string, string> word = new Dictionary<string, string>();

        //loading a language that exists
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

            int lineCount = 0;
            while (file.ReadLine() != null)
            {
                ++lineCount;
            }
            file.DiscardBufferedData();
            file.BaseStream.Position = 0;

            addWords(file, lineCount);

            file.Close();
            file.Dispose();
        }

        void addWords(StreamReader file, int lineCount)
        {
            for (int i = 0; i < lineCount; ++i)
            {
                string str = file.ReadLine();
                string[] splitStr = str.Split('|');

                word.Add(splitStr[0], splitStr[1]);
            }
        }

        public void addLocalisation(string key, string value)
        {
            word.Add(key, value);
        }

        public void removeLocalisation(string key)
        {
            word.Remove(key);
        }

        public int getKeyWordsCount()
        {
            return word.Count;
        }

        public string getName()
        {
            return language;
        }

        public string getKeyWords(int i)
        {
            return word.ElementAt(i).Key;
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

            Dictionary<int, Language> dictionary = new Dictionary<int, Language>();

            Language english = new Language("English");
            dictionary.Add(0, english);

            Language current = english;

            while (!windowShouldClose)
            {
                Console.WriteLine("Make a choice");
                Console.WriteLine("Current dictionary : " + current.getName());
                Console.WriteLine("");
                Console.WriteLine("1) Select a dictionary");
                Console.WriteLine("2) Create a dictionary");
                Console.WriteLine("3) Display dictionary content");
                Console.WriteLine("4) Get a localisation");
                Console.WriteLine("5) Add a localisation");
                Console.WriteLine("6) Remove a localisation");
                Console.WriteLine("7) Save");
                Console.WriteLine("8) Exit");

                inputs(dictionary, config, ref current, ref windowShouldClose);
            }
        }

        static void inputs(Dictionary<int, Language> dictionary, LanguageConfig config, ref Language current, ref bool windowShouldClose)
        {
            string s = Console.ReadLine();
            switch (s)
            {
                case "1":
                    {
                        caseOne(dictionary, ref current);
                        break;
                    }
                case "2":
                    {
                        caseTwo(dictionary, config);
                        break;
                    }
                case "3":
                    {
                        caseThree(config, ref current);
                        break;
                    }
                case "4":
                    {
                        caseFour(config, ref current);
                        break;
                    }
                case "5":
                    {
                        caseFive(config, ref current);
                        break;
                    }
                case "6":
                    {
                        caseSix(config, ref current);
                        break;
                    }
                case "7":
                    {
                        caseSeven(config, ref current);
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

        static void caseOne(Dictionary<int, Language> dictionary, ref Language current)
        {
            Console.Clear();
            Console.WriteLine("Select a dictionary");
            Console.WriteLine("");

            for (int i = 0; i < dictionary.Count; ++i)
            {
                Console.WriteLine((i + 1).ToString() + ") " + dictionary[i].getName());
            }

            string t = Console.ReadLine();
            bool found = true;

            for (int i = 0; i < t.Length; ++i)
            {
                char[] charArray = t.ToCharArray();
                if (charArray[i] < '0' || charArray[i] > '9')
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                int num = int.Parse(t);

                if (num >= 1 && num <= dictionary.Count)
                    current = dictionary[num - 1];
                else
                    Console.WriteLine("Enter a correct number");
            }
            else
                Console.WriteLine("Enter a correct number");

            Console.WriteLine("");
        }

        static void caseTwo(Dictionary<int, Language> dictionary, LanguageConfig config)
        {
            Console.Clear();
            Console.WriteLine("Create new dictionary");
            Console.WriteLine("");
            Console.WriteLine("enter name :");

            string name = Console.ReadLine();
            List<string> temp = config.getLanguages();
            bool found = false;

            for (int i = 0; i < temp.Count; ++i)
            {
                if (name == temp[i])
                {
                    Language newLanguage = new Language(name);
                    dictionary.Add(dictionary.Count, newLanguage);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                Console.WriteLine("No dictionary " + name + " found");
                Console.WriteLine("");
            }
            else
            {
                Console.WriteLine(name + " created");
                Console.WriteLine("");
            }
        }

        static void caseThree(LanguageConfig config, ref Language current)
        {
            Console.Clear();
            List<string> temp = config.getKeyWords();
            Console.WriteLine(current.getName());
            Console.WriteLine("");

            for (int i = 0; i < temp.Count; ++i)
            {
                Console.WriteLine(temp[i] + "|" + current.getContent(temp[i]));
            }

            Console.WriteLine("");
        }

        static void caseFour(LanguageConfig config, ref Language current)
        {
            Console.Clear();
            Console.WriteLine("Get a localisation");
            Console.WriteLine("");
            Console.WriteLine("enter key :");

            string t = Console.ReadLine();
            List<string> key = config.getKeyWords();
            bool found = false;

            for (int i = 0; i < key.Count; ++i)
            {
                if (t == key[i])
                {
                    Console.WriteLine("found value : " + current.getContent(t));
                    found = true;
                    break;
                }
            }

            if (!found)
                Console.WriteLine("value not found");

            Console.WriteLine("");
        }

        static void caseFive(LanguageConfig config, ref Language current)
        {
            Console.Clear();
            Console.WriteLine("Add a localisation");
            Console.WriteLine("");
            Console.WriteLine("enter key :");

            string newKey = Console.ReadLine();
            bool found = false;

            for (int i = 0; i < current.getKeyWordsCount(); ++i)
            {
                if (newKey == current.getKeyWords(i))
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                config.addLocalisation(newKey);
                Console.WriteLine("key successfuly added");

                Console.WriteLine("");

                Console.WriteLine("enter value");
                string value = Console.ReadLine();
                current.addLocalisation(newKey, value);

                Console.WriteLine("value successfuly added");
            }
            else
                Console.WriteLine("key already exists");

            Console.WriteLine("");
        }

        static void caseSix(LanguageConfig config, ref Language current)
        {
            Console.Clear();
            Console.WriteLine("Remove a localisation");
            Console.WriteLine("");
            Console.WriteLine("enter key to remove :");

            string key = Console.ReadLine();
            List<string> keys = config.getKeyWords();
            bool found = false;

            for (int i = 0; i < keys.Count; ++i)
            {
                if (key == keys[i])
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                current.removeLocalisation(key);
                Console.WriteLine("localisation successfuly removed");
            }
            else
                Console.WriteLine("could not remove key : key " + key + " not found");

            Console.WriteLine("");
        }

        static void caseSeven(LanguageConfig config, ref Language current)
        {
            Console.Clear();

            string path = Path.Combine(Environment.CurrentDirectory, @"..\..\..\dictionary\" + current.getName() + ".txt");
            StreamWriter file = new StreamWriter(path);

            for (int i = 0; i < current.getKeyWordsCount(); ++i)
            {
                string key = current.getKeyWords(i);
                file.Write(key + "|" + current.getContent(key));
                if (i == current.getKeyWordsCount() - 1)
                    break;
                file.Write('\n');
            }

            file.Close();
            file.Dispose();

            Console.WriteLine("localisation saved in file " + path);
            Console.WriteLine("");

            path = Path.Combine(Environment.CurrentDirectory, @"..\..\..\dictionary\config.txt");
            file = new StreamWriter(path);

            List<string> languages = config.getLanguages();
            List<string> keywords = config.getKeyWords();
            for (int i = 0; i < languages.Count; ++i)
            {
                file.Write(languages[i]);
                if (i == languages.Count - 1)
                    break;
                file.Write("|");
            }
            file.Write('\n');
            for (int i = 0; i < keywords.Count; ++i)
            {
                file.Write(keywords[i]);
                if (i == keywords.Count - 1)
                    break;
                file.Write("|");
            }

            file.Close();
            file.Dispose();

            Console.WriteLine("config saved in file " + path);
            Console.WriteLine("");
        }
    }
}
