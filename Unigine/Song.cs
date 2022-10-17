using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Unigine
{
    internal class Song: Content
    {
        public string Band { get; set; }
        public int Year { get; set; }
        public string Album { get; set; }
        public Song(string band, int year, string album, string title, string description) : base(title, description)
        {
            Band = band;
            Year = year;
            Album = album;
        }
        public void PrintFullInfo()
        {
            base.PrintShortInfo();
            Console.WriteLine($"{Band}, {Album}, {Year}");
        }

    }
}
