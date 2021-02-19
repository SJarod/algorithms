using System;

namespace AchievementManager
{
    class Enemy
    {
        string m_name;
        bool m_isAlive;

        public Enemy()
        {
            m_name = "enemy";
            m_isAlive = true;
        }

        public Enemy(string name)
        {
            m_name = name;
            m_isAlive = true;
        }

        public delegate void EventHandler();
        public event EventHandler OnEnemyKilled;
        public void Kill() //raise
        {

        }
    }

    class AchievementMgr
    {
        int m_killedEnemies = 0;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Enemy[] enemies = new Enemy[10];
            for (int i = 0; i < enemies.Length; ++i)
                enemies[i] = new Enemy("badguy" + i.ToString());
        }
    }
}
