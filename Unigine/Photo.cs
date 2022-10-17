using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Unigine
{
    internal class Photo:Content
    {
        public int Height { get; set; }
        public int Width { get; set; }
        public  Photo(int height, int width, string title, string description) : base(title, description)
        {
            Height = height;
            Width = width;
        }
        public void PrintFullInfo()
        {
            base.PrintShortInfo();
            Console.WriteLine($"{Height} x {Width}");
        }

    }
}
