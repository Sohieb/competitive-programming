#include <bits/stdc++.h>

using namespace std;

long long rnd(){
    long long res=1;
    res*=(rand()%1235);
    res*=(rand()%334);
    res*=(rand()%7931);
    return res;
}

int main()
{
    system("g++ -std=c++11 me.cpp -o wa");
    system("g++ -std=c++11 BF.cpp -o ac");
    int tc = 1;
    srand(time(0));
    while(1)
    {
        ofstream cout ("in.txt");
        
        /*
        Here generate the test case
        Ex:
        
        cout << 1 << endl;
        int n = 2 + rnd() % 5;
        int m = 1 + rnd() % 30;
        cout << n << " " << m << endl;
        for (int i = 0; i < n; ++i)
            cout << rnd() % 33 << " ";
        cout << endl;
        */

        cout.close();
        system("./wa<in.txt>wa.txt");
        system("./ac<in.txt>ac.txt");
        cerr << "[-] Test Number: " << tc++ << "\n";
        ifstream waf("wa.txt");
        ifstream acf("ac.txt");
        string wa,ac;
        getline(waf,wa,(char)EOF);
        getline(acf,ac,(char)EOF);
            
        cerr << wa << ac <<"\n";
        
        if(wa!=ac){
            cerr<<"Afshtha\n";
            break;
        }
    }
    return 0;
}
