namespace Unigine
{
    internal class Program
    {
        /*static bool ReadingFile()
        {
            try
            {
                FileStream fs = new FileStream("ReadAndRewrite.txt", FileMode.Open);
                return true;
            }
            catch
            {
                return false;
            }
        }
        */
        static void ReadingFile()
        {
            try
            {
                using (StreamReader sr = new StreamReader("ReadAndRewrite.txt"))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        Console.WriteLine(line);
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Ошибка при чтении файла!");
                Console.WriteLine(e.Message);
            }
        }

        static void WritingStringFile()
        {
            try
            {
                using (StreamWriter sw = new StreamWriter ("ReadAndRewrite.txt",true))
                {
                    sw.WriteLine(Console.ReadLine());
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Критическая ошибка!");
                Console.WriteLine(e.Message);
            }
        }
static void Main(string[] args)
        {
            ReadingFile();
            WritingStringFile();
            WritingStringFile();

        }
    }
}