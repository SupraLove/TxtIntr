
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
using namespace std;

class Opts{
private:
    bool Add = false;
    bool Sub = false;
    const int maxPar = 5;
    const int minPar = 2;
    int Params = 0;
    double result{};
    string Operation;
    vector<double> digits;

public:
    Opts(int argc, char **argv);
    void count();
    void usage(const char* progName);
};

void Opts::usage(const char* progName)
{
 std::cout<<"Usage: "<<progName<<" -o summa^raznost <double> param1 param2 param3 [param4] [param5]\n";
 exit(1);
}

Opts::Opts(int argc, char **argv)
{
    int opt;
    opt = getopt(argc, argv, "o:");
    switch (opt) {
        case 'o': // Операция
            Operation = optarg;
            if (Operation == "summa") {
                Add = true;}
            else if (Operation == "raznost"){
                Sub = true;}
            else {
                // если ошибка - сообщить и завершить
                usage(argv[0]);
            }
            break;
        case '?': // неверный параметр
        case ':': // нет значения у параметра
            usage(argv[0]); // сообщить и завершить
    }
    if ((Add == true) || (Sub == true)){
        for(; optind < argc; optind++){
            if (Params < maxPar){
                double d = strtod(argv[optind],nullptr);
                digits.push_back(d);
                Params +=1;
            } 
        }
    }
    if (Params<minPar){
        cout <<"Недостаточно операндов" <<endl;
        usage(argv[0]);}
}

void Opts::count(){
    result = digits[0];
    if (Add){
        for (int i = 1; i < digits.size(); i++){
            result += digits[i];
        }
    }
    else if(Sub){
        for (int i = 1; i < digits.size(); i++){
           result -= digits[i];
        }
    }
    cout<<result<<endl;
}

int main(int argc, char **argv)
{
    Opts op(argc, argv);
    op.count();
    return 0;
} 
