#include <iostream>
#include <fstream>
#include <crypt.h>
#include <algorithm>
using namespace std;
void findPass(string pass, const string& hash)
{
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            break;
        }
    } while (next_permutation(pass.begin(), pass.end()));
    delete pCryptData;
}

int main() {
    string hash;
    string password="123456789";
    ifstream fin("/home/student/hash");
    for(int i=0;i<8;i++) {
        fin>>hash;
        findPass(password,hash);
    }
    fin.close();
    return 0;
}
