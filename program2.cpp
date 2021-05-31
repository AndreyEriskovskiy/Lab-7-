#include <iostream>
#include <fstream>
#include <crypt.h>
#include <algorithm>
#include <thread>
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

int main()
{
    string hash;
    string password="123456789";
    ifstream fin("/home/student/hash");
    int k=0;
    while(!fin.eof()) {
        fin>>hash;
        k++;
    }
    cout<<k<<endl;
    k--;
    fin.close();
    fin.open("/home/student/hash");
    string thread1[k];
    thread thread2[k];
    for (int i=0;i<k;i++) {
        fin>>thread1[i];
        thread2[i]=thread(findPass,password,thread1[i]);
    }
    fin.close();
    for(int i=0;i<k;i++) {
        if(thread2[i].joinable())
            thread2[i].join();
        else
            thread2[i].detach();
    }
    return 0;
}
