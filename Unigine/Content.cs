using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Unigine
{
    internal class Content
    {
        public string Title { get; set; }
        public string Description { get; set; }

        public Content(string title,string description)
        {
            Title= title;
            Description= description;
        }

        public virtual void PrintShortInfo()
        {
            Console.WriteLine(Title);
            Console.WriteLine(Description);
        }

    }
}
