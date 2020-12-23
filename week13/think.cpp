#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Dictionary
{
    private:
        FILE *fp;
        char TmpChinese[30], TmpEnglish[30]; 
        vector<string> Chinese, English;
        int n;
    public:
        Dictionary(){
            fp = fopen("×Öµä.txt", "r");
            fscanf(fp, "%d", &n);
            cout << n << endl;
        }
        ~Dictionary(){
            fclose(fp);
            n=0;
        }
        void LoadLibrary(){
            for(int i=0; i<n; i++){
                fscanf(fp, "%s", TmpEnglish);
                fscanf(fp, "%s", TmpChinese);
                English.push_back(TmpEnglish);
                Chinese.push_back(TmpChinese);
            }
        }
        void LookupWord(string word)
        {
            for(int i=0; i<n; i++)
            {
                if(English[i] == word)
                {
                    cout << "find the word \"" << word << "\" -- " << Chinese[i] << endl;
                    return;
                }
            }
            cout << "Not Find!" << endl;
        }
        void InsertWord(string EWord, string CWord)
        {
            English.push_back(EWord);
            Chinese.push_back(CWord);
            n++;
        }
        void disp()
        {
            for(int i=0; i<n; i++){
                cout << English[i] << endl;
                cout << Chinese[i] << endl;
            }
        }
};

void Test()
{
    Dictionary d1;
    d1.LoadLibrary();
    d1.LookupWord("TIGER");
    d1.InsertWord("CAT", "Ã¨");
    d1.disp();
}

int main()
{
    Test();
    system("pause");
    return 0;
} 