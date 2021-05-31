#include <cstdio>
#include <iostream>

long convertToLong(std::string x){
    if(x[0] == '0' && x.size() > 1){return -1;}
    if(x.size() > 7){return -1;}

    long output(0);
    for(size_t k = 0; k < x.size(); k++){output = 10 * output + (x[k] - '0');}
    if(output > 1000000){return -1;}
    return output;
}

int main(){

    const int N = 7;

    std::string input; getline(std::cin, input);

    int L = input.size();
    long maxTotal(-1); 

    for(int i = 1; i <= N && i <= L - 2; i++){
        for(int j = 1; j <= N && j <= L - 1 - i; j++){
            long a = convertToLong(input.substr(0, i));
            long b = convertToLong(input.substr(i, j));
            long c = convertToLong(input.substr(i + j));
            //std::cout << input.substr(0, i) << "\t" << input.substr(i, j) << "\t" << input.substr(i + j) << std::endl;

            long total(a + b + c);
            if(a >= 0 && b >= 0 && c >= 0 && total > maxTotal){
                puts("---");
                maxTotal = total;
            }
        }
    }

    std::cout << maxTotal << std::endl;

    return 0;
}
