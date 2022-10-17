using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Unigine
{
    internal class Film : Content
    {
        public string Director { get; set; }
        public List<string> Actors { get; set; }

        public Film(string director, string title, string description) : base(title, description)
        {
            Director = director;
            Actors = new List<string>() { "asdfasf", "adfaf" };

        }

        public void PrintFullInfo()
        {
            PrintShortInfo();
            Console.WriteLine($"Director: {Director}");
            Console.WriteLine("Actors:");
            foreach (string actor in Actors)
            {
                Console.WriteLine(actor);
            }
        }


    }
}
