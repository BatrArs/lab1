#include  "modAlphakey.h"

using namespace std;

std::wstring modAlphakey::encrypt(std::wstring& open_text) // шифрование
{
    wstring tabl = open_text;
    int dl, nstrok, index, x;
    while (tabl.size() % key1 != 0){
        tabl += L"*";
    }
    open_text = tabl;
    dl = tabl.size(); // введенный текст
    nstrok = (dl - 1) / key1 + 1; // количество столбцов
    x = 0;
    wstring encrypted();
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < dl) {
                tabl[x] = open_text[index-1];
                x++;
            }
        }
    }
    return tabl;
}

std::wstring modAlphakey::decrypt(std::wstring& cipher_text) // расшифрование
{
    wstring tabl = cipher_text;
    int dl, nstrok, index, x;
    dl = cipher_text.length();
    nstrok = (dl - 1) / key1 + 1; // количество столбцов
    x = 0;
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < dl) {
                tabl[index-1] = cipher_text[x];
                x++;
            }
        }
    }
    return tabl;
}
