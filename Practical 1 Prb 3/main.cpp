#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    sentence = sentence + " ";

    string word = "";
    string longestWord = "";

    for(int i=0; i<sentence.length(); i++)
    {
        if(sentence[i]==' ')
        {
            if(word.length()>longestWord.length())
            {
                longestWord = word;
            }

            word = "";
        }
        else
        {
            word = word + sentence[i];
        }
    }

    cout << "\nLongest Word: " << longestWord;
    cout << "\nNumber of Letters: " << longestWord.length();

    return 0;
}
